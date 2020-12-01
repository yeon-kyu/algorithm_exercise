#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, q;
string  str;

struct node {
	int l, r; //�� �Ʒ� ���°���� ���°���� �����Ŵ�.
	int cnt; //�ڱ� �Ʒ��� a�� � �ִ�.
	int lazy; //������Ʈ��
}T[26][400000];

int pull_up(int t, int k) {
	T[t][k].cnt = T[t][2 * k].cnt + T[t][2 * k + 1].cnt;
	//�θ��� cnt = �� �ڽ��� cnt�� ��
	return 0;
}
int push_down(int t, int k) {
	int lazy = T[t][k].lazy;
	if (lazy == 0) {
		T[t][2 * k].lazy = 0; T[t][2 * k + 1].lazy = 0;
		T[t][2 * k].cnt = 0; T[t][2 * k + 1].cnt = 0;
	}
	else if (lazy == 1) {
		T[t][2 * k].lazy = 1; T[t][2 * k + 1].lazy = 1;
		T[t][2 * k].cnt = T[t][2 * k].r - T[t][2 * k].l + 1;
		T[t][2 * k + 1].cnt = T[t][2 * k + 1].r - T[t][2 * k + 1].l + 1;
	}
	T[t][k].lazy = -1;
	return 0;
}

int build(int t,int k, int left, int right) {//t�� Ʈ��(���ڿ� ����), k�� ���� ����ȣ
	T[t][k].l = left; T[t][k].r = right;
	T[t][k].lazy = -1;
	if (left == right) {
		if (str[left] - 'a' == t) {
			T[t][k].cnt = 1;
		}
		else {
			T[t][k].cnt = 0;
		}
		return 0;
	}
	int mid = (left + right) / 2;
	build(t, k * 2, left, mid);
	build(t, k * 2 + 1, mid + 1, right);
	pull_up(t, k);
	return 0;
}

int query(int t, int k, int left, int right) {
	//���ĺ��� ���� left ���� right���� ������ ����� count�ϴ°�
	if (T[t][k].l >= left && T[t][k].r <= right) {
		return T[t][k].cnt;
	}
	if (T[t][k].l > right || T[t][k].r < left) {
		return 0;
	}
	push_down(t, k); //lazy �ݿ�
	int mid = (T[t][k].l + T[t][k].r) / 2;
	int lret = query(t, k * 2, left, right);
	int rret = query(t, k * 2 + 1, left, right);
	return lret + rret;
}

int update(int t, int k, int left, int right, int V) {
	if (T[t][k].l >= left && T[t][k].r <= right) {
		T[t][k].lazy = V;
		if(V==1) T[t][k].cnt = T[t][k].r - T[t][k].l + 1;
		else T[t][k].cnt = 0;
		return 0;
	}
	if (T[t][k].l > right || T[t][k].r < left) {
		return 0;
	}
	int mid = (T[t][k].l + T[t][k].r) / 2;
	push_down(t, k); //lazy �ݿ�
	update(t, k * 2, left, right, V);
	update(t, k * 2 + 1, left, right, V);
	pull_up(t, k);
	return 0;
}


bool desc(char a, char b) {
	if (a <= b) {
		return false;
	}
	else {
		return true;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> q;
	cin >> str;

	str = "1" + str;
	for (int i = 0; i < 26; i++) { //��� ���ں��� Ʈ���� �����
		build(i, 1, 1, n);	
	}

	int l, r, k;
	int num[26];

	for (int i = 0; i < q; i++) {
		cin >> l >> r >> k;

		for (int j = 0; j < 26; j++) {
			num[j] = 0;
		}
		
		if (k == 1) { //��������

			for (int j = 0; j < 26; j++) {
				num[j] = query(j, 1, l, r);
				update(j, 1, l, r, 0);//a,b,c...�� ������� �� ���Դ�.
			}
			int left;
			left = l;
			for (int j = 0; j< 26; j++) {
				if (num[j] > 0) {
					update(j, 1, left, left + num[j] - 1,1);
					//left���� a����-1 ���� 1�� ������Ʈ�϶�
					left = left + num[j];
				}
			}


			//sort(str.begin() + l - 1, str.begin() + r);
		}
		else { //��������
			for (int j = 0; j < 26; j++) {
				num[j] = query(j, 1, l, r);
				update(j, 1, l, r, 0);//a,b,c...�� ������� �� ���Դ�.
			}
			int left, prev;
			left = l;
			for (int j = 25; j>=0; j--) {
				if (num[j] > 0) {
					update(j, 1, left, left + num[j] - 1, 1);
					//left���� a����-1 ���� 1�� ������Ʈ�϶�
					left = left + num[j];
				}
			}

			//sort(str.begin() + l - 1, str.begin() + r,desc);
		}
		//cout << str << endl;
		
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) {
			if (query(j, 1, i, i) > 0)
				putchar('a' + j);
		}
	}
	//cout << str << endl;

}