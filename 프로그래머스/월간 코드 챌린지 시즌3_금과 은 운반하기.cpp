#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long goldToCarry;
long long silverToCarry;

long long getMaxCarryCnt(long long limit, int t) {
    long long cnt = 0;
    if(limit > t) {
        cnt++;
        limit -= t;
    }
    cnt += limit / (2 * t);
    return cnt;
}

bool isPossibleToCarry(long long limit, vector<int> &g, vector<int> &s, vector<int> &w, vector<int> &t) {
    int size = g.size();
    
    long long Gmax = 0; //최대한으로 금을 끌어모았을때 양
    long long Smax = 0; //최대한으로 은을 끌어모았을 때 양
    long long totalMaxCarry = 0; // 금과 은을 합친 최대한의 양
    
    for(int i=0;i<size;i++) {
        long long cnt = getMaxCarryCnt(limit, t[i]); //전달 횟수
        
        int maxCarry = min(w[i] * cnt, (long long)(g[i] + s[i])); // 주어진 시간에 최대로 운반할 수 있는 양
        Gmax += min(g[i], maxCarry);
        Smax += min(s[i], maxCarry);
        totalMaxCarry += maxCarry;
    }
    
    if(goldToCarry <= Gmax && silverToCarry <= Smax && goldToCarry + silverToCarry <= totalMaxCarry) {
        return true;
    } else {
        return false;
    }
}


long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    // a : 옮겨야 하는 금의 총합
    // b : 옮겨야 하는 은의 총합
    goldToCarry = a;
    silverToCarry = b;
    
    // g[] : 각 도시가 갖고 있는 금의 양
    // s[] : 각 도시가 갖고 있는 은의 양
    // w[] : 각 도시가 새 도시로 옮기는 최대 용량
    // t[] : 각 도시가 새 도시로 옮기는데 걸리는 시간
    
    long long minTime = 1;
    long long maxTime = (long long)1000000000 * 100000 * 2 * 2;
    //하나의 도시에서만 제공.
    //a가 최대 1,000,000,000, t최대 100,000, 2(왕복), 2(금따로 은따로)
    
    while(minTime < maxTime) {
        long long limit = (minTime + maxTime) / 2;
        if(isPossibleToCarry(limit, g, s, w, t) == true) {
            maxTime = limit;
        } else {
            minTime = limit + 1;
        }
    }
    
    return maxTime;
}