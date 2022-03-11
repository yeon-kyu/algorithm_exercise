#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool isPair(char before, char c) {
    return (before == '(' && c == ')') || (before == '[' && c == ']') || (before == '{' && c == '}');
}

bool isRightString(string str) {
    stack<char> st;
    for(int i=0;i<str.size();i++) {
        char c = str[i];
        if(c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if(st.empty()) {
                return false;
            }
            else {
                char before = st.top();
                st.pop();
                if(isPair(before, c) == false) {
                    return false;
                }
            }
        }
    }
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    
    for(int i=0;i<s.size();i++) {
        string str = s.substr(i) + s.substr(0, i);
        if (isRightString(str)) {
            answer++;
        }
    }
    return answer;
}