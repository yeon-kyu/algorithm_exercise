#include <string>
#include <vector>

using namespace std;

vector<vector<int>> mat;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    int startRow = left/n;
    int endRow = right/n;
    
    for(int i=0;i<startRow;i++){
        vector<int> temp;
        mat.push_back(temp);
    }
    for(int i=startRow;i<=endRow;i++){
        vector<int> temp(n);
        mat.push_back(temp);
    }
    
    for(int i=startRow;i<=endRow;i++){
        // 반복되는 i+1 이 i+1 개
        int repeat = i+1;
        for(int j=0;j<repeat;j++){
            mat[i][j] = repeat;
        }
        for(int j=repeat; j<n;j++){
            mat[i][j] = j+1;
        }
    }
    
    for(long long i=left; i<=right; i++){
        int row = i/n;
        int col = i%n;
        answer.push_back(mat[row][col]);
    }
    
    return answer;
}