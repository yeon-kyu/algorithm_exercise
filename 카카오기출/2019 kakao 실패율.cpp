#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct stage_info{
    int stage_num;
    double success_rate;
};

int v[200005];
vector<stage_info> info;

bool compare(stage_info a, stage_info b){
    if(a.success_rate < b.success_rate){ //성공률 높으면 배열의 뒤로 가야함
        return true;
    }
    else if(a.success_rate == b.success_rate){
        return a.stage_num < b.stage_num;
    }
    else{
        return false;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    int people_num = stages.size();
    
    for(int i=1;i<=N+1;i++){
        v[i] = 0;
    }
    
    for(int stage: stages){
        for(int i=0;i<stage;i++){
            v[i]++;
        }
    }
    
    for(int i=1;i<=N;i++){
        if(v[i-1] == 0){
            info.push_back({i, 1});
        }
        else{
            double successable = (double)v[i]/v[i-1];
            info.push_back({i, successable});
        }
    }
    
    sort(info.begin(), info.end(), compare);
    
    for(int i=0;i<N;i++){
        answer.push_back(info[i].stage_num);
    }
    
    return answer;
}