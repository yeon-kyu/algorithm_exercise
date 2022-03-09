#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> usedWords;

bool isUsed(string str) {
    if (find(usedWords.begin(), usedWords.end(), str) != usedWords.end()) {
        return true;
    } else {
        return false;
    }
}

bool isNotValid(string str) {
    if (usedWords.back().back() != str[0]) {
        return true;
    } else {
        return false;
    }
}
    
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    
    usedWords.push_back(words[0]);
    
    int size = words.size();
    for(int i=1;i<size;i++) {
        if(isUsed(words[i]) || isNotValid(words[i])) {
            int num = i%n + 1;
            int cycle = i/n + 1;
            answer[0] = num;
            answer[1] = cycle;
            break;
        }
        usedWords.push_back(words[i]);
    }

    return answer;
}