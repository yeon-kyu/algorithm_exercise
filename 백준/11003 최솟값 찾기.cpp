#include <iostream>
#include <queue>

using namespace std;

int A[5000000];
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	
	int start;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		start = i - L + 1;
		pq.push(make_pair(A[i], i));
		while (pq.top().second < start) {
			pq.pop();
		}
		cout << pq.top().first << ' ';
	}
	
}
