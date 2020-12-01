#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct vertex {
	int dest;
	int w;
};


vector<struct vertex> v[51];

bool visited[51] = { false };
int D[51];
int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	struct vertex temp;
	int size = road.size();
	for (int i = 0; i<size; i++) {
		temp.dest = road[i][0];
		temp.w = road[i][2];
		v[road[i][1]].push_back(temp);
		temp.dest = road[i][1];
		v[road[i][0]].push_back(temp);
	}

	for (int i = 1; i <= N; i++) {
		D[i] = 500001;
	}
	D[1] = 0;

	vector<int> Q;
	Q.push_back(1);
	while (!Q.empty()) {

		int mini = Q[0];  //확정되지 않은 노드 중 가장 가까운것
		for (int i = 0; i < Q.size(); i++) {
			if (D[Q[i]] < D[mini]) mini = Q[i];
		}
		int temp = mini;
		visited[temp] = true;
		
		Q.erase(find(Q.begin(),Q.end(),mini));
		//cout << temp << "는 : " << D[temp] << "로 확정되었다" << endl;

		int s = v[temp].size();
		for (int i = 0; i < s; i++) {
			if (visited[v[temp][i].dest] == false) {
				D[v[temp][i].dest] = min(D[v[temp][i].dest], D[temp] + v[temp][i].w);
				//cout << "D[" << v[temp][i].dest << "] : " << D[v[temp][i].dest] << endl;
				
				if (find(Q.begin(), Q.end(), v[temp][i].dest) == Q.end()) {
					//cout << "pushing <"<<v[temp][i].dest<<'>';
					Q.push_back(v[temp][i].dest);
				}
			

			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (D[i] <= K) answer++;
	}
	

	return answer;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
}