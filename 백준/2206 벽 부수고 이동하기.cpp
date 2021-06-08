#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int x;
	int y;
	int broken;
	int cnt;
};

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int N, M;
char mat[1001][1001];
int dist[1001][1001][2];//������ [2] : �� �Ⱥν� ���0, �ν� ��� 1

bool canStep(int a, int b) {
	if (a >= 0 && a < N && b >= 0 && b < M) {
		return true;
	}
	return false;
}

int doBFS() {
	queue<struct Node> Q;
	Q.push({ 0,0,0,1 });
	dist[0][0][0] = 1;

	while (!Q.empty()) {
		Node curNode = Q.front();
		Q.pop();

		if (curNode.x == N - 1 && curNode.y == M - 1) {
			return curNode.cnt;
		}
		for (int i = 0; i < 4; i++) {
			int a = curNode.x + dx[i];
			int b = curNode.y + dy[i];
			int broken = curNode.broken;
			int cnt = curNode.cnt;
			if (canStep(a, b)){
				if (mat[a][b] == '0') { //������ ���� ���� step
					if (dist[a][b][broken] == -1 || dist[a][b][broken] > cnt + 1) {//�̹� �ٸ� ��ΰ� �� ���� ���� ��ŵ
						Q.push({ a, b, broken, cnt + 1 });
						dist[a][b][broken] = cnt + 1;
					}
				}
				else { //������ �ִ� ���� stop
					int A = a + dx[i];
					int B = b + dy[i];
					//���� �ϳ� �νǼ��ְ� �ٴ��� step�� ������ ����
					if (broken==0 && canStep(A, B) && mat[A][B] == '0') { 
						if (dist[a][b][broken] == -1 || dist[a][b][broken] > cnt + 2) {
							Q.push({ a, b, 1, cnt + 1 });
							dist[a][b][1] = cnt + 1;
						}
							
					}
				}
			}
		}
	}
	return -1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			mat[i][j] = str[j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dist[i][j][0] = -1;
			dist[i][j][1] = -1;
		}
	}

	cout << doBFS();


	return 0;
}