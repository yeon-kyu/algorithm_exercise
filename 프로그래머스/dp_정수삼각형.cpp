#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dp[502][502] = { 0 };

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    dp[0][0] = triangle[0][0];
    int s= triangle.size();
    for(int i=1;i<s;i++){
        for(int k = 0; k<=i; k++){ //i:1, k:0,1
            if(k>0){
                int x = dp[i-1][k-1];
                int y = dp[i-1][k];
                dp[i][k] = max(x,y)+triangle[i][k];
            }
            else{
                dp[i][k] = dp[i-1][k] + triangle[i][k];
            }
            
        }
    }
    int maxi = 0;
    for(int i=0;i<s;i++){
        if(dp[s-1][i]>maxi){
            maxi = dp[s-1][i];
        }
    }
    answer = maxi;
    
    
    return answer;
}