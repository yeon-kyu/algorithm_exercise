#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int N;
int num[1001];

void swap(int a, int b) {
	int temp = num[b];
	num[b] = num[a];
	num[a] = temp;
}

void quickSort(int left, int right) {
	if (left >= right) {
		return;
	}
	int pivot = left;
	int i = left + 1;
	int j = right;
	while (true) {
		while (num[i] < num[pivot]) { 
			//i�� while�� ������ �Ǻ����� ū �ε����� ����Ű�� ��������(swap ���)
			i++;
		}
		while (num[j] > num[pivot]) {
			//j�� while�� ������ �Ǻ����� ���� �ε����� ����Ű�� ��������(swap���)
			j--;
		}
		if (i > j) {
			swap(pivot, j); //���� �� �Ǻ��� j�� �ٲپ� �ָ鼭 j�� �Ǻ��� ����Ű�� ��
			break;
		}
		swap(i, j);
	}
	quickSort(left, j-1);
	quickSort(j + 1, right);
}

void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	
	while (i <= mid && j <= right) {
		if (num[i] <= num[j]) {

		}
		else {

		}
	}
}

void mergeSort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);

		int x = left; //���� ����Ʈ �ε���
		int y = mid + 1; //������ �ε��� ����Ʈ
		int* B = new int[right - left + 1];
		for (int i = 0; i < right - left + 1; i++) {
			if (x == mid + 1) { //���� �ε��� �� �־����� ������ ����Ʈ�� �ֱ�
				B[i] = num[y++];
				continue;
			}
			if (y == right + 1) { //������ �ε��� �� �־����� ���� ����Ʈ�� �ֱ�
				B[i] = num[x++];
				continue;
			}

			//�� ����Ʈ�� �ε����� ���Ͽ� �� �����ָ� ���ο� ����Ʈ�� �ִ´�
			if (num[x] < num[y]) { 
				B[i] = num[x++];
			}
			else {
				B[i] = num[y++];
			}
		}
		for (int i = 0; i < right - left + 1; i++) { //���ο� ����Ʈ�� �ִ� ���� ������ ����Ʈ�� �߰��Ѵ�.
			num[left + i] = B[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	//quickSort(0, N - 1);
	mergeSort(0, N - 1);
	for (int i = 0; i < N; i++) {		cout << num[i] << '\n';	}}