#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Document {
	int idx;
	int prior;
};
vector<Document> v;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	int size = priorities.size();
	for (int i = 0; i<size; i++) {
		v.push_back(Document{ i, priorities[i] });
	}

	while (!v.empty()) {
		Document front = v.front();
		v.erase(v.begin());

		//중요도가 높은 문서가 있는지 확인
		bool goBackFlag = false;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].prior > front.prior) {
				goBackFlag = true;
				break;
			}
		}
		if (goBackFlag == true) {
			// 맨 뒤로 보낸다.
			v.push_back(front);
		}
		else {
			// 인쇄한다
			answer++;
			if (front.idx == location) {
				break;
			}
		}
	}

	return answer;
}