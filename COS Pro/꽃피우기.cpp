// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mat[101][101];
int row,col;

void refresh(){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            mat[i][j] = 0;
        }
    }
}

int solution(vector<vector<int>> garden) {
    // 여기에 코드를 작성해주세요.
    int answer = 0;
    
    row = garden.size();
    col = garden[0].size();

    int cnt = 0;
    while(true){
        bool doneFlag = true;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(garden[i][j] == 0){
                    doneFlag = false;
                    break;
                }
            }
            if(doneFlag == false){
                break;
            }
        }
        
        if(doneFlag == true){
            break;
        }
        
        refresh();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(garden[i][j] == 1){
                    
                    if(i>0){
                        mat[i-1][j] = 1;
                    }
                    if(i<row-1){
                        mat[i+1][j] = 1;
                    }
                    if(j>0){
                        mat[i][j-1] = 1;
                    }
                    if(j<col-1){
                        mat[i][j+1] = 1;
                    }
                     
                }
            }
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j] == 1){
                    garden[i][j] = 1;
                }
            }
        }
        
        cnt++;
        
    }
    answer  = cnt;
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    vector<vector<int>> garden1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int ret1 = solution(garden1);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;
    
    vector<vector<int>> garden2 = {{1, 1}, {1, 1}};
    int ret2 = solution(garden2);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}