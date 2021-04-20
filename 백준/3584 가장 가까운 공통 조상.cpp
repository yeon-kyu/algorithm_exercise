#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> node[10001];

void refreshNode() {
	for (int i = 0; i < 10001; i++) {
		node[i].clear();
	}
}

vector<int> getParentArray(int a) {
	if (node[a].size() > 0) {
		vector<int> A = getParentArray(node[a][0]);
		A.push_back(a);
		return A;
	}
	else {
		vector<int> A;
		A.push_back(a);
		return A;
	}
}

void findCommonParent(int a, int b) {
	vector<int> a_parents = getParentArray(a);
	vector<int> b_parents = getParentArray(b);

	int a_size = a_parents.size();
	int b_size = b_parents.size();
	if (a_size > b_size) {
		a_size = b_size;
	}

	int pos = 0;
	int i = 0;
	for (i = 0; i < a_size; i++) {
		if (a_parents[i] != b_parents[i]) {
			pos = i - 1;
			break;
		}
	}
	if (i == a_size) {
		pos = i - 1;
	}
	cout << a_parents[pos] << '\n';

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int parent, child;
		for (int j = 1; j < N; j++) {
			cin >> parent >> child;
			node[child].push_back(parent);
		}
		int a_node, b_node;
		cin >> a_node >> b_node;
		findCommonParent(a_node, b_node);

		refreshNode();
	}


	return 0;
}