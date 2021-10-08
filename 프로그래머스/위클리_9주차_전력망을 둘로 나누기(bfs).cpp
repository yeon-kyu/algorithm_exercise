#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<int> node[101];
bool visited[101];

void refresh(){
    for(int i=0;i<101;i++){
        visited[i] = false;
    }
}

int do_bfs(int pos, int exc){
    queue<int> q;
    q.push(pos);
    int cnt = 1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        int size = node[cur].size();
        for(int i=0;i<size;i++){
            if(node[cur][i] == exc){
                continue;
            }
            if(visited[node[cur][i]] == false){
                q.push(node[cur][i]);
                cnt++;
                visited[node[cur][i]] = true;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 98;
    
    for(vector<int> wire : wires){
        node[wire[0]].push_back(wire[1]);
        node[wire[1]].push_back(wire[0]);
    }
    
    for(vector<int> wire: wires){
        refresh();
        int left_cnt = do_bfs(wire[0], wire[1]);
        int right_cnt = do_bfs(wire[1], wire[0]);
        
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