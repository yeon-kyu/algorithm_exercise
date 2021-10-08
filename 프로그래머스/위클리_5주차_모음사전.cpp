#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> v;

void do_dfs(string s){
    if(s.size() == 5){
        return;
    }
    
    s+="1";
    v.push_back(s);
    do_dfs(s);
    
    s[s.size()-1]='2';
    v.push_back(s);
    do_dfs(s);
    
    s[s.size()-1]='3';
    v.push_back(s);
    do_dfs(s);
    
    s[s.size()-1]='4';
    v.push_back(s);
    do_dfs(s);

    s[s.size()-1]= '5';
    v.push_back(s);
    do_dfs(s);
}

int solution(string word) {
    int answer = 0;
    
    do_dfs("");
    
    int size = word.size();
    for(int i=0;i<size;i++){
        if(word[i] == 'A'){
            word[i] = '1';
        }
        else if(word[i] == 'E'){
            word[i] = '2';
        }
        else if(word[i] == 'I'){
            word[i] = '3';
        }
        else if(word[i] == 'O'){
            word[i] = '4';
        }
        else if(word[i] == 'U'){
            word[i] = '5';
        }
        else{
            cout<<"error";
        }
    }
    
    size = v.size();
    for(int i=0;i<size;i++){
        if(v[i] == word){
            answer = i+1;
            break;
        }
    }
    
    return answer;
}