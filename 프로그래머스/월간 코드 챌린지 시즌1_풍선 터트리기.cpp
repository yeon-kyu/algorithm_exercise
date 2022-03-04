#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<int> s;

vector<int> smallestFromLeft;
vector<int> smallestFromRight;

void setupSmallestFromLeft(vector<int> &a) {
    int size = a.size();
    int smallest = a[0];
    
    smallestFromLeft.resize(size);
    
    for(int i=0;i<size;i++){
        smallest = min(smallest, a[i]);
        smallestFromLeft[i] = smallest;
    }
}

void setupSmallestFromRight(vector<int> &a){
    int size = a.size();
    int smallest = a[size-1];
    
    smallestFromRight.resize(size);
    
    for(int i=0;i<size;i++){
        smallest = min(smallest, a[size-1-i]);
        smallestFromRight[size-1-i] = smallest;
    }
}

int solution(vector<int> a) {
    int answer = 0;
    
    int size = a.size();
    if(size == 1) {
        return 1;
    } else if(size == 2) {
        return 2;
    }
    //size >= 3 가 보장됨
    
    setupSmallestFromLeft(a);
    setupSmallestFromRight(a);
    
    for(int notTouchedIdx=1; notTouchedIdx <= size-2; notTouchedIdx++){
        int left = smallestFromLeft[notTouchedIdx-1];
        int right = smallestFromRight[notTouchedIdx+1];
        int middle = a[notTouchedIdx];
        
        s.insert(left);
        s.insert(right);
        if(middle < left || middle < right){
            s.insert(middle);
        }
    }
    answer = s.size();
    
    return answer;
}