#include <string>
#include <vector>
#include <iostream>

using namespace std;

int checkStringSize(string str, int k){ //ababc -> 2abc
    
    string compress = "";
    string before = str.substr(0,k);
    int cnt = 1;
    int s= str.size();//4
    int i;
    for(i=k;i+k <= s;i += k){ //i = 2부터 시작, 2->끝
        string temp = str.substr(i,k);
        if(temp == before){ //이전 단위와 같을때
            cnt++;
        }
        else{
            if(cnt != 1){ //이전 단위와 다를때
                compress+=to_string(cnt);    
            }
            compress+=before;
            cnt = 1;
            before = temp;
        }
        
    }
    if(cnt ==1 ){
        compress+=before;
    }
    else{
        compress+=to_string(cnt);
        compress+=before;
    }
    
    //i = 4
    string temp = str.substr(i,s-i);
    compress+=temp;
    //cout<<"k가 "<<k<<"일 때" << compress<<endl;
    return compress.size();
}

int solution(string s) {
    int answer = 0;
    

    int len = s.size();
    if(len == 1)
        return 1;
    
    int mini = len;
    for(int i=1;i<=len/2;i++){ //길이가 4면 2개단위로자르는것까지 확인. 길이5도 마찬가지.
        int temp = checkStringSize(s,i);
        if(temp < mini){
            mini = temp;
        }
    }
    answer = mini;
    
    return answer;
}