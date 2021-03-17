#include <iostream>

using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    
    int small = h;
    int big = w;
    
    if(w>h){ //h가 작다
        small = h;
        big = w;
    }
    else{ //w가 작다
        small = w;
        big = h;
    }
    int G;
    for(int i = small; i>0 ;i--){
        
        if(big%i==0&&small%i==0){
            G = i;
            break;
        }
    }
    
    int sub = w+h-G;//그어진 선이 침범한 정사각형 수
    answer = (long long)w*h-sub;
    
    return answer;
}