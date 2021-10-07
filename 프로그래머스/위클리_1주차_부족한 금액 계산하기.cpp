#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    long long pay = 0;
    for(int i=1;i<=count;i++){
        pay += price*i;
    }
    
    answer = pay-money;
    if(answer < 0){
        answer = 0;
    }

    return answer;
}