#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, Q;

struct nodeInfo {
	int dest;
	int usado;
};

vector<nodeInfo> node[5001];
bool visited[5001];

int getCountOfVideo(int k, int v) {
	queue<int> q;
	q.push(v);
	visited[v] = true;
	int cnt = 0;

	while (!q.empty()) {
		int top = q.front();
		q.pop();

		int size = node[top].size();
		for (int i = 0; i < size; i++) {
			nodeInfo cur = node[top][i];
			if (cur.usado >= k && visited[cur.dest] == false) {
				q.push(cur.dest);
				visited[cur.dest] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

void refreshVisited() {
	for (int i = 0; i < 5001; i++) {
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	for (int i = 1; i < N; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		node[p].push_back({ q, r });
		node[q].push_back({ p, r });
	}

	for (int i = 0; i < Q; i++) {
		int k, v;
		cin >> k >> v;

		refreshVisited();
		cout << getCountOfVideo(k, v) <<' ';
	}
}