#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parent[101];
vector<int> child[101];
int cnt = 0;
int N;
int visited[101] = {false};
int getParentCnt(int pos){
    visited[pos] = true;
    int s = parent[pos].size();
    if(s==0){
        return 0;
    }
    int ret = 0;
    for(int i=0;i<s;i++){
        if(visited[parent[pos][i]] == false)
            ret += getParentCnt(parent[pos][i])+1;
    }
    return ret;
}
int getChildCnt(int pos){
    visited[pos] = true;
    int s = child[pos].size();
    if(s==0){
        return 0;
    }
    int ret= 0;
    for(int i = 0;i<s;i++){
        if(visited[child[pos][i]] == false)
            ret+=getChildCnt(child[pos][i])+1;
    }
    return ret;
}

void checkSure(int pos){
    
    int a = getParentCnt(pos);
    int b = getChildCnt(pos);
    
    cout<<pos<<"의 부모수 : "<<a<<", 자식수 : "<<b<<endl;
    
    if( a+b+1 == N){
        cnt++;
    }
    
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    N=n;
    for(int i=0;i<results.size();i++){
        int a = results[i][0];
        int b= results[i][1];
        parent[b].push_back(a);
        child[a].push_back(b);
    }
    
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            visited[k] = false;
        }
        checkSure(i);
    }
    answer = cnt;
    
    return answer;
}