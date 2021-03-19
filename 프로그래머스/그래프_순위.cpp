#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> upNode[101];
vector<int> downNode[101];
bool visited[101] = { false };

int upCount(int pos) {
	visited[pos] = true;
	int s = upNode[pos].size();
	int res = 0;
	for (int i = 0; i < s; i++) {
		if (visited[upNode[pos][i]] == false) {
			res++;
			//cout << pos << "에서 " << upNode[pos][i] << "추가" << endl;
			res += upCount(upNode[pos][i]);
		}
	}
	return res;
}
int downCount(int pos) {
	visited[pos] = true;
	int s = downNode[pos].size();
	int res = 0;
	for (int i = 0; i < s; i++) {
		if (visited[downNode[pos][i]] == false) {
			res++;
			res += downCount(downNode[pos][i]);
		}
	}
	return res;
}

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	int size = results.size();
	for (int i = 0; i < size; i++) {
		upNode[results[i][1]].push_back(results[i][0]);
		downNode[results[i][0]].push_back(results[i][1]);
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 0; k <= n; k++) {
			visited[k] = false;
		}
		int parentCount = upCount(i);
		int childCount = downCount(i);
		
        if (parentCount + childCount == n - 1) {
			answer++;
		}
	}

	return answer;
}