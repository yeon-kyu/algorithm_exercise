#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    long long answer = 0;
    
    int arr[] = {1,2,4};
    
    vector<int> ans;
    
    while(true){
        
        ans.push_back(n%3);
        n = n/3;
        if(n<=3){
            if(n!=0)
                ans.push_back(n);
            break;
        }
        
    }
    
    int size = ans.size();
    
    for(int i = 0;i<size;i++){
        if(ans[i]==0){
        
            ans[i] = 3;
            ans[i+1]--;        
            if(i==size-1){
                ans[i] = 0;
            }
            
        }
         else if(ans[i]==-1){
            ans[i] = 2;
            ans[i+1]--;
         }       
    }
    
    for(int i = size-1; i>=0; i--){
        if(ans[i]!=0)
            answer = answer*10+arr[ans[i]-1];
    }
    
    return to_string(answer);
}