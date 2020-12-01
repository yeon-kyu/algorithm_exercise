#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m, k;
struct node {
	int dest;
	int dist;
};
vector<node> A[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	int u, v, l;
	struct node temp;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> l;
		temp.dest = v;
		temp.dist = l;
		A[u].push_back(temp);
		temp.dest = u;
		A[v].push_back(temp);
	}
	set<int> s;
	set<int>::iterator it;
	for (int i = 1; i <= k; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}

	int ans = 1000000001;
	for (auto it = s.begin(); it != s.end();it++) {
		
		int size = A[*it].size();
		for (int j = 0; j < size; j++) {
			if (A[*it][j].dist < ans) {
				
				if (s.find(A[*it][j].dest)==s.end()) {
					ans = A[*it][j].dist;
				}
				
			}
		}
	}
	if (ans == 1000000001) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	

}