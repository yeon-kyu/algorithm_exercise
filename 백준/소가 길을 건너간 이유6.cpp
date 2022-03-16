#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N, K, R;

vector<int> node[10001];
int parent[10001];

void init() {
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0,0,1,-1 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n = i * N + j + 1;

			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
					int newN = ny * N + nx + 1;
					node[n].push_back(newN);
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int n1 = (r1 - 1) * N + c1;
		int n2 = (r2 - 1) * N + c2;
		// n1과 n2를 갈라놓는다.(길을 만든다)

		node[n1].erase(find(node[n1].begin(), node[n1].end(), n2));
		node[n2].erase(find(node[n2].begin(), node[n2].end(), n1));
	}
}

int getParent(int a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		return parent[a] = getParent(parent[a]);
	}
}

void unionParent(int a, int b) {
	int A = getParent(a);
	int B = getParent(b);

	if (A <= B) {
		parent[B] = A;
	}
	else {
		parent[A] = B;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// K : 농장에 있는 소의 수. 1이상
	// N : 정사각형 목초지가 한 행/열에 있는 개수. 1이상
	// R : 길의 갯수

	cin >> N >> K >> R;

	init();

	for (int i = 1; i <= N*N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N*N; i++) {
		int size = node[i].size();
		for (int j = 0; j < size; j++) {
			int adj = node[i][j];
			int cur = i;
			unionParent(adj, cur);
		}
	}

	map<int, int> m;
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		int n = (r - 1)*N + c;
		int parentOfN = getParent(n);
		if (m.find(parentOfN) == m.end()) {
			m[parentOfN] = 1;
		}
		else {
			m[parentOfN] = m[parentOfN] + 1;
		}
	}

	vector<int> v;
	for (auto it = m.begin(); it != m.end(); it++) {
		v.push_back(it->second);
	}

	int answer = 0;
	int size = v.size();
	for (int i = 0; i < size; i++) {
		int cur = v[i];
		for (int j = i + 1; j < size; j++) {
			int next = v[j];
			answer += cur * next;
		}
	}

	cout << answer;
}