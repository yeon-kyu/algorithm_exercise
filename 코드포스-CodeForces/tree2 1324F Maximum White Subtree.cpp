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
	int cnt = a[temp]; //1이면 white, 0이면 black
	if (cnt == 0) {
		cnt = -1;
	}

	int s = v[temp].size();
	for (int i = 0; i < s; i++) {
		if (visited[v[temp][i]] == false) { //안들렸다면 방문
			int x = doDFS(v[temp][i]);
			if (x < 0) //방문한게 최댓값을 낮춘다면
				x = 0; //방문 취소
			cnt += x; //cnt : upMax
		}
	}
	upMax[temp] = cnt;
	return cnt;
}
void doDFS2(int temp,int fp) { //fp는 위에서받은거
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

	//a[v]=1이면 v는 흰색, 0이면 v는 검은색
	
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
	//교훈...출력을 여러번 해야할 때
	//dfs를 쓰는 알고리즘이면(시간소모 큼) 기록을 남겨라
	//루트가 따로 없다면 아무 노드나 루트로 잡아도된다.
}