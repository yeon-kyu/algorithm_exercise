#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> v[20001];

bool visited[20001];
int dist[20001];

vector<int> Q;

bool notInQueue(int tar){
    
    for(auto it = Q.begin(); it!= Q.end();it++){
        if(*it == tar){
            return false;
        }
    }
    return true;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i=0;i<=n;i++)
        dist[i] = 99999;
    
    int s = edge.size();
    for(int i=0;i<s;i++){
        int a = edge[i][0];
        int b= edge[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    Q.push_back(1);
    visited[1] = true;
    dist[1] = 0;
    
    while(!Q.empty()){
        int temp = Q[0]; //현재 보는 노드
       
        int adjSize = v[temp].size();
        for(int i=0;i<adjSize;i++){
            if(visited[v[temp][i]]==false && notInQueue(v[temp][i])){//확정나지 않았거나 Q에 v[temp][i]가 없으면
                Q.push_back(v[temp][i]); //큐에 넣는다.
                dist[v[temp][i]] = min(dist[temp]+1,dist[v[temp][i]]);
            }
        }
        
        //cout<<temp<<"의 dist : "<<dist[temp]<<endl;
        
        //이제 temp의 거리를 확정해야함.
        visited[temp] = true;
        Q.erase(Q.begin());
    }
    
    int maxi = 0;
    for(int i=1;i<=n;i++){
        if(dist[i]>maxi)
            maxi = dist[i];
    }
    
    for(int i=1;i<=n;i++){
        if(dist[i] == maxi)
            answer++;
    }
    
    
    return answer;
}