#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>

using namespace std;

map<string, set<string>> mapOfReported; // <블럭당한 사람, 신고한 사람들>
vector<string> blocked;

vector<string> split(string str) {
    vector<string> v;
    int pos = str.find(' ');
    v.push_back(str.substr(0, pos));
    v.push_back(str.substr(pos + 1));
    return v;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for(string str : report) {
        vector<string> v = split(str);
        string reporter = v[0];
        string reported = v[1];
        mapOfReported[reported].insert(reporter);
    }
    
    for(string id : id_list) {
        if(mapOfReported[id].size() >= k) {
            blocked.push_back(id); // 정지된 id 추가
        }
    }
    
    map<string, set<string>> mapOfReporter; //신고한 사람 기준에서 정지된 개수 센다.
    for(string str : report) {
        vector<string> v = split(str);
        string reporter = v[0];
        string reported = v[1];
        if(find(blocked.begin(), blocked.end(), reported) != blocked.end()) {
            mapOfReporter[reporter].insert(reported);   
        }
    }
    
    for(string id : id_list) {
        answer.push_back(mapOfReporter[id].size());
    }
    
    return answer;
}