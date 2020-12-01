#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n;
int a[100001];
int b[100001];
int len[100001];
int len2[100001];
int temp[100001];
vector<int> last;
vector<int> last2;
int ans[100001];
int cnt[100001];
int start, end;
void LIS() {
	vector<int>::iterator it;
	last.push_back(-100);
	for (int i = 1; i <= n; i++) {
		if (last.back() < a[i])
			last.push_back(a[i]);

		it = lower_bound(last.begin(), last.end(), a[i]);
		//lower_bound : ���ĵǾ� �ִٴ� ���� �Ͽ� value�̻��� ���� ������ iterator ��ȯ
		*it = a[i];
		len[i] = it - last.begin();
	}
}

void D_LIS() {
	vector<int>::iterator it;
	last2.push_back(-100);
	for (int i = 1; i <= n; i++) {
		if (last2.back() < b[i])
			last2.push_back(b[i]);

		it = lower_bound(last2.begin(), last2.end(), b[i]);
		//lower_bound : ���ĵǾ� �ִٴ� ���� �Ͽ� value�̻��� ���� ������ iterator ��ȯ
		*it = b[i];
		temp[i] = it - last2.begin();
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//�� �׷����� ��������
	//1. lis�� ������ �ʴ� �׷�
	//2. �ּ� �ϳ��� lis���� �������� ��� lis���� ������ �ʴ� �׷�
	//3. ��� lis�� ���ϴ� �׷�

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		ans[i] = 1;
	}

	LIS();
	int LEN = 0;
	for (int i = 1; i <= n; i++) {
		LEN = max(LEN, len[i]);
	}
	for (int i = 1; i <= n; i++) {
		b[n - i + 1] = 100000-a[i];
	}
	D_LIS();
	for (int i = 1; i <= n; i++) {
		len2[n - i + 1] = temp[i];
	}
	for (int i = 1; i <= n; i++) {
		if (len[i] + len2[i] == LEN + 1)
			ans[i] = 3;
	}
	
	
	//map<int,int> dup;
	//int before = -1;
	//for (int i = 1; i <= n; i++) {
	//	if (ans[i] != 1) {
	//		if (len[i] != before) {
	//			before = len[i];
	//		}
	//		else {
	//			dup.insert(make_pair(len[i], 1));
	//		}
	//	}
	//}
	//map<int, int>::iterator it = dup.begin();
	///*for (; it != dup.end();it++) {
	//	cout << it->first;
	//}*/
	//for (int i = 1; i <= n; i++) {
	//	if (ans[i] != 1) {
	//		bool flag = false;
	//		for (auto it = dup.begin(); it != dup.end(); it++) {
	//			if (len[i] == it->first)
	//				flag = true;
	//		}

	//		if (flag) {
	//			ans[i] = 2;
	//		}
	//	}
	//}

	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i] != 1) {
			if (a[i] <= maxi) ans[i] = 2;
			maxi = max(maxi, a[i]);
		}
	}
	int mini = 100001;
	for (int i = n; i >= 1; i--) {
		if (ans[i] != 1) {
			if (a[i] >= mini) ans[i] = 2;
			mini = min(mini, a[i]);
		}
	}


	for (int i = 1; i <= n; i++) {
		cout << ans[i];
	}
}