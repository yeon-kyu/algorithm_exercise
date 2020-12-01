#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> adj[10001];
vector<int> visited;
vector<int> hacked;

void init() {
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[y].push_back(x);
	}
}

int doDFS(int temp) {
	int cnt_stack = 1; //몇개의 노드를 만났는지 카운트함

	visited[temp] = 1;

	int size = adj[temp].size();
	for (int i = 0; i < size; i++) {
		if (visited[adj[temp][i]] == 0) {
			cnt_stack += doDFS(adj[temp][i]);
		}
	}
	return cnt_stack;
}

int main() {
	init();
	vector<int> cnt;
	cnt.push_back(0);

	for (int i = 1; i <= n; i++) {
		visited = vector<int>(n + 1, 0);
		cnt.push_back(doDFS(i)); // 해킹되는 컴퓨터 수 push_back
	}
	int max = cnt[1];
	for (int i = 1; i <= n; i++) {
		//cout << cnt[i] << endl;
		if (cnt[i] > max) {
			max = cnt[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == max)
			cout << i << " ";
	}

}