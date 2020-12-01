#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int choose_direction(string name) {
	int left = 0;
	int right = 0;
	int size = name.size();
	for (int i = 1; i < size; i++) {//��->��
		if (name[i] == 'A') {
			right++;
		}
		else {
			break;
		}
	}
	cout << "right : " << right << endl;
	for (int i = size - 1; i >= 0; i--) {//��->��
		if (name[i] == 'A') {
			left++;
		}
		else {
			break;
		}
	}
	cout << "left : " << left << endl;
	if (right > left) { //������(��->��)
		return 0-right;
	}
	else { //������(��->��)
		return left;
	}
}

int get_distance(char x) {
	int distance = x - 'A';
	if (distance > 13) { //�������ΰ��(z���� ���°� �����)
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
	if (right > left) { //ȸ���ؾ��Ѵ�
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
	if (right < left) { //ȸ���ؾ��Ѵ�
		return left;
	}
	return -1;
}

int solution(string name) {
	int answer = 0;

	int size = name.size();
	//1.���ĺ����� ��ȸ�ϴµ� ���� �ִ� �Ÿ� ã��(�� or �� ����)
	//2.�� ���ĺ� �ڸ����� �ִ� �Ÿ� ã��
	int dir =  choose_direction(name);
	int flag = true; //Ŀ�� �̵��� ���� �ʿ���°��
	if (dir >= 0) { //������
		cout << "������" << endl;
		for (int i = 0; i < size-dir; i++) {
			answer += get_distance(name[i]) + 1;//+1�� Ŀ�� �̵�
			name[i] = 'A';
			flag = false;
			//cout << "answer : " << answer << endl;
			int flag2 = check_turn_left(name, i);
			if (flag2>0) {
				answer--;//Ŀ�� �̵��Ѱ� ���
				cout << "���ư��ÿ�" << "���� index : " << i << endl;
				answer += i;
				cout << answer << endl;
				for (int j = size - 1; j > i + flag2; j--) {
					answer += get_distance(name[j]) + 1;
				}
				return answer;
			}
		}
	}
	else {//������
		//ù°�ڸ������ϰ�
		cout << "������" << endl;
		answer += get_distance(name[0]) + 1;
		name[0] = 'A';
		for (int i = size - 1; i > 0-dir; i--) {
			answer += get_distance(name[i]) + 1; //+1�� Ŀ�� �̵�
			name[i] = 'A';
			flag = false;
			int flag2 = check_turn_right(name, i);
			if (flag2>0) {
				answer--;//Ŀ�� �̵��Ѱ� ���
				cout << "���ư��ÿ� ���� index : " << i << endl;
				answer += size - i - 1;
				for (int j = 0; j < i-flag2; j++) {
					answer += 1 + get_distance(name[j]);
				}
				return answer;
			}
		}
	}
	if (flag == false) { //Ŀ�� �̵��� �ѹ��̶� ������
		answer--;
	}
	return answer;
}
