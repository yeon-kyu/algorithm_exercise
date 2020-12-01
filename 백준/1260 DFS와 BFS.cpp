#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, v_num;
int** matrix;
vector<int> vec;
vector<int> vec2;
queue<int> Q;
int check_dupl(int i, vector<int> vec) { //return�� 0�̸� ���������ʴ°�
	vector<int>::iterator it; // vec�� i�� ���ԵǾ������� ����ϰ� ��������
	for (it = vec.begin(); it < vec.end(); it++) {
		if (*it == i)
			return 1;
	}
	return 0;
}
vector<int> remove(vector<int> vec, int value) {
	for (vector<int>::iterator it = vec.begin(); it < vec.end(); it++) {
		//cout << "*it : " << *it << endl;
		if (*it == value) {
			vec.erase(it);
			return vec;
		}
	}
	cout << "��ã��" << endl;
}
void doDFS(int v) {
	//cout << "���� �������� ��� : " << v << endl;
	for (int i = 0; i < n; i++) {
		if (matrix[v][i] == 1 && check_dupl(i + 1, vec)) {//i+1�� ����ص� �Ǵ°��
			cout << i + 1 << " ";
			vec = remove(vec, i + 1);
			if (!vec.empty()) {
				doDFS(i);
			}
		}
	}

}
void doBFS(int v) {
	Q.push(v);
	vec2 = remove(vec2, v);

	while (!Q.empty()) {
		int temp = Q.front();
		cout << temp << " ";
		Q.pop();
		for (int i = 0; i < n; i++) {
			if (matrix[temp - 1][i] == 1 && check_dupl(i + 1, vec2)) {
				Q.push(i + 1);
				vec2 = remove(vec2, i + 1);
			}
		}
	}
}

int main() {

	cin >> n >> m >> v_num;

	matrix = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 0;
		}
	}

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		//cout << "x : " << x << ", y : " << y << endl;
		matrix[x - 1][y - 1] = 1;
		matrix[y - 1][x - 1] = 1;
	}

	/*for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	cout << matrix[i][j]<<" ";
	}
	cout << endl;
	}*/

	for (int i = 0; i < n; i++) {
		vec.push_back(i + 1);
		vec2.push_back(i + 1);
	}

	cout << v_num << " ";
	vec = remove(vec, v_num);
	doDFS(v_num - 1);

	cout << endl;

	//cout << v_num << " ";
	//vec2 = remove(vec2, v_num);
	doBFS(v_num);

}