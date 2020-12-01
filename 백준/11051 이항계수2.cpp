#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
int pascal[1001][1001];

void calculate() {

	for (int i = 1; i <= N; i++) { //�ﰢ���� ���ʴ밢�� �ʱ�ȭ
		pascal[i][0] = 1;
	}
	for (int i = 1; i <= K; i++) { //�ﰢ���� �����ʴ밢�� �ʱ�ȭ
		pascal[i][i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j != 0 && j != i && j<=i) { //�������� �̿� �� dp
				pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j])%10007;
			}
		}
	}
}


int main() {

	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	
	//cin >> N >> K;
	scanf("%d %d", &N, &K);
	int num;

	if (K > N - K) { //����� ª����
		K = N - K;
	}
	calculate();
	//cout << pascal[N][K]<<endl;
	printf("%d", pascal[N][K]);
}
