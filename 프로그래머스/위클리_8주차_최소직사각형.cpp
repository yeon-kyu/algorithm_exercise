#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int max_w = 0;
    int max_h = 0;
    for(vector<int> size : sizes){
        if(size[0] < size[1]){
            int temp = size[0];
            size[0] = size[1];
            size[1] = temp;
        }
        
        max_w = max(size[0], max_w);
        max_h = max(size[1], max_h);
    }
    
    answer = max_w * max_h;
    return answer;
}