#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dir = 0;// 0:아래, 1:오른쪽, 2:왼쪽위

int mat[1001][1001];
int N;

bool canMoveNext(int y, int x) {
    if(dir == 0) {
        if(y+1 >= N || mat[y+1][x] != 0) {
            return false;
        }
        else {
            return true;
        }
    }
    else if (dir == 1) {
        if(x+1 >= N || mat[y][x+1] != 0) {
            return false;
        }
        else {
            return true;
        }
    }
    else if(dir == 2) {
        if(mat[y-1][x-1] != 0) {
            return false;
        } else {
            return true;
        }
    }
    else {
        cout<<"canmoveNext error : "<<y<<' '<<x<<endl;
    }
}

vector<int> movedPosition(int y, int x) {
    vector<int> v(2);
    if (dir == 0) {
        v[0] = y+1;
        v[1] = x;
    }
    else if(dir == 1) {
        v[0] = y;
        v[1] = x+1;
    }
    else if(dir == 2){
        v[0] = y-1;
        v[1] = x-1;
    }
    return v;
}

vector<int> solution(int n) {
    N = n;
    vector<int> answer;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j] = 0;
        }
    }
    int counter = 1;
    
    int posY = 0;
    int posX = 0;
    
    while (true) {
        
        mat[posY][posX] = counter;
        counter++;
        
        if (canMoveNext(posY, posX)==true) {
            vector<int> v = movedPosition(posY, posX);
            posY = v[0];
            posX = v[1];
        } else {
            dir = (dir+1)%3;
            if(canMoveNext(posY, posX) == true) {
                vector<int> v = movedPosition(posY, posX);
                posY = v[0];
                posX = v[1];
            } else {
                break;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            answer.push_back(mat[i][j]);
        }
    }
    
    return answer;
}