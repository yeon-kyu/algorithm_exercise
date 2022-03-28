#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;

vector<int> node[201];
int dist[201];

const int INF = 200001;

void bfs(int start) {
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	priority_queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int front = q.top(); //현재 확정지을 노드
		q.pop();

		int size = node[front].size();
		for (int i = 0; i < size; i++) {
			int cur = node[front][i]; //다음 큐에 넣을 후보
			int distance = dist[front] + 1;
			if (dist[cur] > distance) {
				dist[cur] = distance;
				q.push(cur);
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 도시의 수 N <= 200
	// 여행 계획에 속한 도시들의 수 M <= 1000

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				node[i + 1].push_back(j + 1);
			}
		}
	}

	vector<int> city(M);
	for (int i = 0; i < M; i++) {
		cin >> city[i];
	}

	bfs(city[0]);

	bool possible = true;
	for (int i = 0; i < M; i++) {
		if (dist[city[i]] == INF) {
			possible = false;
			break;
		}
	}

	if (possible) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

}