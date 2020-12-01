#include <iostream>
#include <string>
#include <map>

using namespace std;


map<string, int> m;
int parent[200001];

int findParent(int temp) {
	int p = parent[temp];
	if (p == temp) {
		return temp;
	}
	else {
		return parent[temp] = findParent(p);
	}
}

void unionParent(int a, int b) {
	int parentA = findParent(a); //a의 최종 부모
	int parentB = findParent(b);

	if (parentA < parentB) {
		parent[parentB] = parentA; //b최종 부모의 부모를 a 의 최종 부모로 설정
	}
	else {
		parent[parentA] = parentB;
	}
}

void printFriends(int a, int cnt) {
	int temp = findParent(a);
	int ans = 0;
	for (int i = 1; i <= cnt; i++) {
		if (findParent(i) == temp) {
			ans++;
		}
		//cout << findParent(i) << endl;
	}
	cout << ans << " ";
	//printf("%d\n", ans);
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int test_n, F;
	cin >> test_n;
	//scanf("%d", &test_n);

	for (int i = 0; i < test_n; i++) {
		cin >> F;
		//scanf("%d", &F);
		m.clear();
		for (int j = 0; j < 2 * F + 1; j++) {
			parent[j] = j;
		}

		int cnt = 1;
		for (int j = 0; j < F; j++) {
			string A, B;
			cin >> A >> B;
			//char A[21]; char B[21];
			//scanf("%s", A); scanf("%s", B);

			if (m.find(A) == m.end()) { //A가 새로운 이름인경우
				m.insert(make_pair(A, cnt));
				cnt++;
			}
			if (m.find(B) == m.end()) {
				m.insert(make_pair(B, cnt));
				cnt++;
			}
			unionParent(m[A], m[B]);

			printFriends(m[A], cnt - 1);
		}

	}
}