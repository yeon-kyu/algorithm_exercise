#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct playerInfo{
    double percent;//승률
    int cnt;//무거운 복서 이긴 횟수
    int weight; //몸무게
    int num; //번호
};

vector<playerInfo> v;

bool compare(playerInfo a, playerInfo b){
    
    if(a.percent!=b.percent){ //승률 높은 놈 앞으로
        return a.percent > b.percent;
    }
    else if(a.cnt != b.cnt){// cnt 큰 놈 앞으로
        return a.cnt > b.cnt;
    }
    else if(a.weight != b.weight){ //weight 큰 놈 앞으로
        return a.weight > b.weight;
    }
    else{ //번호 큰놈 뒤로
        return a.num < b.num;
    }
    
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    
    //1. 승률 높으면 앞으로, 전적없으면 승률0%
    //2. 승률 같으면 -> 자신보다 무거운 복서 이긴 횟수가 앞으로
    //3. 2번도 같으면 무거운 선수 앞으로
    //4. 3번도 같으면 복서 번호 작은 사람이 앞으로
    
    int size = weights.size();
    for(int i=0;i<size;i++){ //각 선수에 대해 탐색
        string result = head2head[i];
        int win_cnt=0; //모든 이긴 횟수
        int cnt = 0;//몸무게 큰 사람 이긴 횟수
        int lose_cnt=0;
        for(int j=0;j<size;j++){
            if(result[j] == 'W'){
                win_cnt++;
                if(weights[j] > weights[i]){
                    cnt++;
                }
            }
            else if(result[j] =='L'){
                lose_cnt++;
            }
        }
        
        if(win_cnt+lose_cnt == 0){
            v.push_back({(double)0, cnt, weights[i],i+1});
        }
        else{
            v.push_back({(double)win_cnt/(win_cnt+lose_cnt), cnt, weights[i],i+1});
        }
    }
    
    sort(v.begin(), v.end(), compare);
    for(int i=0;i<size;i++){
        answer.push_back(v[i].num);
    }
    
    return answer;
}