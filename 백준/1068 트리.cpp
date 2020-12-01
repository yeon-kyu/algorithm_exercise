#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> tree[50];

void erase(int e) {

	int s = tree[e].size();
	if (s == 0) {
		tree[e].push_back(-1); //-1�� �������� �ǹ�. leaf�� ���Ҹ���
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
	
	for (int i = 0; i < N; i++) { //tree �ϼ�
		cin >> temp;
		if (temp != -1) {
			tree[temp].push_back(i);
		}
	}
	cin >> E;

	erase(E); //�ش� ��� �Ʒ��� leaf node�� -1�� ����(leaf�� �ƴϰ� ��)

	//���� ����� �θ� ��尡 �ڽ��� 1�����ٸ� leaf�� �Ǿ���
	for (int i = 0; i < N; i++) {
		int s = tree[i].size();
		for (int j = 0; j < s; j++) {
			if (tree[i][j] == E) { //�������� �θ� ����
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
