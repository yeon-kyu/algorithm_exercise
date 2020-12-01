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

	int d = digit[digit.size() - get_pos(num)];  //0또는 1의 2지수승 자리의 digit
	
	long long plus = num - pow(2, get_pos(num) - 1); //num이 7이면 3를 반환(7-4) ..handle_pnt이후의 추가 숫자들
	
	
	return handle_pnt[get_pos(num) - 1] + d + get_1s(plus); 
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//n
	//x삭제(x>1)후 , x/2 , x%2, x/2 넣음
	//list의모든 요소가 0또는 1이 될 때까지
	// l~r까지의 요쇼 중에 1의 총 갯수?
	cin >> n >> l >> r;
	
	if (n == 0) {
		cout << 0;
		return 0;
	}

	while (1) { //digit에는 2진법의 n의 비트가 역순으로 저장됨
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
