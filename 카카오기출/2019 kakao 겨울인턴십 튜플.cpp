#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compareWithSize(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<string> split(string s, string del) {
    vector<string> v;
    int pos = 0;
    string token;
    while((pos=s.find(del)) != string::npos) {
        token = s.substr(0, pos);
        v.push_back(token);
        s.erase(0, pos + del.length());
    }
    v.push_back(s);
    return v;
}

vector<vector<int>> convertStringToSet(string s) {
    string newString = s.substr(1, s.size()-2);
    vector<vector<int>> v;
    
    vector<string> setVector = split(newString, "{");
    setVector.erase(setVector.begin());
    setVector[setVector.size()-1] += ",";
    for(int i=0;i<setVector.size(); i++) {
        int len = setVector[i].size();
        setVector[i] = setVector[i].substr(0, len-2);
        
        vector<string> numStringVector = split(setVector[i], ",");
        vector<int> numVector;
        for(string str : numStringVector) {
            numVector.push_back(stoi(str));
        }
        v.push_back(numVector);
    }
    
    return v;
}

int getDistinctNumber(vector<int>& ans, vector<int>& set) {
    for(int setNum : set) {
        if (find(ans.begin(), ans.end(), setNum) == ans.end()) {
            return setNum;
        }
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> v = convertStringToSet(s);
    sort(v.begin(), v.end(), compareWithSize);
    
    for(vector<int> set : v) {
        int distinctNum = getDistinctNumber(answer, set);
        answer.push_back(distinctNum);
    }
    
    return answer;
}