#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Key[61][61];
int Lock[61][61];

int key_size;
int lock_size;

struct Hole{
    int y;
    int x;
};
vector<Hole> hole;

void move_lock(int y, int x){
    int temp[21][21];
    for(int i=0;i<lock_size;i++){
        for(int j=0;j<lock_size;j++){
            temp[i][j] = Lock[i+20][j+20];
            Lock[i+20][j+20] = 0;
        }
    }
    
    for(int i=0;i<lock_size;i++){
        for(int j=0;j<lock_size;j++){
            Lock[i+y+20][j+x+20] = temp[i][j];
        }
    }
}

void re_move_lock(int y, int x){
    int temp[21][21];
    for(int i=0;i<lock_size;i++){
        for(int j=0;j<lock_size;j++){
            temp[i][j] = Lock[i+20-y][j+20-x];
            Lock[i+20-y][j+20-x] = 0;
        }
    }
    
    for(int i=0;i<lock_size;i++){
        for(int j=0;j<lock_size;j++){
            Lock[i+20][j+20] = temp[i][j];
        }
    }
}

void move_key(int y, int x){
    int temp[21][21];
    for(int i=0;i<key_size;i++){
        for(int j=0;j<key_size;j++){
            temp[i][j] = Key[i+20][j+20];
            Key[i+20][j+20] = 0;
        }
    }
    
    for(int i=0;i<key_size;i++){
        for(int j=0;j<key_size;j++){
            Key[i+y+20][j+x+20] = temp[i][j];       
        }
    }
}

void re_move_key(int y, int x){
    int temp[61][61];
    for(int i=0;i<key_size;i++){
        for(int j=0;j<key_size;j++){
            temp[i][j] = Key[i+20-y][j+20-x];
            Key[i+20-y][j+20-x] = 0;
        }
    }
    
    for(int i=0;i<key_size;i++){
        for(int j=0;j<key_size;j++){
            Key[i+20][j+20] = temp[i][j];       
        }
    }
}

void lotate_key(){ //[20][20] 기준으로 회전.
    int temp[61][61];
    for(int i=0;i<=60;i++){
        for(int j=0;j<=60;j++){
            temp[i][j] = 0;
        }
    }
    for(int i=0;i<=40;i++){
        for(int j=0;j<=40;j++){
            temp[j][40-i] = Key[i][j];
        }
    }
    for(int i=0;i<=60;i++){
        for(int j=0;j<=60;j++){
            Key[i][j] = temp[i][j];
        }
    }
}

bool isTrueKey(int y, int x, bool flag){
    int temp[61][61];
    for(int i=0;i<=60;i++){
        for(int j=0;j<=60;j++){
            temp[i][j] = Lock[i][j] + Key[i][j];
        }
    }
    
    for(int i=0;i<lock_size;i++){
        for(int j=0;j<lock_size;j++){
            int cur = temp[20+i+y][20+j+x];
            if(cur != 1){
                return false;
            }
        }
    }
    
    return true;
}

bool check_possible(int y, int x){
    int h_size = hole.size();
    
    if(h_size == 0){
        return true;
    }
    
    for(int i=0;i<h_size;i++){
        //hole[i] : 자물쇠의 회전 중심
        
        move_lock(-1 * hole[i].y, -1 * hole[i].x);
        move_key(-1 * y, -1 * x);
        
        //4번 회전
        for(int k=0;k<4;k++){
            
            bool flag = false;
            if(y==0 && x==0 && hole[i].y == 2 && hole[i].x == 2){
                flag = true;
            }
            
            lotate_key();
            bool isKey = isTrueKey(-1*hole[i].y, -1*hole[i].x, flag);
            if(isKey == true){
                return true;
            }
        }
        
        //원복
        re_move_lock(hole[i].y, hole[i].x);
        re_move_key(y, x);   
    }
    return false;
}

bool solve(vector<vector<int>>& key,vector<vector<int>>& lock){
    for(int i=0;i<key_size;i++){
        for(int j=0;j<key_size;j++){
            if(key[i][j] == 1){
                if(check_possible(i,j)){
                    return true;
                }
            }
        }
    }

    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    key_size = key.size();
    lock_size = lock.size();
    
    //init
    for(int i=0;i<=60;i++){
        for(int j=0;j<=60;j++){
            Key[i][j] = 0;
            Lock[i][j] = 0;
        }
    }
    
    for(int i=0;i<key_size;i++){
        for(int j=0;j<key_size;j++){
            Key[i+20][j+20] = key[i][j];
        }
    }
    for(int i=0;i<lock_size;i++){
        for(int j=0;j<lock_size;j++){
            Lock[i+20][j+20] = lock[i][j];
            if(lock[i][j] == 0){
                hole.push_back({i,j});
            }
        }
    }
    bool isKey = solve(key, lock);
    
    answer = isKey;
    return answer;
}