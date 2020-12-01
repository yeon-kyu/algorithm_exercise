#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> num_case; //각 회당 가능한 모든 숫자들이 들어감
char visited[10];
int ans;
int strike;
int ball;

void check_answer(int round) { //세 숫자가 모였을때 strike,ball 수를 체크함
	int left, mid, right;
	for (int i = 1; i<10; i++) {
		if (visited[i] == 'L') {
			left = i;
		}
		else if (visited[i] == 'M') {
			mid = i;
		}
		else if (visited[i] == 'R') {
			right = i;
		}
	}
	//ans xyz << x:ans/100 , y:(ans%100)/10 , z:ans%10
	int x = ans / 100;
	int y = (ans % 100) / 10;
	int z = ans % 10;

	int s = 0; //brute force 각각의 경우에 센 s와 b
	int b = 0;
	if (x == left)
		s++;
	else if (x == mid || x == right)
		b++;
	if (y == mid)
		s++;
	else if (y == left || y == right)
		b++;
	if (z == right)
		s++;
	else if (z == left || z == mid)
		b++;
	
	if (s == strike && b == ball) {
		num_case[round].push_back(left * 100 + mid * 10 + right);
		//cout << left * 100 + mid * 10 + right << endl;
	}

}

void visit(int x, int round) { //brute-force
	int cnt = 0;
	for (int i = 1; i<10; i++) {
		if (visited[i]!='x') {
			cnt++;
		}
	}
	if (cnt == 0) {
		visited[x] = 'L';
	}
	else if (cnt == 1) {
		visited[x] = 'M';
	}
	else if (cnt == 2) {
		visited[x] = 'R';
		//cout << "!";
		check_answer(round); //현재의 스트라이크-볼이 맞는지 확인
		return;
	}
	else {
		return;
	}

	for (int i = 1; i<10; i++) {
		if (visited[i] == 'x') {
			visit(i, round);
			visited[i] = 'x';
		}
	}

}

int solution(vector<vector<int>> baseball) {
	int answer = 0;

	int n = baseball.size();

	for (int i = 0; i<n; i++) {
		vector<int> temp;
		num_case.push_back(temp);
	}

	for (int i = 0; i<n; i++) { //round 수 만큼 반복
		ans = baseball[i][0];
		strike = baseball[i][1];
		ball = baseball[i][2];
		for (int j = 1; j<10; j++) {
			for (int j = 1; j<10; j++) { //초기화
				visited[j] = 'x';
			}
			visit(j, i); //j부터 시작하는 brute-force 9번 반복. i는 현재 round
		}
	}

	for (int i = 1; i < n; i++) { //round 수 만큼 반복
		int nn = num_case[0].size();
		for (int j = 0; j < nn; j++) { //num_case[0]와 각각 비교하여 겹치는게 있으면 생존, 없으면 삭제=> 최종적으로 모두다 겹치는 숫자만 생존
			vector<int>::iterator it;
			it = find(num_case[i].begin(), num_case[i].end(), num_case[0][j]);
			if (it == num_case[i].end()) {
				//cout << i<<"번째인데 "<<num_case[0][j]<< "지운다" << endl;
				num_case[0].erase(num_case[0].begin() + j);
				j--;
				nn--;
			}
			

		}
		
	}
	answer = num_case[0].size();

	return answer;
}

