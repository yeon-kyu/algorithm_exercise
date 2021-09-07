#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

unordered_map<string, vector<int>> m;

vector<string> split(string s, string del){
    vector<string> v;
    int pos = 0;
    string token;
    while((pos = s.find(del)) != string::npos){
        token = s.substr(0,pos);
        v.push_back(token);
        s.erase(0,pos+del.size());
    }
    v.push_back(s);
    return v;
}

void brute_force_and_add_map(int cnt, string str, string made, int score){
    int size = made.size();
    if(size == cnt){
        m[made].push_back(score);
    }
    else{
        brute_force_and_add_map(cnt,str,made+str[size],score);
        brute_force_and_add_map(cnt,str,made+"-",score);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(string semi_info: info){
        vector<string> v = split(semi_info," ");
        string m_key = "";
        m_key.push_back(v[0][0]);
        m_key.push_back(v[1][0]);
        m_key.push_back(v[2][0]);
        m_key.push_back(v[3][0]);
        brute_force_and_add_map(4,m_key,"",stoi(v[4]));
    }
    
    for(auto it = m.begin();it!=m.end();it++){
        sort(it->second.begin(), it->second.end());
    }
    
    for(string semi_query: query){
        vector<string> v = split(semi_query," and ");
        vector<string> food_and_score = split(v[3], " ");
        
        string m_key = "";
        m_key.push_back(v[0][0]);
        m_key.push_back(v[1][0]);
        m_key.push_back(v[2][0]);
        m_key.push_back(food_and_score[0][0]);
        
        int ans = 0;
        vector<int> list = m[m_key];
        
        auto it = lower_bound(list.begin(), list.end(), stoi(food_and_score[1]));
        ans = list.end()-it;
        
        answer.push_back(ans);
    }
    
    return answer;
}