#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> tree[50];

void erase(int e) {

	int s = tree[e].size();
	if (s == 0) {
		tree[e].push_back(-1); //-1은 삭제됨을 의미. leaf의 역할못함
	}
	else {
		for (int i = 0; i < s; i++) {
			erase(tree[e][i]);
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;//<=50
	int temp;
	int E;
	int ans = 0;
	cin >> N;
	
	for (int i = 0; i < N; i++) { //tree 완성
		cin >> temp;
		if (temp != -1) {
			tree[temp].push_back(i);
		}
	}
	cin >> E;

	erase(E); //해당 노드 아래의 leaf node는 -1이 붙음(leaf가 아니게 됨)

	//지운 노드의 부모 노드가 자식이 1개였다면 leaf가 되야함
	for (int i = 0; i < N; i++) {
		int s = tree[i].size();
		for (int j = 0; j < s; j++) {
			if (tree[i][j] == E) { //지운노드의 부모 접근
				if (tree[i].size() == 1) { 
					ans++;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (tree[i].size() == 0) {
			ans++;
		}
	}
	cout << ans;
}
