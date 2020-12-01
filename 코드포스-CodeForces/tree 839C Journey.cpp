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
	
	if (s == 1) { //leaf ���
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

	// 7���� �ձ��� n���� ����, n-1���� ��..��� ���� �� �� ����
	//���� ���ô� �ٽ� �鸮�� �ʰ� ��� �� ���� �������� �� �����
	// n <= 100000
	//u != v ���� �� ���û��̸� �մ� ���� �ǹ���

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