#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> split(string s, string del){
    vector<string> v;
    int pos = 0;
    string token;
    while((pos = s.find(del)) != string::npos){
        token = s.substr(0,pos);
        v.push_back(token);
        s.erase(0,pos+del.length());
    }
    v.push_back(s);
    return v;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    
    int max_result = 0;
    
    for(int i=0;i<5;i++){
        vector<string> s = split(table[i]," ");
        
        int tot = 0;
        
        for(int j=1;j<=5;j++){
            
            int size = languages.size(); 
            for(int k=0;k<size;k++){ //languages에 있으면
                if(languages[k] == s[j]){
                    tot+=preference[k] * (6-j);
                    break;
                }
            }
        }
        
        if(tot > max_result){
            max_result = tot;
            answer = s[0];
        }
        else if(tot==max_result){
            if(s[0] < answer){
                answer = s[0];
            }
        }
        
    }
    
    return answer;
}