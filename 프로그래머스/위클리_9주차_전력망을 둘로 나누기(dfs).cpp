#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> node[101];
bool visited[101];

void refresh(){
    for(int i=0;i<101;i++){
        visited[i] = false;
    }
}

int do_dfs(int pos, int exc){
    visited[pos] = true;
    if(pos == exc){
        return 0;
    }
    
    int ans = 1;
    
    int size = node[pos].size();
    for(int i=0;i<size;i++){
        if(visited[node[pos][i]] == false){
            ans += do_dfs(node[pos][i], exc);    
        }
        
    }
    return ans;
}


int solution(int n, vector<vector<int>> wires) {
    int answer = 98;
    
    for(vector<int> wire : wires){
        node[wire[0]].push_back(wire[1]);
        node[wire[1]].push_back(wire[0]);
    }
    
    for(vector<int> wire: wires){
        refresh();
        int left_cnt = do_dfs(wire[0], wire[1]);
        int right_cnt = do_dfs(wire[1], wire[0]);
        
        int diff = right_cnt-left_cnt;
        if(diff<0){
            diff = -1 * diff;
        }
        if(diff==0){
            answer = 0;
            break;
        }
        
        answer = min(answer, diff);
    }
    
    return answer;
}