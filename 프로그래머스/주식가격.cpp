#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int size = prices.size();
    for(int i = 0; i<size-1; i++){
        int gap = 1;
        for(int j = i+1; j<size-1;j++){
            if(prices[i]>prices[j]){ //가격 떨어짐
                    break;
            }
            else{
                gap++;
            }
        }
        answer.push_back(gap);
    }
    answer.push_back(0);
    
    
    
    return answer;
}