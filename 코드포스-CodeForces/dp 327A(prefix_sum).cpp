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
		plus =a[n]+j-i+1-2*(a[j] - a[i-1]); //prefix-sum으로 중간의 몇개의 1이 있었는지 파악가능
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

	//a[n] ..각 element는 0또는 1 n<=100
	//i와 j를 골라(1<=i<=j<=n) 그 범위 사이의 a[k]뒤집는다
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
			flag = true; //모두 1인경우 i와j가 같게되며 -1해야함
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
