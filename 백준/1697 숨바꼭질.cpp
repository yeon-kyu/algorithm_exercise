#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, K;

struct posInfo {
	int pos;
	int cnt;
};

bool visited[100001];

int do_bfs() {

	queue<posInfo> q;
	q.push({ N, 0 });
	
	while (!q.empty()) {
		int pos = q.front().pos;
		int cnt = q.front().cnt;
		q.pop();

		if (pos == K) {
			return cnt;
		}

		visited[pos] = true;
		cnt++;
		if (pos - 1 >= 0 && visited[pos-1] == false) {
			q.push({ pos - 1, cnt });
		}
		if (pos + 1 <= 100000 && visited[pos + 1] == false) {
			q.push({ pos + 1, cnt });
		}
		if (pos * 2 <= 100000 && visited[pos * 2] == false) {
			q.push({ pos * 2, cnt });
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < 100001; i++) {
		visited[i] = false;
	}

	cout << do_bfs();

}