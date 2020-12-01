#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
struct node {
	int x;
	int y;
};
vector<int> v[101];
bool visited[101];
bool done[101] = { false };

void doDFS(int pos) {
	done[pos] = true;
	visited[pos] = true;

	int s = v[pos].size();
	for (int i = 0; i < s; i++) {
		if (visited[v[pos][i]] == false) {
			doDFS(v[pos][i]);
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	node a[101];

	cin >> n;
	int x, y;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		a[i].x = x;
		a[i].y = y;
	}

	for (int i = 1; i <= n; i++) {//������ ��忡 ���ؼ�
		for (int j = 1; j < i; j++) { //�ٸ� ����� ������ ��
			if (a[i].x == a[j].x || a[i].y == a[j].y) { //���� �����ΰ��� ������
				v[i].push_back(j);
				v[j].push_back(i);
				//cout << i << " �� " << j << " ����" << endl;
			}
		}
	}

	int cnt = -1; //���� : �׷��� �� - 1
	for (int i = 1; i <= n; i++) {
		if (done[i] == false) {
			for (int j = 1; j <= n; j++) {
				visited[j] = false;
			}
			doDFS(i);
			cnt++;
		}
	}
	cout << cnt;




	//cout << ans;

}