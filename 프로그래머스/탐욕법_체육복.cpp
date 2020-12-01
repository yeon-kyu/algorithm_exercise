#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;


	int lost_s = lost.size();
	answer += n - lost_s;

	for (int i = 0; i < lost_s; i++) {
		vector<int>::iterator it;
		it = find(reserve.begin(), reserve.end(), lost[i]); //������ ������ �����ִ����
		if (it != reserve.end()) {
			answer++;
			reserve.erase(it);
			lost.erase(lost.begin() + i);
			lost_s--;
			i--;
			
		}
	}

	for (int i = 0; i<lost_s; i++) {
		vector<int>::iterator it;

		it = find(reserve.begin(), reserve.end(), lost[i] - 1); //���� �л����� �������ִٸ�
		if (it != reserve.end()) {
			answer++;
			reserve.erase(it);
			continue;
		}
		it = find(reserve.begin(), reserve.end(), lost[i] + 1); //���� �л����� ���� �� �ִٸ�
		if (it != reserve.end()) {
			answer++;
			reserve.erase(it);
			continue;
		}
	}

	return answer;
}


