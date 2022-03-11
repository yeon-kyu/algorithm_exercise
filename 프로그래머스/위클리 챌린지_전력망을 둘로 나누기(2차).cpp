#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> node[101];
bool visited[101];

void refresh() {
    for(int i=0;i<100;i++) {
        visited[i] = false;
    }
}

int getFamilyCnt(int start) {
    int cnt = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;
        
        int size = node[cur].size();
        for(int i = 0;i<size;i++) {
            if(visited[node[cur][i]] == false) {
                q.push(node[cur][i]);
                visited[node[cur][i]] = true;
            }
        }
    }
    return cnt;
}

int getAbs(int a) {
    if(a < 0) {
        return -a;
    } else {
        return a;
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for(int i=0; i < n - 1; i++) {
        int a = wires[i][0];
        int b = wires[i][1];
        node[a].push_back(b);
        node[b].push_back(a);
    }
    
    for(int i=0;i<n-1;i++) {
        int a = wires[i][0];
        int b = wires[i][1];

        node[a].erase(find(node[a].begin(), node[a].end(), b));
        node[b].erase(find(node[b].begin(), node[b].end(), a));
        
        refresh();
        int aCnt = getFamilyCnt(a);
        int bCnt = getFamilyCnt(b);
        
        answer = min(answer, getAbs(aCnt-bCnt));
        
        node[a].push_back(b);
        node[b].push_back(a);
    }

    return answer;
}