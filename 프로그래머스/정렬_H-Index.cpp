#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());
	int size = citations.size();
	
	if (size == 1) { //size�� 1���� ��� start�� �����̹Ƿ� ����ó��
		return 1;
	}
	for (int h = 0; h < 10000; h++) {
		int cnt = 0;
		for (int i = 0; i < size; i++) {
			if (citations[i] >= h) {
				cnt++;
			}
		}
		if (cnt < h) {
			return h - 1; //h���� ������ ����-> h-1�� ����
		}
	}

}

