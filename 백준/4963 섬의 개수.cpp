#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int parent[2501];
int map[2501];

int find_parent(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = find_parent(parent[x]);
	}
}

void union_parent(int a, int b) {
	int A = find_parent(a);
	int B = find_parent(b);
	if (A < B) { //작은쪽에게 바라보도록
		parent[B] = A;
	}
	else {
		parent[A] = B;
	}
}

void seek_around(int x, int w, int end) {
	vector<int> seek;
	vector<int>::iterator it;
	for (int i = 1; i < 9; i++) { //1번~8번까지의 방향을 나타냄
		seek.push_back(i);
		//123
		//4 5
		//678
	}

	//맨윗줄일경우
	if (x <= w) {
		it = find(seek.begin(), seek.end(), 1);
		if (it != seek.end()) {
			seek.erase(it);
		}
		it = find(seek.begin(), seek.end(), 2);
		if (it != seek.end()) {
			seek.erase(it);
		}
		it = find(seek.begin(), seek.end(), 3);
		if (it != seek.end()) {
			seek.erase(it);
		}

	}
	//맨아랫줄
	if (x >= end - w) {
		it = find(seek.begin(), seek.end(), 6);
		if (it != seek.end()) {
			seek.erase(it);
		}
		it = find(seek.begin(), seek.end(), 7);
		if (it != seek.end()) {
			seek.erase(it);
		}
		it = find(seek.begin(), seek.end(), 8);
		if (it != seek.end()) {
			seek.erase(it);
		}
	}
	//맨왼쪽줄
	if ((x - 1) % w == 0) {
		it = find(seek.begin(), seek.end(), 1);
		if (it != seek.end()) {
			seek.erase(it);
		}
		it = find(seek.begin(), seek.end(), 4);
		if (it != seek.end()) {
			seek.erase(it);
		}
		it = find(seek.begin(), seek.end(), 6);
		if (it != seek.end()) {
			seek.erase(it);
		}
	}
	//맨오른쪽줄
	if (x%w == 0) {
		it = find(seek.begin(), seek.end(), 3);
		if (it != seek.end()) {
			seek.erase(it);
		}
		it = find(seek.begin(), seek.end(), 5);
		if (it != seek.end()) {
			seek.erase(it);
		}
		it = find(seek.begin(), seek.end(), 8);
		if (it != seek.end()) {
			seek.erase(it);
		}
	}

	int size = seek.size();
	for (int i = 0; i < size; i++) {
		int dir = seek[i];
		if (dir == 1) {//좌상
			if (map[x - w - 1] == 1) {
				union_parent(x - w - 1, x);
			}
		}
		else if (dir == 2) {
			if (map[x - w])
				union_parent(x - w, x);
		}
		else if (dir == 3) {
			if (map[x - w + 1]) {
				union_parent(x - w + 1, x);
			}
		}
		else if (dir == 4) {
			if (map[x - 1]) {
				union_parent(x - 1, x);
			}
		}
		else if (dir == 5) {
			if (map[x + 1]) {
				union_parent(x + 1, x);
			}
		}
		else if (dir == 6) {
			if (map[x + w - 1])
				union_parent(x + w - 1, x);
		}
		else if (dir == 7) {
			if (map[x + w])
				union_parent(x + w, x);
		}
		else if (dir == 8) {
			if (map[x + w + 1])
				union_parent(x + w + 1, x);parent[x + w + 1] = x;
		}

	}
}

int main() {
	int w, h;
	for (int i = 1; i < 2501; i++) { //parent 초기화
		parent[i] = i;
	}

	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		int end = w * h + 1;


		for (int i = 1; i < end; i++) { //input
			cin >> map[i];
		}

		for (int i = 1; i < end; i++) {
			if (map[i] != 0) {
				seek_around(i, w, end); //주변에 인접노드 확인 및 합치기
			}
		}

		vector<int> num;
		for (int i = 1; i < end; i++) {
			vector<int>::iterator it;
			int p = find_parent(i);
			it = find(num.begin(), num.end(), p);
			if (it == num.end() && map[i] == 1) {//해당parent가 없으면
				num.push_back(p);
			}

		}
		cout << num.size() << endl;

		for (int i = 1; i < end; i++) { //다음을 위한 초기화
			map[i] = 0;
			parent[i] = i;
		}
	}
}
