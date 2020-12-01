#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct pairs {
	int start; //이 변수로 방향성을 확인할수 있음
	int object; //가르켜지는 방향
};


int n;
//vector<int> node[200001];
//vector<int> road[200001];
vector<struct pairs> node2[200001];
bool visited[200001];
int bttmUp[200001];
int ans[200001];
int minn;

void reset_visited() {
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
}

int doDFS(int pos) {
	visited[pos] = true;
	int cnt = 0;
	int s = node2[pos].size();
	for (int i = 0; i < s; i++) {
		if (visited[node2[pos][i].object] == false) {
			//road[pos] 안에 node[pos][i]가 없다면? +1....여기 find에서 시간초과가 난것이다!!!
			/*if (find(road[pos].begin(), road[pos].end(), node[pos][i]) == road[pos].end()) {
				cnt++;
			}*/
			if (node2[pos][i].object == node2[pos][i].start) {
				cnt++;
			}
			
			cnt += doDFS(node2[pos][i].object);
		}
	}
	bttmUp[pos] = cnt;
	return cnt;
}
void doDFS2(int pos, int fromParent) {
	visited[pos] = true;
	ans[pos] = bttmUp[pos] + fromParent;
	
	int s = node2[pos].size();
	for (int i = 0; i < s; i++) {
		if (visited[node2[pos][i].object] == false) {
			int flag;
			/*if (find(road[pos].begin(), road[pos].end(), node[pos][i]) == road[pos].end()) {
				flag = -1;
			}*/
			if (node2[pos][i].object == node2[pos][i].start) {
				flag = -1;
			}
			else {//부모->자식 가는 길이 있었을 때
				flag = 1;
			}
			doDFS2(node2[pos][i].object, ans[pos] - bttmUp[node2[pos][i].object] + flag);
		}
	}
	if (ans[pos] < minn) {
		minn = ans[pos];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//n개의 도시, n-1개의 도로
	//수도를 정할것임

	//수도에서 다른 도시로 가는것만 중요함
	//inverse되야하는 최소 도로의 수, 
	//수도로 적합한 것들 출력

	cin >> n;
	struct pairs temp;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		/*road[a].push_back(b);
		node[a].push_back(b);
		node[b].push_back(a);*/

		temp.start = a;
		temp.object = b;

		node2[a].push_back(temp);
		temp.object = a;
		node2[b].push_back(temp);
	}
	
	minn = n;
	reset_visited();
	doDFS(1);
	reset_visited();
	doDFS2(1, 0);
	cout << minn << endl;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == minn)
			cout << i << ' ';
	}
}

