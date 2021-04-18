#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
vector<int> v[100001];
int parent[100001];
int visited[100001];

void DFS(int pos,int p) {
	parent[pos] = p;
	visited[pos] = true;

	int size = v[pos].size();
	for (int i = 0; i < size; i++) {
		if (visited[v[pos][i]] == false) {
			DFS(v[pos][i], pos);
		}
	}
}

int main() {
	cin >> N; //N은 10만 이하
	int a, b;

	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i <= N; i++) {
		visited[i] = false;
	}

	DFS(1,1);
	
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}