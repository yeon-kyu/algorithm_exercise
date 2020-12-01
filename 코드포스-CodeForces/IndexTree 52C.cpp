#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


struct node {
	int l, r;//아래 노드에 l부터 r 까지 있다.
	int mini; //아래 노드중 가장 작은애
	long long incre;//아래 노드들에 더해줘야하는 값
} T[2000000];

long long a[200001];
int n, m;

long long build(long long k, long long L, long long R) {
	T[k].l = L; T[k].r = R;
	T[k].incre = 0;
	if (L == R) { //leaf라는 뜻
		T[k].mini = a[L]; 
		return 0; 
	}
	long long mid = (L + R) / 2;
	build(k * 2, L, mid); //왼쪽 자식노드 build
	build(k * 2 + 1, mid + 1, R);  //오른쪽 자식 노드 build
	T[k].mini = min(T[k * 2].mini + T[k * 2].incre, T[k * 2 + 1].mini + T[k * 2].incre);
	return 0;
}
long long query(long long k, int L, int R) {
	long long mid;
	if (T[k].l >= L && T[k].r <= R) {
		return T[k].mini + T[k].incre;
	}
	if (T[k].l > R || T[k].r < L) {
		return 500000000000000;
	}
	mid = (T[k].l + T[k].r) / 2;
	long long lret = query(k * 2, L, R);
	long long rret = query(k * 2 + 1, L, R);
	return min(lret, rret) + T[k].incre;
}
long long increment(long long k, int L, int R, int V) {
	long long mid;
	if (T[k].l >= L && T[k].r <= R) {
		T[k].incre += V;
		return 0;
	}
	if (T[k].l > R || T[k].r < L) {
		return 0;
	}
	mid = (T[k].l + T[k].r) / 2;
	increment(k * 2, L, R, V);
	increment(k * 2 + 1, L, R, V);
	T[k].mini = min(T[k * 2].mini + T[k * 2].incre, T[k * 2 + 1].mini + T[k * 2 + 1].incre);
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	cin >> m;
	//cout << "m : " << m << endl;
	string str;
	getline(cin, str); // \n 버퍼 하나 지워줘야함
	for (int i = 1; i <= m; i++) {
		getline(cin, str);
		//cout << "str : " << str << endl;
		stringstream ss(str);
		int arg[3];
		string temp;

		int cnt = 0;
		while (ss >> temp) {
			arg[cnt] = stoi(temp)+1;
			cnt++;
		}
		if (cnt == 3) { //inc
			////cout << "i:" << i << " " << arg[0] + arg[1] +arg[2] << endl;
			//int pos = arg[0];
			////cout << "arg[2] : " << arg[2] << endl;
			//while (true) {
			//	int rpos = pos % n;
			//	a[rpos] += arg[2];
			//	if (pos%n == arg[1]) 
			//		break;
			//	
			//	pos++;
			//}
			arg[2]--;
			if (arg[0] <= arg[1]) { //L<=R
				//cout << arg[0] << "부터" << arg[1] << "까지" << arg[2] << "만큼" << endl;
				increment(1, arg[0], arg[1], arg[2]);
			}
			else { //L>R
				//cout << "1부터" << arg[1] << "까지" <<arg[0]<<"부터"<<n<<"까지"<< arg[2] << "만큼" << endl;
				increment(1, 1, arg[1], arg[2]);
				increment(1, arg[0], n, arg[2]);
			}
		}
		else { //rmq
			////cout << "i:" << i << " " << arg[0] + arg[1] << endl;
			//int pos = arg[0]; //3
			//int min = a[pos]; //4
			////cout << "최초 pos : " << pos << endl;
			////cout << "최초 min : " << min << endl;
			//while (true) {
			//	if (min > a[pos%n]) {
			//		min = a[pos%n];
			//	}
			//	if (pos%n == arg[1])//0
			//		break;
			//	pos++;
			//}
			//cout << min << endl;
			if (arg[0] <= arg[1]) {//L<=R
				//cout << arg[0] << " 부터 " << arg[1] << " 까지" << endl;
				cout<<query(1, arg[0], arg[1])<<'\n';
			}
			else { //L>R
				int a = query(1, 1, arg[1]);
				int b = query(1, arg[0], n);
				//cout << "1부터 " << arg[1] << " 까지 " << arg[0] << " 부터 " << n << "까지" << endl;
				cout << min(a, b)<<'\n';
			}
		}
	}

	

}