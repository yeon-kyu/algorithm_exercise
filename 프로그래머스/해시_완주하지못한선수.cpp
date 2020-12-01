//https://programmers.co.kr/learn/courses/30/lessons/42576
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	multimap<string, int> m;
	int p = participant.size();

	for (int i = 0; i <p; i++) {
		m.insert(make_pair(participant[i], i + 1));
	}

	for (int i = 0; i < p - 1; i++) {
		m.erase(m.find(completion[i]));
	}

	answer = m.begin()->first;
	return answer;
}
