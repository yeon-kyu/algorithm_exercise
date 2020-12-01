//https://programmers.co.kr/learn/courses/30/lessons/42578
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;

	map<string, int> m;

	int size = clothes.size();
	for (int i = 0; i<size; i++) {
		if (m.find(clothes[i][1]) == m.end()) { //없으면 추가
			m[clothes[i][1]] = 1;
		}
		else {
			m[clothes[i][1]] = m[clothes[i][1]] + 1;
		}
	}
	int cnt = 1;
	int m_size = m.size();
	for (auto it = m.begin(); it != m.end(); it++) {
		cnt = cnt * (it->second + 1);
	}
	cnt--;
	answer = cnt;
	return answer;
}
