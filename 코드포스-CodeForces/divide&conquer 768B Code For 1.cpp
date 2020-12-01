#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

long long n, r, l;

vector<int> digit;
int handle_pnt[51];
//void divide(int position) {
//	int temp = v[position];
//	if (temp == 1 || temp == 0) {
//		return;
//	}
//	v.erase(v.begin()+position);
//	v.insert(v.begin() + position, 3, (int)(temp / 2));
//	//v.insert(v.begin() + position, (int)(temp % 2));
//	v[position + 1] = temp % 2;
//	divide(position + 2);
//	divide(position);
//}
int get_pos(long long num) {
	int cnt = 0;
	while (1) {
		if (num == 0) {
			break;
		}
		num = num / 2;
		cnt++;
	}
	return cnt++;
}

long long get_1s(long long num) {

	if (num < 0) {
		cout << "error-num : " << num << endl;
	}

	if (num == 0) {
		return 0;
	}

	int d = digit[digit.size() - get_pos(num)];  //0�Ǵ� 1�� 2������ �ڸ��� digit
	
	long long plus = num - pow(2, get_pos(num) - 1); //num�� 7�̸� 3�� ��ȯ(7-4) ..handle_pnt������ �߰� ���ڵ�
	
	
	return handle_pnt[get_pos(num) - 1] + d + get_1s(plus); 
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//n
	//x����(x>1)�� , x/2 , x%2, x/2 ����
	//list�Ǹ�� ��Ұ� 0�Ǵ� 1�� �� ������
	// l~r������ ��� �߿� 1�� �� ����?
	cin >> n >> l >> r;
	
	if (n == 0) {
		cout << 0;
		return 0;
	}

	while (1) { //digit���� 2������ n�� ��Ʈ�� �������� �����
		if (n == 0) {
			break;
		}
		digit.push_back(n % 2);
		n = n / 2;
	}
	int s = digit.size();
	
	handle_pnt[1] = digit[s - 1];
	for (int i = 2; i <= s; i++) {
		handle_pnt[i] = 2 * handle_pnt[i - 1] + digit[s - i];
	}

	
	cout << get_1s(r) - get_1s(l - 1);
	
}
