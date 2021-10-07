#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct posInfo{
    int y;
    int x;
};

int b_size;
vector<vector<int>> b;
vector<vector<int>> t;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int ans = 0;

void init(vector<vector<int>> &game_board, vector<vector<int>> &table){
    for(int i=0;i<b_size;i++){
        vector<int> v;
        for(int j=0;j<b_size;j++){
            v.push_back(game_board[i][j]);
        }
        b.push_back(v);
    }
    
    for(int i=0;i<b_size;i++){
        vector<int> v;
        for(int j=0;j<b_size;j++){
            v.push_back(table[i][j]);
        }
        t.push_back(v);
    }
}

vector<posInfo> find_empty_board(int y, int x){ //bfs
    
    vector<posInfo> v;
    v.push_back({y,x});
    b[y][x] = 1;
    
    queue<posInfo> q;
    q.push({y,x});
    
    while(!q.empty()){
        posInfo pos = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int nextY = pos.y + dy[i];
            int nextX = pos.x + dx[i];
            if(nextY < b_size && nextY >= 0 && nextX < b_size && nextX >= 0){
                //cout<<nextY<<' '<<nextX<<endl;
                if(b[nextY][nextX] == 0){
                    q.push({nextY, nextX});
                    v.push_back({nextY, nextX});
                    b[nextY][nextX] = 1;    
                }
                
            }
        }
    }
    
    return v;
}

vector<posInfo> find_exist_table(int y, int x){
    
    vector<posInfo> v;
    v.push_back({y,x});
    t[y][x] = 0;
    
    queue<posInfo> q;
    q.push({y,x});
    
    while(!q.empty()){
        posInfo pos = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int nextY = pos.y + dy[i];
            int nextX = pos.x + dx[i];
            if(nextY<b_size && nextY>=0 && nextX<b_size&& nextX>=0){
                if(t[nextY][nextX] == 1){
                    q.push({nextY, nextX});
                    v.push_back({nextY, nextX});
                    t[nextY][nextX] = 0;    
                }
                
            }
        }
    }
    
    return v;
}

void fit_to_zero(vector<posInfo> &v){ //모양을 왼쪽 위로 피팅시키기
    
    int min_y = v[0].y;
    int min_x = v[0].x;
    
    for(auto it = v.begin(); it!=v.end(); it++){
        min_y = min(min_y, it->y);    
        min_x = min(min_x, it->x);
    }
    
    for(auto it = v.begin(); it!=v.end(); it++){
        it->y -= min_y;
        it->x -= min_x;
    }
}

bool compare(posInfo a, posInfo b){
    if(a.y > b.y){
        return true;
    }
    else if(a.y < b.y){
        return false;
    }
    else{ //a.y == b.y
        return a.x < b.x;
    }
}

void rotate(vector<posInfo> &v){ 
    int size = v.size();
    for(int i=0;i<size;i++){ //rotate
        int t = v[i].y;
        v[i].y = -v[i].x;
        v[i].x = t;
    }
}

bool compare_b_t(vector<posInfo> b_vector, vector<posInfo> t_vector){
    
    if(b_vector.size() != t_vector.size()){
        return false;
    }
    
    fit_to_zero(b_vector);
    fit_to_zero(t_vector);
    
    sort(b_vector.begin(), b_vector.end(), compare);
    
    //원형으로 체크
    sort(t_vector.begin(), t_vector.end(), compare);
    bool flag = true;
    
    for(int i=0;i<b_vector.size();i++){
        if(b_vector[i].y != t_vector[i].y || b_vector[i].x != t_vector[i].x){
            flag = false;
            break;
        }
    }
    
    if(flag == true){
        return true;
    }
    
    for(int i=0;i<3;i++){
        //90도 돌려서 체크
        rotate(t_vector);
        fit_to_zero(t_vector);
        sort(t_vector.begin(), t_vector.end(), compare);
        flag = true;

        for(int i=0;i<b_vector.size();i++){
            if(b_vector[i].y != t_vector[i].y || b_vector[i].x != t_vector[i].x){
                flag = false;
                break;
            }
        }
        if(flag == true){
            return true;
        }
    }
    
    return false;
}

void undo_t_vector(vector<posInfo> v){
    int size = v.size();
    for(int i=0;i<size;i++){
        t[v[i].y][v[i].x] = 1;
    }
}


int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    //bfs로 game_board에서 빈공간의 블럭자리가 몇개짜리 퍼즐인지 탐색
    //그 퍼즐 수만큼 table에 존재하는지 확인
    //있으면 모양까지 일치 가능한지 확인 <- 이게 어려움. 회전도 생각
    
    b_size = game_board.size();
    init(game_board, table);
    
    vector<vector<posInfo>> board_list;
    vector<vector<posInfo>> table_list;
    
    for(int i=0;i<b_size;i++){
        for(int j=0;j<b_size;j++){
            if(b[i][j] == 0){
                vector<posInfo> b_vector = find_empty_board(i, j);
                board_list.push_back(b_vector);
            }
        }
    }
    
    for(int i=0;i<b_size;i++){
        for(int j=0;j<b_size;j++){
            if(t[i][j] == 1){
                vector<posInfo> t_vector = find_exist_table(i, j);
                table_list.push_back(t_vector);
            }
        }
    }
    
    for(vector<posInfo> board : board_list){
        
        int size = table_list.size();
        for(int i=0;i<size;i++){
            if(compare_b_t(board, table_list[i])){
                ans += board.size();
                table_list.erase(table_list.begin()+i); // TODO check syntax
                break;
            }

        }
    }
    
    answer = ans;
    return answer;
}