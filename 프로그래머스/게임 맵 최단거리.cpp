#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>

using namespace std;

int dist[101][101];
int N,M;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vector<vector<int>> m;

struct Node{
    int x,y;
};

void refresh(){
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            dist[i][j] = 10001;
        }
    }
}

void BFS(int a, int b){
    queue<struct Node> Q;
    
    dist[a][b] = 1;
    Q.push({a,b});
    
    while(!Q.empty()){
        struct Node node = Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int x = node.x+dx[i];
            int y = node.y+dy[i];
            if(x>=0 && x<N && y>=0 && y<M && m[x][y]==1){
                if(dist[x][y] > dist[node.x][node.y]+1){
                    dist[x][y] = dist[node.x][node.y] + 1;
                    Q.push({x,y});
                }
            }
        }
    }
    
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    m = maps;
    N = maps.size();
    M = maps[0].size();
    
    refresh();
    BFS(0,0);
    if(dist[N-1][M-1] == 10001){
        answer = -1;
    }
    else{
        answer = dist[N-1][M-1];
    }
    
    return answer;
}