#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int N;
int weight[501];
int time[501];
vector<int> building[501];
bool visited[501];

int getTime(int pos) {
	int size = building[pos].size();
	
	if (size == 0) {
		return weight[pos];
	}
	if (time[pos] == 0) {
		int maxi = 0;
		for (int i = 0; i < size; i++) {
			int temp = getTime(building[pos][i]);
			if (temp > maxi) {
				maxi = temp;
			}
		}
		time[pos] = weight[pos] + maxi;
	}
	
	return time[pos];

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;


	for (int i = 1; i <= N; i++) {
		visited[i] = false;
		time[i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		cin >> weight[i];

		int temp;
		while (true) {
			cin >> temp;
			if (temp == -1) {
				break;
			}

			building[i].push_back(temp);
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << getTime(i) << '\n';
	}

	return 0;
}