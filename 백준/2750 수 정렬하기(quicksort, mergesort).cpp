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
			//i는 while이 끝나면 피봇보다 큰 인덱스를 가리키고 있을것임(swap 대상)
			i++;
		}
		while (num[j] > num[pivot]) {
			//j는 while이 끝나면 피봇보다 작은 인덱스를 가리키고 있을것임(swap대상)
			j--;
		}
		if (i > j) {
			swap(pivot, j); //끝날 땐 피봇과 j를 바꾸어 주면서 j가 피봇을 가리키게 함
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

		int x = left; //왼쪽 리스트 인덱스
		int y = mid + 1; //오른쪽 인덱스 리스트
		int* B = new int[right - left + 1];
		for (int i = 0; i < right - left + 1; i++) {
			if (x == mid + 1) { //왼쪽 인덱스 다 넣었으면 오른쪽 리스트만 넣기
				B[i] = num[y++];
				continue;
			}
			if (y == right + 1) { //오른쪽 인덱스 다 넣었으면 왼쪽 리스트만 넣기
				B[i] = num[x++];
				continue;
			}

			//두 리스트의 인덱스를 비교하여 더 작은애를 새로운 리스트에 넣는다
			if (num[x] < num[y]) { 
				B[i] = num[x++];
			}
			else {
				B[i] = num[y++];
			}
		}
		for (int i = 0; i < right - left + 1; i++) { //새로운 리스트에 있는 값을 원래의 리스트에 추가한다.
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