#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> num_case; //�� ȸ�� ������ ��� ���ڵ��� ��
char visited[10];
int ans;
int strike;
int ball;

void check_answer(int round) { //�� ���ڰ� ������ strike,ball ���� üũ��
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

	int s = 0; //brute force ������ ��쿡 �� s�� b
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
		check_answer(round); //������ ��Ʈ����ũ-���� �´��� Ȯ��
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

	for (int i = 0; i<n; i++) { //round �� ��ŭ �ݺ�
		ans = baseball[i][0];
		strike = baseball[i][1];
		ball = baseball[i][2];
		for (int j = 1; j<10; j++) {
			for (int j = 1; j<10; j++) { //�ʱ�ȭ
				visited[j] = 'x';
			}
			visit(j, i); //j���� �����ϴ� brute-force 9�� �ݺ�. i�� ���� round
		}
	}

	for (int i = 1; i < n; i++) { //round �� ��ŭ �ݺ�
		int nn = num_case[0].size();
		for (int j = 0; j < nn; j++) { //num_case[0]�� ���� ���Ͽ� ��ġ�°� ������ ����, ������ ����=> ���������� ��δ� ��ġ�� ���ڸ� ����
			vector<int>::iterator it;
			it = find(num_case[i].begin(), num_case[i].end(), num_case[0][j]);
			if (it == num_case[i].end()) {
				//cout << i<<"��°�ε� "<<num_case[0][j]<< "�����" << endl;
				num_case[0].erase(num_case[0].begin() + j);
				j--;
				nn--;
			}
			

		}
		
	}
	answer = num_case[0].size();

	return answer;
}

