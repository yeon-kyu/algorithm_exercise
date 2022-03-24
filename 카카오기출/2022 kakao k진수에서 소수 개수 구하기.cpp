#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

string convertNtoK(int n, int k) {
    string s = "";
    while(true) {
        s += to_string(n%k);
        n = n/k;
        if(n == 0) {
            break;
        }
    }
    string str = s;
    int size = s.size();
    for(int i=0;i<size;i++){
        str[i] = s[size-1-i];
    }
    return str;
}

vector<string> split(string s, string del) {
    vector<string> v;
    while(true) {
        int pos = s.find(del);
        if(pos == string::npos) {
            v.push_back(s);
            break;
        }
        v.push_back(s.substr(0, pos));   
        s.erase(0, pos+del.size());
    }
    return v;
}

bool isPrimary(string s) {
    long long n = stoll(s);
    long long maxDivider = sqrt(n);
    
    if(n == 1) {
        return false;
    }
    
    for(long long i=2;i<=maxDivider;i++){
        if(n % i == 0) {
            return false;
        }
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    // 양의 정수 n 을 k진수로 변환
    string kNumber = convertNtoK(n,k);
    
    vector<string> v = split(kNumber, "0");
    for(string s : v) {
        if(s.size() >= 1) {
            if(isPrimary(s)) {
                answer++;
            }
        }
    }
    
    return answer;
}