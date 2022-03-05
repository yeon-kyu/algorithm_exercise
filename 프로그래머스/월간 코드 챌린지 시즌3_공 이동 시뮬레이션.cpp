#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = -1;
    
    int startX = x;
    int endX = x;
    int startY = y;
    int endY = y;
    
    int size = queries.size();
    for(int i=0;i<size;i++){
        vector<int> query = queries[size-1-i];
        int distance = query[1];
        
        if(query[0] == 0) { //역으로 오른쪽으로 이동
            endY = min(m-1, endY + distance);
            if(startY != 0){
                startY += distance;
                if(startY > m){
                    return 0;
                }
            }
        } else if(query[0] == 1) { //역으로 왼쪽으로 이동
            startY = max(0, startY-distance);
            if(endY != m-1) {
                endY -= distance;
                if(endY < 0){
                    return 0;
                }
            }
        } else if(query[0] == 2) { //역으로 아래로 이동
            endX = min(n-1, endX + distance);
            if(startX != 0) {
                startX += distance;
                if(startX > n) {
                    return 0;
                }
            }
        } else if(query[0] == 3) { // 역으로 위로 이동
            startX = max(0, startX-distance);
            if(endX != n-1) {
                endX -= distance;
                if(endX < 0){
                    return 0;
                }
            }
        }   
        //cout<<"query : "<<query[0]<<' '<<query[1]<<endl;
        //cout<<"startX : "<<startX<<", endX : "<<endX<< ", startY : "<<startY<<",endY : "<<endY<<endl;
    }

    
    long long row = endX - startX + 1;
    long long col = endY - startY + 1;
    
    answer = row*col;
    return answer;
}