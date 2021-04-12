#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
int parentNum[51];

struct Body {
	int x, y;
};
Body body[51];

bool isBigger(Body b1, Body b2) {
	if (b1.x < b2.x && b1.y < b2.y) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	cin >> N; //N¿∫ 50 ¿Ã«œ

	for (int i = 0; i < N; i++) {
		cin >> body[i].x >> body[i].y;
		parentNum[i] = 0;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				if (isBigger(body[i], body[j])) {
					parentNum[i]++;
				}
			}
		}
		cout << parentNum[i] +1  << endl;
	}

	return 0;
}