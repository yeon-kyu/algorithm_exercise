#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int N;
int R;
int Q;

vector<int> node[100001];
vector<int> childCnt;
bool visited[100001];

int dfs(int pos) {
	int cnt = 1;
	visited[pos] = true;

	int size = node[pos].size();
	for (int i = 0; i < size; i++) {
		if (visited[node[pos][i]] == false) {
			cnt += dfs(node[pos][i]);
		}
	}
	childCnt[pos] = cnt;
	return cnt;
}

void init() {
	childCnt.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> R >> Q;

	init();

	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	dfs(R);

	for (int i = 0; i < Q; i++) {
		int u;
		cin >> u;
		cout << childCnt[u] << '\n';
	}
}