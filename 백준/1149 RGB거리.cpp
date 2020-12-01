#include <iostream>

using namespace std;
int get_min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}
int get_min(int a, int b, int c) {
	int temp;
	if (a < b) {
		temp = a;
	}
	else {
		temp = b;
	}
	if (c < temp) {
		temp = c;
	}
	return temp;

}
int main() {
	int n;
	cin >> n;

	int** d;

	d = new int*[n];
	for (int i = 0; i < n; i++) {
		d[i] = new int[3];
	}

	/*for (int i = 0; i < n; i++) {
	for (int j = 0; j < 3; j++) {
	d[i][j] =
	}
	d[i] = new int[3];
	}*/

	/*d = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
	d[i] = (int*)malloc(sizeof(int)*n);
	}*/



	/*for (int i = 0; i < n; i++) {
	d[i] = new int[3];
	}*/
	/*for (int i = 0; i < n; i++) {
	*d = new int[1000];
	}*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> d[i][j];
		}
	}


	int min[3]; int temp[3];
	temp[0] = d[0][0];
	temp[1] = d[0][1];
	temp[2] = d[0][2];
	//cout <<"min"<< min[0] << " " << min[1] << " " << min[2] << endl;
	for (int i = 1; i < n; i++) {
		min[0] = get_min(temp[1] + d[i][0], temp[2] + d[i][0]);
		min[1] = get_min(temp[0] + d[i][1], temp[2] + d[i][1]);
		min[2] = get_min(temp[0] + d[i][2], temp[1] + d[i][2]);
		for (int j = 0; j < 3; j++) {
			temp[j] = min[j];
		}
	}
	//cout << min[0] << " " << min[1] << " " << min[2] << endl;
	cout << get_min(min[0], min[1], min[2]) << endl;


	/*for (int i = 0; i < n; i++) {
	cout << d[i][0] << " " << d[i][1]<<" " << d[i][2] << endl;
	}*/
}