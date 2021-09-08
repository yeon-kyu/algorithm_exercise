#include <string>
#include <vector>
#include <iostream>

using namespace std;

int mat[12][12];
int N;
int ans = 0;

bool isPossible(int row, int col){
    for(int i=0;i<row;i++){ //같은 수직축 위에 퀸 없는지 확인
        if(mat[i][col] == 1){
            return false;
        }
    }
    for(int i=1;i<=row;i++){ //대각선 왼쪽 위 확인
        if(row-i >= 0 && col-i >= 0){
            if(mat[row-i][col-i] == 1){
                return false;
            }
        }
        if(row-i >= 0 && col+i < N){ //대각선으론쪽 위 확인
            if(mat[row-i][col+i] == 1){
                return false;
            }
        }
    }
    return true;
}

void back_tracking(int row){
    if(row == N){
        ans++;
    }
    else{
        for(int i=0;i<N;i++){
            //mat[row][i] 에 대해서 놔도 되는지 확인
            if(isPossible(row, i)){
                mat[row][i] = 1;
                back_tracking(row+1);
                mat[row][i] = 0;
            }
        }
    }
}

int solution(int n) {
    int answer = 0;
    
    //init
    N = n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j] = 0;
        }
    }
    
    //한 행당 하나씩 놓는다.
    for(int i=0;i<n;i++){ //0, 1, 2,..
        mat[0][i] = 1; 
        back_tracking(1);
        mat[0][i] = 0;
    }
    answer = ans;
    
    return answer;
}