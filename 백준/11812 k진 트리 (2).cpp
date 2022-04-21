#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

long long N;
int K, Q;
vector<int> node[1000];

vector<long long> getParents(long long a) {
	vector<long long> v;

	while (a >= 1) {
		v.push_back(a);
		a = (long long)(a + K - 2) / K;
	}
	reverse(v.begin(), v.end());

	return v;
}

long long getDistance(long long x, long long y) {
	if (K == 1) {
		long long diff = x - y;
		if (diff < 0) {
			diff = -diff;
		}
		return diff;
	}

	vector<long long> v1 = getParents(x);
	vector<long long> v2 = getParents(y);

	int end = min(v1.size(), v2.size());
	int diffPosition = end;

	for (int i = 0; i < end; i++) {
		if (v1[i] != v2[i]) {
			diffPosition = i;
			break;
		}
	}

	int fromV1 = v1.size() - diffPosition;
	int fromV2 = v2.size() - diffPosition;

	return fromV1 + fromV2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> Q;

	for (int i = 0; i < Q; i++) {
		long long x, y;
		cin >> x >> y;

		cout << getDistance(x, y) << '\n';
	}
}