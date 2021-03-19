#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> node[201];

int parent[201];

int getParent(int pos) {
	if (parent[pos] == pos) {
		return pos;
	}
	else {
		return parent[pos] = getParent(parent[pos]);
	}
}

void unionParent(int a, int b) {
	int A = getParent(a);
	int B = getParent(b);
	if (A > B) { //���ڰ� �� �����ָ� �θ�� ����
		parent[A] = B;
	}
	else {
		parent[B] = A;
	}

}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j<n; j++) {
			if (computers[i][j] == 1) {
				unionParent(i + 1, j + 1);
			}
		}
	}
	//���� ���� �θ�� ���� �ϳ�����
	vector<int> networkList;
	for (int i = 1; i <= n; i++) {
		int temp = getParent(i);
		if (find(networkList.begin(), networkList.end(), temp)==networkList.end()) {
			networkList.push_back(temp);
		}
	}
	return networkList.size();

}

int main() {

	cout << solution(3, { { 1,1,0 },{ 1,1,0 },{ 0,0,1 } });


	return 0;
}