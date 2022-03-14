#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dunsSize;
int K;
int ans = 0;

void calcMaxCount(vector<vector<int>> &duns, vector<int> visitedDuns) {
    int tired = K;
    int cnt = 0;
    for(int idx : visitedDuns) {
        if(tired >= duns[idx][0]) {
            tired -= duns[idx][1];
            cnt++;
        } else {
            break;
        }
    }
    ans = max(ans, cnt);
}

void brute(vector<vector<int>> &duns, vector<int> visitedDuns) {
    if(visitedDuns.size() == dunsSize) {
        calcMaxCount(duns, visitedDuns);
        return;
    }
    
    for(int i=0;i<dunsSize;i++) {
        if(find(visitedDuns.begin(), visitedDuns.end(), i) == visitedDuns.end()) {
            vector<int> temp = visitedDuns;
            temp.push_back(i);
            brute(duns, temp);
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    K = k;
    dunsSize = dungeons.size();
    
    vector<int> temp;
    brute(dungeons, temp);
    
    answer = ans;
    
    return answer;
}