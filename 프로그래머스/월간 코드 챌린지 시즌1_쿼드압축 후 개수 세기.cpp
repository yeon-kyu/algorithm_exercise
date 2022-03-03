#include <string>
#include <vector>
#include <iostream>

using namespace std;

int zeroCnt = 0;
int oneCnt = 0;

void divide(vector<vector<int>>& arr, int startY, int startX, int endY, int endX) {
    
    if(startY == endY) {
        if(arr[startY][startX] == 0) {
            zeroCnt++;
        } else {
            oneCnt++;
        }
        return;
    }
    
    int num = arr[startY][startX];
    int mergeFlag = true;
    for(int i = startY; i< endY; i++) {
        for(int j = startX; j < endX; j++) {
            if (num != arr[i][j]) {
                mergeFlag = false;
                break;
            }
        }
        if(mergeFlag == false) {
            break;
        }
    }
    if(mergeFlag == false) {
        int gap = endY - startY;
        divide(arr, startY, startX, startY + gap/2, startX + gap/2);
        divide(arr, startY, startX + gap/2, startY + gap/2, endX);
        divide(arr, startY + gap/2, startX, endY, startX + gap/2);
        divide(arr, startY + gap/2, startX + gap/2, endY, endX);
    }
    else {
        if (num == 0) {
            zeroCnt++;
        } else {
            oneCnt++;
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    int size = arr.size();
    
    divide(arr, 0,0, size, size);
    answer.push_back(zeroCnt);
    answer.push_back(oneCnt);
    
    return answer;
}