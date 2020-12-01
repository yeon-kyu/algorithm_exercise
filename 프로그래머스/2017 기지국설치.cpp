#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stations, int w)
{

	int answer = 0;
	int wid = 2 * w + 1;
	int s = stations.size();
	
	//첫 기지국 나오기 전까지의 추가할 기지국 개수
	int start_gap = stations[0] - (w + 1);
	if (start_gap > 0) {
		answer += (start_gap-1) / wid + 1;
	}

	//기지국들 사이에 추가할 기지국 개수
	for (int i = 1; i < s; i++) {
		int prev_last = stations[i - 1] + w;
		int next_first = stations[i] - w;
		if (prev_last + 1 < next_first) {
			int mid_gap = next_first - prev_last - 1;
			answer += (mid_gap-1) / wid + 1;
		}
	}

	//마지막에 추가할 기지국 개수
	int end_gap = n - (stations[s - 1] + w);
	if (end_gap > 0) {
		answer += (end_gap-1) / wid + 1;
	}

	return answer;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> v; v.push_back(9);// v.push_back(11);
	cout<<solution(16,v, 2);
	
	//16, [9], 2
}