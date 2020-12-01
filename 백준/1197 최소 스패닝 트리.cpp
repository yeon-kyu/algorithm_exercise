#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[10001];


struct line_info {
	int a, b, c;
};
vector<line_info> line;

bool compare(struct line_info X, struct line_info Y) { 
	//line_info�� c�� �������� �������� ��������
	if (X.c < Y.c) {
		return true;
	}
	else {
		return false;
	}
}

int get_parent(int x) {
	int p = parent[x];
	if (p == x) {
		return x;
	}
	else {
		return parent[x] = get_parent(p);
	}
}

void union_parent(int x, int y) {
	int X = get_parent(x);
	int Y = get_parent(y);
	if (X < Y) { //���� �ָ� �ٶ󺸰�
		parent[Y] = X;
	}
	else {
		parent[X] = Y;
	}
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;//v<=10000 E<=100000
	int A, B, C;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		
		struct line_info temp;
		temp.a = A; temp.b = B; temp.c = C;
		line.push_back(temp);
	}
	sort(line.begin(), line.end(), compare);
	
	for (int i = 1; i <= V; i++) { //parent�ʱ�ȭ
		parent[i] = i;
	}

	//ũ�罺��
	int ans = 0;
	for (int i = 0; i < E; i++) { //v���� ��尡 �����Ƿ� �׸�ŭ �ݺ�
		int a = line[i].a;
		int b = line[i].b;
		//����Ŭ üũ�� �ϸ��
		
		if (get_parent(a)==get_parent(b)) { //����Ŭ�� ���	
			continue;
		}
		else {
			union_parent(a, b); //�׷��� ����
			ans += line[i].c;
		}
	}
	cout << ans;
	
}
