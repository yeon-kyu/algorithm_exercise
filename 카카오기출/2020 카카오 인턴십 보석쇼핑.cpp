#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer;

	set<string> s;
	for (auto gem : gems) {
		s.insert(gem);
	}
	int setSize = s.size();

	int minStart = 0;
	int minEnd = gems.size() - 1;

	map<string, int> m;

	int gemsSize = gems.size();
	int start = 0;
	int end = 0;

	m.insert(make_pair(gems[start], 1));

	while (true) {
		// 종결조건
		if (end == gemsSize) {
			break;
		}

		if (setSize > m.size()) {
			end++;
			if (end == gemsSize) {
				break;
			}
			if (m.find(gems[end]) == m.end()) {
				m.insert(make_pair(gems[end], 1));
			}
			else {
				m[gems[end]] = m[gems[end]] + 1;
			}
		}
		else if (setSize == m.size()) {
			if (minEnd - minStart > end - start) {
				minStart = start;
				minEnd = end;
			}
			if (m[gems[start]] > 1) {
				m[gems[start]] = m[gems[start]] - 1;
			}
			else {
				m.erase(gems[start]);
			}
			start++;
		}
	}
	answer.push_back(minStart + 1);
	answer.push_back(minEnd + 1);

	return answer;
}