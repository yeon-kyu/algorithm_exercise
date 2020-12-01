#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int n;

struct point {
	int pos;
	int power;
	int dp; //��� ���� ��
};
vector<struct point> p;

bool compare(struct point a, struct point b) {
	return a.pos < b.pos;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//n���� ����ġ
	//i��° ����ġ�� pos_i������..pos�¼��� �ٸ�
	//pow_i�� �Ŀ�
	//beacon�� ������ ��� ���ʿ��ִ� beacon�� �ı��ȴ�.
	//(�� beacon�� �Ŀ���ŭ �Ÿ�(inclusive�ϰ�))
	//������ �� beacon�� �������
	//�ּҷ� �״� beacon�� ���� ���ض�

	cin >> n;
	struct point temp;
	p.push_back(temp);
	for (int i = 1; i <= n; i++) {
		cin >> temp.pos >> temp.power;
		p.push_back(temp);
	}
	sort(p.begin(), p.end(),compare);

	p[0].dp = 0; p[0].pos = INT_MIN;
	for (int i = 1; i <= n; i++) {
	
		int bar = p[i].pos - p[i].power;
		for (int z = 1; z <= i; z++) {
			if (p[i - z].pos >= bar) {//�׾����
				//cout << "dead" << endl;
			}
			else {
				p[i].dp = p[i - z].dp + 1;
				break;
			}
		}

	}
	int min = n;
	for (int i = 1; i <= n; i++) {
		int temp; //�����ʺ��� i��°������ ����� �� ������ ��
		temp = (n - p[i].dp);
		if (temp < min) {
			min = temp;
		}
	}
	cout << min;

}