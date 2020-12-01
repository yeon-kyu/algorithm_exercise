#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int choose_direction(string name) {
	int left = 0;
	int right = 0;
	int size = name.size();
	for (int i = 1; i < size; i++) {//좌->우
		if (name[i] == 'A') {
			right++;
		}
		else {
			break;
		}
	}
	cout << "right : " << right << endl;
	for (int i = size - 1; i >= 0; i--) {//우->좌
		if (name[i] == 'A') {
			left++;
		}
		else {
			break;
		}
	}
	cout << "left : " << left << endl;
	if (right > left) { //역방향(우->좌)
		return 0-right;
	}
	else { //정방향(좌->우)
		return left;
	}
}

int get_distance(char x) {
	int distance = x - 'A';
	if (distance > 13) { //역방향인경우(z부터 세는게 가까움)
		distance = 'Z' - x + 1;
	}
	return distance;
}
int check_turn_left(string name,int index) {
	int right = 0;
	int left = index;
	for (int i = index + 1; i < name.size(); i++) {
		if (name[i] == 'A') {
			right++;
		}
		else {
			break;
		}
	}
	for (int i = name.size() - 1; i > index; i--) {
		if (name[i] == 'A') {
			left++;
		}
		else {
			break;
		}
	}
	if (right > left) { //회전해야한다
		return right;
	}
	else {
		return -1;
	}
}
int check_turn_right(string name,int index) {
	int left = 0;
	int right = name.size()-index;
	for (int i = index - 1; i >= 0; i--) {
		if (name[i] == 'A') {
			left++;
		}
		else {
			break;
		}
	}
	for (int i = 0; i < index; i++) {
		if (name[i] == 'A') {
			right++;
		}
		else {
			break;
		}
	}
	if (right < left) { //회전해야한다
		return left;
	}
	return -1;
}

int solution(string name) {
	int answer = 0;

	int size = name.size();
	//1.알파벳들을 순회하는데 가는 최단 거리 찾기(좌 or 우 직진)
	//2.각 알파벳 자리에서 최단 거리 찾기
	int dir =  choose_direction(name);
	int flag = true; //커서 이동이 전혀 필요없는경우
	if (dir >= 0) { //정방향
		cout << "정방향" << endl;
		for (int i = 0; i < size-dir; i++) {
			answer += get_distance(name[i]) + 1;//+1은 커서 이동
			name[i] = 'A';
			flag = false;
			//cout << "answer : " << answer << endl;
			int flag2 = check_turn_left(name, i);
			if (flag2>0) {
				answer--;//커서 이동한거 취소
				cout << "돌아가시오" << "현재 index : " << i << endl;
				answer += i;
				cout << answer << endl;
				for (int j = size - 1; j > i + flag2; j--) {
					answer += get_distance(name[j]) + 1;
				}
				return answer;
			}
		}
	}
	else {//역방향
		//첫째자리먼저하고
		cout << "역방향" << endl;
		answer += get_distance(name[0]) + 1;
		name[0] = 'A';
		for (int i = size - 1; i > 0-dir; i--) {
			answer += get_distance(name[i]) + 1; //+1은 커서 이동
			name[i] = 'A';
			flag = false;
			int flag2 = check_turn_right(name, i);
			if (flag2>0) {
				answer--;//커서 이동한거 취소
				cout << "돌아가시오 현재 index : " << i << endl;
				answer += size - i - 1;
				for (int j = 0; j < i-flag2; j++) {
					answer += 1 + get_distance(name[j]);
				}
				return answer;
			}
		}
	}
	if (flag == false) { //커서 이동을 한번이라도 했으면
		answer--;
	}
	return answer;
}
