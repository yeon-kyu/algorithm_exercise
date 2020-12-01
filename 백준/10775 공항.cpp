#include <iostream>

using namespace std;

int parent[100001] = { 0 };



int find_parent(int temp) {
	if (parent[temp] < 1) { //도킹 불가능한 조건
		return -1;
	}
	if (temp == parent[temp]) { //temp노드가 아직 도킹되지않은 게이트인 경우 
		parent[temp] = parent[temp] - 1; //이전 노드를 가리키게함
		return parent[temp];
	}
	else {
		return parent[temp] = find_parent(parent[temp]);
		//find_parent()함수를 재귀호출함. 
		//find_parent의 결과값과 현재 temp가 가리키는 parent는 같은 노드를 바라보게함(시간 단축)
	}
}

int main() {
	int P, G;
	cin >> G >> P;
	int cnt = 0;
	int x;
	int result = 0;

	for (int i = 0; i <= G; i++) {
		parent[i] = i; //초기화
	}

	for (int i = 0; i < P; i++) {
		cin >> x;

		if (find_parent(x) < 0) {
			break;
		}
		cnt++;
	}


	cout << cnt << endl;

}