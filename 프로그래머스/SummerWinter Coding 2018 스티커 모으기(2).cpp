#include <iostream>
#include <vector>
using namespace std;

int dp[100001];

int solution(vector<int> sticker) {
    int answer =0;

    int size = sticker.size();
    
    if(size == 1) {
        return sticker[0];
    }
    
    // 첫번째 인덱스를 골랐을 경우
    dp[0] = sticker[0];
    dp[1] = dp[0];
    for(int i=2;i<size-1;i++) {
        dp[i] = max(dp[i-2] + sticker[i], dp[i-1]);
    }
    int answerWithFirstIndexChosen = dp[size-2];
    
    // 첫번째 인덱스를 고르지 않았을 경우
    dp[0] = 0;
    dp[1] = sticker[1];
    for(int i=2;i<size;i++) {
        dp[i] = max(dp[i-2] + sticker[i], dp[i-1]);
    }
    int answerWithFirstIndexNotChosen = dp[size-1];
    
    answer = max(answerWithFirstIndexChosen, answerWithFirstIndexNotChosen);

    return answer;
}