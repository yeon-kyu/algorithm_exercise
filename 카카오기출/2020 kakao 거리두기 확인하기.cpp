#include <string>
#include <vector>

using namespace std;
int check_right(vector<string> place, int a, int b){
    if(b == 4){ //오른쪽 없음
        return 1;
    }
    else if(place[a][b+1] == 'X'){ //오른쪽이 벽임
        return 1;
    }
    else {
        if(place[a][b+1] == 'P'){ //오른쪽 사람있음
            return 0;
        }
        else{ // 그냥 테이블O 인 경우 -> 오른쪽 '위', '더 오른쪽', '아래' 확인해야함
            if(a == 0){ 
            }
            else if(place[a-1][b+1] == 'P'){ //오른쪽 위 사람임
                return 0;
            }
            
            if(b == 3){
            }
            else if(place[a][b+2] == 'P'){ //더 오른쪽 사람임
                return 0;
            }
            
            if(a == 4){
            }
            else if(place[a+1][b+1] == 'P'){ //오른족 아래 사람임
                return 0;
            }
        }
    }
    return 1;
}

int check_left(vector<string> place, int a, int b){
    if(b == 0){ //왼쪽 없음
        return 1;
    }
    else if(place[a][b-1] == 'X'){ //왼쪽이 벽임
        return 1;
    }
    else {
        if(place[a][b-1] == 'P'){ //왼쪽 사람있음
            return 0;
        }
        else{ // 그냥 테이블O 인 경우 -> 왼쪽 '위', '더 왼쪽', '아래' 확인해야함
            if(a == 0){ 
            }
            else if(place[a-1][b-1] == 'P'){ //왼쪽 위 사람임
                return 0;
            }
            
            if(b == 1){
            }
            else if(place[a][b-2] == 'P'){ //더 왼쪽 사람임
                return 0;
            }
            
            if(a == 4){
            }
            else if(place[a+1][b-1] == 'P'){ //왼쪽 아래 사람임
                return 0;
            }
        }
    }
    return 1;
}


int check_below(vector<string> place, int a, int b){
    if(a == 4){ //아래가 없음
        return 1;
    }
    else if(place[a+1][b] == 'X'){ //아래가 벽임
        return 1;
    }
    else {
        if(place[a+1][b] == 'P'){ //아래가 사람임
            return 0;
        }
        else { //그냥 테이블 O인경우 -> '아래의 왼쪽', '더 아래', '아래의 오른쪽' 확인해야함
            if(b == 0){
            }
            else if(place[a+1][b-1] == 'P'){ //아래의 왼쪽 확인
                return 0;
            }
            
            if(a == 3){
            }
            else if(place[a+2][b] == 'P'){ //더 아래 확인
                return 0;
            }
            
            if(b == 4){
            }
            else if(place[a+1][b+1] == 'P'){ //아래의 오른족
                return 0;
            }
        }
    }
    return 1;
}

int get_review(vector<string> place){
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(place[i][j] == 'P'){
                int a = check_right(place, i, j);
                if(a == 0){
                    return 0;
                }
                int b = check_below(place, i, j);
                if(b == 0){
                    return 0;
                }
                
                int c = check_left(place, i, j);
                if(c == 0){
                    return 0;
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(vector<string> place : places){
        int ans = get_review(place);
        answer.push_back(ans);
    }
    
    return answer;
}