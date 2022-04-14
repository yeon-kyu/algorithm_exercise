#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int N, M;

vector<int> node[32001];
int dependency[32001] = { 0 };
bool visited[32001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < M; i++) {
		int front, back;
		cin >> front >> back;
		node[front].push_back(back); // 의존성 갖고 있는 문제에 대한 리스트를 저장
		dependency[back]++;
	}

	int cnt = 0;
	while (true) {
		for (int i = 1; i <= N; i++) {
			if (visited[i] == false && dependency[i] == 0) {
				cout << i << ' ';
				visited[i] = true;
				cnt++;
				int size = node[i].size(); // 현재 지워지는 것에 의존성을 갖던 문제들
				for (int j = 0; j < size; j++) {
					dependency[node[i][j]]--;
				}
				break;
			}
		}
		if (cnt == N) {
			break;
		}
	}
}