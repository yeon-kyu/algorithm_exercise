// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> arr, int k) {
    // 여기에 코드를 작성해주세요.
    int answer = 0;
    
    sort(arr.begin(), arr.end());
    answer = arr[k-1] - arr[0]; // 4 6 9 9 11 19
    
    int mini = arr[k-1];
    int size = arr.size();
    for(int i=k-1;i<size;i++){
        int temp = arr[i] - arr[i-k+1];
        if(temp<mini){
            mini = temp;
        }
    }
    answer = mini;
    
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    vector<int> arr = {9, 11, 9, 6, 4, 19};
    int K = 4;
    int ret = solution(arr, K);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}