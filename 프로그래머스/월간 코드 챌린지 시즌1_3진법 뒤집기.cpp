#include <string>
#include <vector>

using namespace std;

string convertToReverseTernary(int n) {
    string str = "";
    while (n > 0) {
        int temp = n%3;
        n = n/3;
        str += to_string(temp);
    }
    return str;
}

int convertTernaryToDemical(string n) {
    int ret = 0;
    int numberToMultiple = 1;
    int size = n.size();
    for(int i=0; i<size; i++) {
        int indexNum = n[size-1-i] - '0';
        ret += indexNum * numberToMultiple;
        numberToMultiple *= 3;
    }
    return ret;
}

int solution(int n) {
    int answer = 0;
    
    string ternary = convertToReverseTernary(n);    
    answer = convertTernaryToDemical(ternary);
    
    return answer;
}