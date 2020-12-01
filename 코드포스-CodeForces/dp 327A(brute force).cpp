#include <iostream>
#include <algorithm>
#include <vector>

int n;
int a[101];
int cnt = 0;

using namespace std;

int check_i(int i) {
	int j;
	int max = -100;
	for (int j = i; j <= n; j++) {
		int plus = 0;
		for (int k = i; k <= j; k++) {
			if (a[k] == 1) {
				plus--;
			}
			else {
				plus++;
			}
		}
		if (plus > max) {
			max = plus;
		}
	}
	return max;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//a[n] ..�� element�� 0�Ǵ� 1 n<=100
	//i�� j�� ���(1<=i<=j<=n) �� ���� ������ a[k]�����´�
	//(i<=k<=j)
	
	cin >> n;
	bool flag= false;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			cnt++;
		}
		else {
			flag = true; //��� 1�ΰ�� i��j�� ���ԵǸ� -1�ؾ���
		}
	}
	if (flag == false) { //0�� �ϳ����ȳ��� ���
		cnt--;
	}


	int max = 0;
	int temp;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			temp = check_i(i);
			if (max < temp) {
				max = temp;
			}
		}
	}
	cout << cnt + max;
	
}
