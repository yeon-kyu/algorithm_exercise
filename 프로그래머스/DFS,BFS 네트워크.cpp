#include <string>
#include <vector>

using namespace std;

bool visited[201] = { false };

vector<int> v[201];

void makeVisited(int pos) {
	visited[pos] = true;
	int s = v[pos].size();
	for (int i = 0; i<s; i++) {
		if (visited[v[pos][i]] == false) {
			makeVisited(v[pos][i]);
		}
	}
}

int checkGroup(int pos) {
	if (visited[pos] == true) { //�̹� ���� ����� ����Ǿ����ٸ�
		return 0;
	}
	else { //ó���̶�� ����� ���鵵 true��������
		makeVisited(pos);
		return 1;
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i<n; i++) {
		for (int k = 0; k<n; k++) {
			if (computers[i][k] == 1) {
				v[i].push_back(k);
			}
		}
	}

	for (int i = 0; i<n; i++) {
		answer += checkGroup(i);
	}


	return answer;
}