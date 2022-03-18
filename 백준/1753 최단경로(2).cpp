#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int V, E, K;
struct nodeInfo {
	int dest;
	int w;
};
vector<nodeInfo> node[20001];
int dist[20001];
int INF = 200001;

struct compare {
	bool operator()(int a, int b) {
		return dist[a] > dist[b];
	}
};

void dijkstra() {
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	priority_queue<int, vector<int>, compare> q;
	dist[K] = 0;
	q.push(K);
	while (!q.empty()) {
		int cur = q.top(); //현재 확정지을 노드
		q.pop();

		int size = node[cur].size();
		for (nodeInfo nextNode : node[cur]) {
			int next = nextNode.dest;
			int cost = dist[cur] + nextNode.w;
			if (cost < dist[next]) {
				q.push(next);
				dist[next] = cost;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> K; 
	// N : 정점 개수, E : 간선 개수, K : 시작 번호

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b, c });
	}
	dijkstra();

	for (int i = 1; i <= V; i++) {
		int d = dist[i];
		if (d == INF) {
			cout << "INF" << '\n';
		}
		else {
			cout << d << '\n';
		}
	}
}