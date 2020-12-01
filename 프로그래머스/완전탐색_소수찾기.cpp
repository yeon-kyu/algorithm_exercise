#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool num[7] = { false };
int s;
vector<vector<int>> vv;

void visit(string numbers, int x,vector<int> v) {
	num[x] = true;

	v.push_back(numbers[x]-'0');
	vv.push_back(v);

	bool flag = false;
	for (int i = 0; i < s; i++) {
		if (num[i] == false) {
			visit(numbers, i,v);
			num[i] = false;
			flag = true;
		}
	}
	if (flag == false) {
		return;
	}
}

bool check_prime(int x) { //서로소인지 확인
	if (x == 1 || x == 0) {
		return false;
	}
	for (int i = 2; i < x; i++) {
		if (x%i == 0) {
			return false;
		}
	}
	return true;
}

int solution(string numbers) {
	int answer = 0;

	s = numbers.size();

	vector<int> cnt;

	for (int i = 0; i < s; i++) {
		vector<int> v;
		visit(numbers, i, v);
		for (int j = 0; j < s; j++) {
			num[j] = false;
		}
	}
	
	for (int i = 0; i < vv.size(); i++) {
		int temp = 0;
		for (int j = 0; j < vv[i].size(); j++) {
			temp = temp*10 + vv[i][j];
		}
		
		if (find(cnt.begin(), cnt.end(), temp) != cnt.end()) {//이미 센 수면 추가안함
			continue;
		}

		if (check_prime(temp)) {
			//cout << temp << endl;
			cnt.push_back(temp);
			answer++;
		}
	}

	return answer;
}

