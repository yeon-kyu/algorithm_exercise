#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    int size = scores.size();
    
    vector<vector<int>> n_scores;
    for(int i=0;i<size;i++){
        vector<int> v;
        for(int j=0;j<size;j++){
            v.push_back(scores[j][i]);
        }
        n_scores.push_back(v);
    }
    
    for(int i=0;i<size;i++){
        
        int sum = 0;
        int num = size;
        for(int j=0;j<size;j++){
            sum+=n_scores[i][j];
        }
        
        int self_score = n_scores[i][i];
        vector<int> v = n_scores[i];
        sort(v.begin(), v.end());
        
        if(v[0] == self_score){ //자신을 최저점 찍음
            if(v[1] != self_score){ //유일한 최저점
                sum -= self_score;
                num--;
            }
        }
        else if(v[size-1] == self_score){ //자신을 최고점 찍음
            if(v[size-2] != self_score){
                sum -= self_score;
                num--;
            }
        }
        
        double score = (double)sum/num;
        cout<<score<<endl;
        if(score>=90){
            answer+="A";
        }
        else if(score>=80){
            answer+="B";
        }
        else if(score>=70){
            answer+="C";
        }
        else if(score>=50){
            answer+="D";
        }
        else{
            answer+="F";
        }
    
    }
    
    return answer;
}