#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, P, K;
struct edge {
	int dest;
	int price;
};
vector<edge> node[1001];

int INF = 1000001;
int dist[1001] = { INF };

void refresh() {
	for (int i = 0; i <= N; i++) {
		dist[i] = INF;
	}
}

struct compare {
	bool operator()(int a, int b) {
		return dist[a] > dist[b];
	}
};

bool dijkstra(int limit) { // K 이하의 비용으로 N까지 도달할 수 있는가 결정!
	refresh();
	
	priority_queue<int, vector<int>, compare> pq;

	pq.push(1);
	dist[1] = 0;
	while (!pq.empty()) {
		int cur = pq.top(); //현재 확정지을 노드
		pq.pop();
		
		for (edge e : node[cur]) {
			int next = e.dest; // 큐에 넣을 후보
			int nextDist = dist[cur] + (e.price > limit);

			if (dist[next] > nextDist) {
				dist[next] = nextDist;
				pq.push(e.dest);
			}
		}
	}

	return dist[N] <= K;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> P >> K;

	// N : 컴퓨터 개수
	// P : 케이블 선 개수
	// K : 공짜 케이블 선 개수

	for (int i = 0; i < P; i++) {
		int a, b, price;
		cin >> a >> b >> price;
		node[a].push_back({ b, price });
		node[b].push_back({ a, price });
	}

	int start = 0;
	int end = 1000000;
	int ans = -1;
	while (start <= end) {
		int mid = (start + end) / 2;
		bool flag = dijkstra(mid);
		if (flag) {
			end = mid - 1;
			ans = mid;
		}
		else {
			start = mid + 1;
		}
	}
	cout << ans;
}