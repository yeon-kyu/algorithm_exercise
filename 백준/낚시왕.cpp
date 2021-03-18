#include <string>
#include <vector>
#include <iostream>
using namespace std;

int matrix[101][101] = { -1 };

struct Shark {
	int r, c, s, d, z;
};

vector<Shark> sharks;

int main() {
	
	int answer = 0;
	int R, C, M;
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		Shark temp;
		cin >> temp.r >> temp.c >> temp.s >> temp.d >> temp.z;
		sharks.push_back(temp);
	}

	int pos = 0;

	for (int i = 0; i < C; i++) {
		pos++;

		int size = sharks.size();

		//����
		int minRow = R + 1;
		int deletedPosition = size;
		for (int k = 0; k < size; k++) { //���� ���ò��� ��ġ���� ���� ����� ��� ã��
			Shark temp = sharks[k];
			if (temp.z == 0) {
				continue;
			}
			if (temp.c == pos) {
				if (minRow > temp.r) {
					minRow = temp.r;
					deletedPosition = k;
				}
			}
		}
		if (minRow != (R + 1)) { //��� ����
			answer += sharks[deletedPosition].z;
			sharks[deletedPosition].z = 0;
		}

		//��� �ʱ�ȭ
		for (int a = 1; a <= R; a++) {
			for (int b = 1; b <= C; b++) {
				matrix[a][b] = -1;
			}
		}


		//��� �̵�
		for (int k = 0; k < size; k++) {
			Shark temp = sharks[k];

			//matrix[temp.r][temp.c] = 0;
			if (temp.z == 0) {
				continue;
			}

			if (temp.d == 1) {
				temp.r = temp.r - temp.s;
				while (temp.r <= 0 || temp.r > R) {
					if (temp.r > R) {
						temp.r = R - (temp.r - R);
					}
					else {
						temp.r = 1 + 1 - temp.r;
					}
					if (temp.d == 2)
						temp.d = 1;
					else
						temp.d = 2;
				}
			}
			else if (temp.d == 2) {
				temp.r = temp.r + temp.s;
				while (temp.r <= 0 || temp.r > R) {
					if (temp.r > R) {
						temp.r = R - (temp.r - R);
					}
					else {
						temp.r = 1 + 1 - temp.r;
					}
					if (temp.d == 2)
						temp.d = 1;
					else
						temp.d = 2;
				}

			}
			else if (temp.d == 3) {
				temp.c = temp.c + temp.s;
				while (temp.c <= 0 || temp.c > C) {
					if (temp.c > C) {
						temp.c = C - (temp.c - C);
					}
					else {
						temp.c = 1 + 1 - temp.c;
					}
					if (temp.d == 3)
						temp.d = 4;
					else
						temp.d = 3;
				}
			}
			else if (temp.d == 4) {
				temp.c = temp.c - temp.s;
				while (temp.c <= 0 || temp.c > C) {
					if (temp.c > C) {
						temp.c = C - (temp.c - C);
					}
					else {
						temp.c = 1 + 1 - temp.c;
					}
					if (temp.d == 3)
						temp.d = 4;
					else
						temp.d = 3;
				}
			}
			sharks[k] = temp;
			//cout <<k<<"��ġ : "<< temp.r << ' ' << temp.c<<", ���� : "<<temp.d << endl;

		}

		// ��� �ο�
		for (int k = 0; k < size; k++) {
			Shark temp = sharks[k];
			if (temp.z == 0) {
				continue;
			}
			//cout << matrix[temp.r][temp.c] << endl;
			if (matrix[temp.r][temp.c] != -1) { //���� �߻�
				Shark compete = sharks[matrix[temp.r][temp.c]]; //������ ���
				if (compete.z > temp.z) { //������ �� �̱�
					sharks[k].z = 0;

				}
				else { //k��° �� �̱�
					sharks[matrix[temp.r][temp.c]].z = 0; //z�� 0�̸� ������
					matrix[temp.r][temp.c] = k;
				}
			}
			else { //���� ����
				matrix[temp.r][temp.c] = k; //k��° �� �ڸ��� ����
			}
		}



	}
	cout << answer;
}