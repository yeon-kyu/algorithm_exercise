#include <iostream>
#include <vector>

using namespace std;

int parent[101];

int findParent(int temp) {
	if (parent[temp] == temp) {
		return temp;
	}
	else {
		return findParent(parent[temp]);
	}
}

void unionParent(int x, int y) {
	int X = findParent(x);
	int Y = findParent(y);

	if (X < Y) {
		parent[Y] = X; //즉, y의 최상위 부모의 부모를 X로 둠(핵심)
	}
	else {
		parent[X] = Y;
	}
}


int main() {
	int C, n;
	cin >> C >> n;

	for (int i = 0; i <= C; i++) {
		parent[i] = i;
	}

	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		unionParent(x, y);
	}


	int temp = findParent(1);
	int ans = 0;
	for (int i = 1; i <= C; i++) {
		if (temp == findParent(i)) {
			ans++;
		}
	}
	cout << ans - 1;

}