#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node{
    int dest;
    int cost;
};

vector<Node> v[201];
int dist[3][201];
bool visited[201];

int inf = 987654321;
int flag;
    
bool compare(int a, int b){
    if(dist[flag][a] < dist[flag][b]){
        return true;
    }
    else{
        return false;
    }
}
    
void reset(){
    for(int i=0;i<201;i++){
        dist[flag][i] = inf;
        visited[i] = false;
    }    
}

void do_dijkstra(int start){
    reset();
    
    vector<int> q;
    
    q.push_back(start);
    dist[flag][start] = 0;
    while(!q.empty()){
        int temp = q.front(); //현재 확정할 노드
        q.erase(q.begin());
        
        for(Node ad_node : v[temp]){//확정할 노드 근처 노드들에서
            if(visited[ad_node.dest] == false){ //확정나지 않은 것 중에.
                
                if(find(q.begin(), q.end(), ad_node.dest) == q.end()){ //큐에 없으면
                    q.push_back(ad_node.dest);
                    dist[flag][ad_node.dest] = dist[flag][temp] + ad_node.cost;
                }
                else{ //큐에 있으면
                    dist[flag][ad_node.dest] = min(dist[flag][temp]+ad_node.cost, dist[flag][ad_node.dest]);
                }
            }
        }   
        visited[temp] = true;
        sort(q.begin(),q.end(),compare);
    }
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    //init
    for(vector<int> fare : fares){
        v[fare[0]].push_back(Node{fare[1], fare[2]});
        v[fare[1]].push_back(Node{fare[0], fare[2]});
    }
    
    flag = 0;
    do_dijkstra(s);
    flag = 1;
    do_dijkstra(a);
    flag = 2;
    do_dijkstra(b);
    
    answer = inf; //될 수 없는 큰 수
    for(int mid=1;mid<=n;mid++){
        int fromS = dist[0][mid];
        int fromA = dist[1][mid];
        int fromB = dist[2][mid];
        
        if(fromS == inf || fromA == inf || fromB == inf){
            continue;
        }
        answer = min(answer, fromS + fromA + fromB);
    }
    
    return answer;
}