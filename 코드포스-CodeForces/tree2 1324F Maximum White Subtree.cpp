#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[200001];
vector<int> v[200001];
bool visited[200001] = { false };
int upMax[200001];
int ans[200001];

int doDFS(int temp) {

	visited[temp] = true;
	int cnt = a[temp]; //1�̸� white, 0�̸� black
	if (cnt == 0) {
		cnt = -1;
	}

	int s = v[temp].size();
	for (int i = 0; i < s; i++) {
		if (visited[v[temp][i]] == false) { //�ȵ�ȴٸ� �湮
			int x = doDFS(v[temp][i]);
			if (x < 0) //�湮�Ѱ� �ִ��� ����ٸ�
				x = 0; //�湮 ���
			cnt += x; //cnt : upMax
		}
	}
	upMax[temp] = cnt;
	return cnt;
}
void doDFS2(int temp,int fp) { //fp�� ������������
	visited[temp] = true;

	if (fp == -1) ans[temp] = upMax[temp];
	else ans[temp] = upMax[temp] + fp;
	
	int s = v[temp].size();
	for (int i = 0; i < s; i++) {
		if (visited[v[temp][i]] == false) {
			if (upMax[v[temp][i]] == -1)
				doDFS2(v[temp][i], ans[temp]);
			else  
				doDFS2(v[temp][i], ans[temp] - upMax[v[temp][i]]);
		}
	}
	//ans[temp];
}

int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	//a[v]=1�̸� v�� ���, 0�̸� v�� ������
	
	scanf("%d", &n);
	//cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		//cin >> a[i];
	}
	int t1,t2;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &t1, &t2);
		//cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}

	doDFS(1);
	for (int j = 1; j <= n; j++) {
		visited[j] = false;
	}
	doDFS2(1, 0);

	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	//����...����� ������ �ؾ��� ��
	//dfs�� ���� �˰����̸�(�ð��Ҹ� ŭ) ����� ���ܶ�
	//��Ʈ�� ���� ���ٸ� �ƹ� ��峪 ��Ʈ�� ��Ƶ��ȴ�.
}