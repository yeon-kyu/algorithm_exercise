#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int N, M;
bool visited[101];

void refresh() {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
}

struct Node {
	vector<int> parent;
	vector<int> child;
};

Node node[101];

int getUpperCount(int pos) {
	visited[pos] = true;
	int cnt = 1;
	int size = node[pos].parent.size();
	for (int i= 0; i < size; i++){
		if (visited[node[pos].parent[i]] == false) {
			cnt += getUpperCount(node[pos].parent[i]);
		}
	}
	return cnt;
}

int getLowerCount(int pos) {
	visited[pos] = true;
	int cnt = 1;
	int size = node[pos].child.size();
	for (int i = 0; i < size; i++) {
		if (visited[node[pos].child[i]] == false) {
			cnt += getLowerCount(node[pos].child[i]);
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b; // a가 b보다 무겁다. a가 b의 부모
		node[b].parent.push_back(a);
		node[a].child.push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		refresh();
		int upperCount = getUpperCount(i);
		int lowerCount = getLowerCount(i);
		cout << N - (upperCount + lowerCount - 1) << '\n';
	}
}