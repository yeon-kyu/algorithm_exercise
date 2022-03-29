#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int T;
int node[1001][2]; // 왼쪽자식 : [][0], 오른쪽 자식 : [][1]
int root;

void refresh() {
	for (int i = 0; i < 1001; i++) {
		node[i][0] = -1;
		node[i][1] = -1;
	}
}

int getPosition(vector<int> v, int target) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == target) {
			return i;
		}
	}
	return -1;
}

int getLeftIndex(vector<bool> v, int idx) {
	for (int i = idx-1; i >= 0; i--) {
		if (v[i] == true) {
			return i;
		}
	}
	return -1;
}
int getRightIndex(vector<bool> v, int idx) {
	for (int i = idx + 1; i < v.size(); i++) {
		if (v[i] == true) {
			return i;
		}
	}
	return -1;
}

void makeBT(vector<int> &preorder, vector<int> &inorder, int N) {
	vector<bool> visited(N, false);
	vector<int> updateOrder(N+1, 0);

	root = preorder[0];
	visited[getPosition(inorder, root)] = true;
	updateOrder[root] = 1;
	
	for (int i = 1; i < N; i++) {
		int cur = preorder[i];

		int indexOfInorder = getPosition(inorder, cur);
		int left = getLeftIndex(visited, indexOfInorder);
		int right = getRightIndex(visited, indexOfInorder);
		
		int parent;
		if (left == -1 && right == -1) {
			cout << "Impossible" << cur <<' '<< indexOfInorder << endl;
		}
		else if (left == -1) {
			parent = inorder[right];
			node[parent][0] = cur;
			updateOrder[cur] = updateOrder[parent] + 1;
		}
		else if (right == -1) {
			parent = inorder[left];
			node[parent][1] = cur;
			updateOrder[cur] = updateOrder[parent] + 1;
		}
		else {
			// left와 right 중에 더 자식인것의 자식임
			int leftLevel = updateOrder[inorder[left]];
			int rightLevel = updateOrder[inorder[right]];

			if (leftLevel < rightLevel) { // 오른쪽 index의 왼쪽 자식임
				parent = inorder[right];
				node[parent][0] = cur;
				updateOrder[cur] = updateOrder[parent] + 1;
			}
			else { // 왼쪽 index의 오른쪽 자식임
				parent = inorder[left];
				node[parent][1] = cur;
				updateOrder[cur] = updateOrder[parent] + 1;
			}
		}

		visited[indexOfInorder] = true;
	}
}

void postOrder(int pos) {
	if (node[pos][0] != -1) {
		postOrder(node[pos][0]);
	}
	if (node[pos][1] != -1) {
		postOrder(node[pos][1]);
	}
	cout << pos << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		vector<int> preorder(N);
		vector<int> inorder(N);
		for (int j = 0; j < N; j++) {
			cin >> preorder[j];
		}
		for (int j = 0; j < N; j++) {
			cin >> inorder[j];
		}
		refresh();
		makeBT(preorder, inorder, N);

		postOrder(root);
		cout << '\n';
	}
}