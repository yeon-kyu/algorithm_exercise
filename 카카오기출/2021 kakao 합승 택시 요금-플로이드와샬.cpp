#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dist[201][201];

int inf = 987654321;


void do_floydwarshall(int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j=1; j <= n; j++){
            dist[i][j] = inf;
        }
    }
    
    for(int i=1; i <= n; i++){
        dist[i][i] = 0;
    }
    
    for(vector<int> fare : fares){
        int x = fare[0];
        int y = fare[1];
        int z = fare[2];
        dist[fare[0]][fare[1]] = fare[2];
        dist[fare[1]][fare[0]] = fare[2];
    }
     
    do_floydwarshall(n);
    
    answer = inf; //될 수 없는 큰 수
    for(int mid=1;mid<=n;mid++){
        int fromS = dist[s][mid];
        int fromA = dist[mid][a];
        int fromB = dist[mid][b];
        
        if(fromS == inf || fromA == inf || fromB == inf){
            continue;
        }
        answer = min(answer, fromS + fromA + fromB);
    }
    
    return answer;
}