#include <string>
#include <vector>
#include <iostream>

using namespace std;

string convertDexToBinaryString(long long n) {
	string str = "";
	while (n > 0) {
		str += to_string(n % 2);
		n = n / 2;
	}
	string newString = "";
	int size = str.size();
	for (int i = 0; i<size; i++) {
		newString += str[size - i - 1];
	}

	return newString;
}

long long convertBinaryStringToDex(string str) {
	long long dex = 0;
	long long multiple = 1;
	long long size = str.size();
	for (int i = 0; i<size; i++) {
		int n = str[size - i - 1] - '0';
		dex += (n * multiple);
		multiple *= 2;
	}
	return dex;
}

long long getFx(long long n) {
	string a = convertDexToBinaryString(n);
	string b = a;

	int size = a.size();

	bool twoFixFlag = true;
	for (int i = 0; i<size; i++) {
		if (a[size - 1 - i] == '0') {
			b[size - 1 - i] = '1';
			if (i > 0) {
				b[size - i] = '0';
			}
			twoFixFlag = false;
			break;
		}
	}
	if (twoFixFlag == true) {
		b[0] = '0';
		b = '1' + b;
	}

	return convertBinaryStringToDex(b);
}

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;

	for (auto number : numbers) {
		answer.push_back(getFx(number));
	}

	return answer;
}