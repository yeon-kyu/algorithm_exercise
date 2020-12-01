#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	int size = answers.size();

	vector<int> p1 = { 1,2,3,4,5 };
	vector<int> a;

	vector<int> p2 = { 2,1,2,3,2,4,2,5 };
	vector<int> b;

	vector<int> p3 = { 3,3,1,1,2,2,4,4,5,5 };
	vector<int> c;
	

	for (int i = 0; i<size; i++) {
		a.push_back(p1[i % 5]);
		b.push_back(p2[i % 8]);
		c.push_back(p3[i % 10]);
	}

	int ans1 = 0;
	int ans2 = 0;
	int ans3 = 0;

	for (int i = 0; i<size; i++) {
		if (answers[i] == a[i]) {
			ans1++;
		}
		if (answers[i] == b[i]) {
			ans2++;
		}
		if (answers[i] == c[i]) {
			ans3++;
		}
	}
	int max = ans1;
	if (ans2>max) {
		max = ans2;
	}
	if (ans3>max) {
		max = ans3;
	}

	if (ans1 == max) {
		answer.push_back(1);
	}
	if (ans2 == max) {
		answer.push_back(2);
	}
	if (ans3 == max) {
		answer.push_back(3);
	}

	return answer;
}