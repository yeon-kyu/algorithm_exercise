#include <iostream>
#include <algorithm>
#include <vector>

int n;
int a[101];

using namespace std;

int check_i(int i) {
	int j;
	int max = -100;
	for (int j = i; j <= n; j++) {
		int plus;
		plus =a[n]+j-i+1-2*(a[j] - a[i-1]); //prefix-sum���� �߰��� ��� 1�� �־����� �ľǰ���
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
	int temp;
	bool flag= false;
	a[0] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		if (temp == 1) {
			a[i] = a[i-1] + 1;
		}
		else {
			a[i] = a[i - 1];
			flag = true; //��� 1�ΰ�� i��j�� ���ԵǸ� -1�ؾ���
		}
	}

	int max = 0;

	for (int i = 1; i <= n; i++) {
		temp = check_i(i);
		if (max < temp) {
			max = temp;
		}
		
	}
	cout << max;
	
}
