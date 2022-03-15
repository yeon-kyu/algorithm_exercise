#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> dp;

int solution(int n) {
    int ans = 0;

    while(true) {
        if(n%2 == 0) { //짝수
            n = n/2;
        } else { // 홀수
            n--;
            ans++;
        }
        if(n == 0) {
            break;
        }
    }
    return ans;
}