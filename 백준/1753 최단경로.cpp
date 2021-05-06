#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int V, E;
int start;
struct Dir {
	int dest;
	int w;
};
vector<struct Dir> node[20001];
int dist[20001];
bool visited[20001];
vector<int> Q;

int intMax = INT_MAX;

bool notInQueue(int pos) {
	for (auto it = Q.begin(); it != Q.end(); it++) {
		if (*it == pos) {
			return false;
		}
	}
	return true;
}


void findMinAndSwap() {

	int idx = 0;

	int size = Q.size();
	for (int i = 0; i < size; i++) {

		if (dist[Q[i]] < dist[Q[idx]]) {
			idx = i;
		}
	}
	int temp = Q[idx];
	Q[idx] = Q[0];
	Q[0] = temp;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	cin >> start;

	for (int i = 1; i <= V; i++) {
		visited[i] = false;
		dist[i] = intMax;
	}
	dist[start] = 0;

	int u, v, w;
	struct Dir d;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		d.dest = v;
		d.w = w;

		node[u].push_back(d);
	}

	Q.push_back(start);

	while (!Q.empty()) {

		findMinAndSwap();

		int cur = Q[0];
		int size = node[cur].size();
		for (int i = 0; i < size; i++) {
			if (visited[node[cur][i].dest] == false) {
				if (notInQueue(node[cur][i].dest)) {
					Q.push_back(node[cur][i].dest);
					dist[node[cur][i].dest] = dist[cur] + node[cur][i].w;
				}
				else {
					dist[node[cur][i].dest] = min(dist[cur] + node[cur][i].w, dist[node[cur][i].dest]);
				}
			}
		}
		visited[cur] = true;
		Q.erase(Q.begin());

	}
	for (int i = 1; i <= V; i++) {
		int d = dist[i];
		if (d == intMax) {
			cout << "INF" << '\n';
		}
		else {
			cout << dist[i] << '\n';
		}
	}

	return 0;
}