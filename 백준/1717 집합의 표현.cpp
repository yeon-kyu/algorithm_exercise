#include <iostream>

#include <vector>

using namespace std;

int parent[1000001];

int findParent(int temp) {
	int p = parent[temp];
	if (p == temp) {
		return temp;
	}
	else {
		return parent[temp] = findParent(p);
	}
}

void unionParent(int a, int b) {
	int A = findParent(a);
	int B = findParent(b);

	if (A < B) {
		parent[B] = A;
	}
	else {
		parent[A] = B;
	}
}

void checkSibling(int a, int b) {
	int A = findParent(a);
	int B = findParent(b);
	if (A == B) {
		cout << "YES" << " ";
	}
	else {
		cout << "NO" << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	int o, a, b;
	for (int i = 0; i < m; i++) {
		cin >> o >> a >> b;
		if (o == 0) {
			unionParent(a, b);
		}
		else {
			checkSibling(a, b);
		}
	}

}