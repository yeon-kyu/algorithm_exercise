#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string,int> m_combine;

void combination(string str, int idx, string result){
    int size = str.size();
    if(idx == size-1) {
        if(result.size()>1){
            if(m_combine.find(result) != m_combine.end()){
                m_combine[result]++;
            }
            else{
                m_combine[result] = 1;
            }
        }
        return;
    }
    idx++;
    combination(str,idx,result);
    combination(str,idx,result+str[idx]);
}

void make_combine(string str){//str 메뉴들로 가능한 모든 조합을 생성한다.
    int size = str.size();
    //5개 중에 2개의 조합을 m_combine에 넣는다.
    combination(str,-1,"");
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(string str : orders){ //만들 수 있는 모든 조합 생성
        sort(str.begin(),str.end());
        make_combine(str);
    }
    
    map<string,int> m[11];
    for(auto it = m_combine.begin();it!=m_combine.end();it++){ //각 조합들을 메뉴 수에 따라 분리
        
        if(it->second > 1){
            int c_size = (it->first).size();
            m[c_size][it->first] = it->second;
        }
        
        //cout<< it->first <<' '<<it->second <<endl;
    }
    for(int i : course){ //메뉴 수가 course 인 것들끼리 비교
        map<string,int> temp_m = m[i];
        int maxi = 2;
        for(auto it = temp_m.begin();it!=temp_m.end();it++){
            if(maxi < it->second){
                maxi = it->second;
            }
        }
        for(auto it = temp_m.begin();it!=temp_m.end();it++){
            if(it->second == maxi){
                answer.push_back(it->first);
            }
        }
    }
    
    sort(answer.begin(), answer.end()); //단어 오름차순 정렬
    
    return answer;
}