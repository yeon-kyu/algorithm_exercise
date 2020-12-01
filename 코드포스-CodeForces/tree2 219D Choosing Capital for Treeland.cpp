#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct pairs {
	int start; //�� ������ ���⼺�� Ȯ���Ҽ� ����
	int object; //���������� ����
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
			//road[pos] �ȿ� node[pos][i]�� ���ٸ�? +1....���� find���� �ð��ʰ��� �����̴�!!!
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
			else {//�θ�->�ڽ� ���� ���� �־��� ��
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

	//n���� ����, n-1���� ����
	//������ ���Ұ���

	//�������� �ٸ� ���÷� ���°͸� �߿���
	//inverse�Ǿ��ϴ� �ּ� ������ ��, 
	//������ ������ �͵� ���

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

