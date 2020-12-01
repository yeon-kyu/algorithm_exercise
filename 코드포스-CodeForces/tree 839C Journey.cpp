#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> node[100001];
bool visited[100001] = { false };
double ans = 0;
void doDFS(int v, long long len, double branch) {
	visited[v] = true;
	len++;
	int s = node[v].size();
	
	if (s == 1) { //leaf 노드
		ans += (double)len * branch;
	}
	else {
		for (int i = 0; i < s; i++) {
			if (visited[node[v][i]] == false) {
				doDFS(node[v][i], len, branch/(s-1));
				visited[node[v][i]] = false;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 7개의 왕국에 n개의 도시, n-1개의 길..모든 도시 갈 수 있음
	//갔던 도시는 다시 들리지 않고 어느 한 곳에 도착했을 때 멈춘다
	// n <= 100000
	//u != v 각각 두 도시사이를 잇는 길을 의미함

	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);

	}
	visited[0] = true;
	node[1].push_back(0);
	doDFS(1, -1, 1);

	cout.precision(16);
	cout <<ans;
}