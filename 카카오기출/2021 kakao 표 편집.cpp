#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct Node{
    int idx;
    Node* prev;
    Node* next;
};

vector<Node*> list;
stack<int> deleted;

int clearWithIndex(int idx){
    int next_idx;
    
    Node* prev_node = list[idx]->prev;
    Node* next_node = list[idx]->next;
    
    if(prev_node != NULL){
        prev_node->next = next_node;
    }
    
    if(next_node != NULL){
        next_node->prev = prev_node;
        next_idx = next_node->idx;
    }
    else{
        next_idx = prev_node->idx;
    }
    deleted.push(idx);
    
    return next_idx;
}

void rollback(){
    int idx = deleted.top();
    Node* reborn_node = list[idx];
    
    Node* prev_node = reborn_node->prev;
    Node* next_node = reborn_node->next;
    
    if(prev_node != NULL){
        prev_node->next = reborn_node;
    }
    
    if(next_node != NULL){
        next_node->prev = reborn_node;    
    }

    deleted.pop();
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    
    for(int i=0;i<n;i++){
        Node* temp = new Node;
        temp->idx = i;
        temp->prev = NULL;
        temp->next = NULL;
        
        list.push_back(temp);
    }
    
    for(int i=1;i<n;i++){
        list[i]->prev = list[i-1];
    }
    
    for(int i=0;i<n-1;i++){
        list[i]->next = list[i+1];
    }
    
    for(string command : cmd){
        char c = command[0];
        if(c == 'U'){
            int cnt = stoi(command.substr(2));
            for(int i=0;i<cnt;i++){
                k = list[k]->prev->idx;
            }
        }
        else if(c == 'D'){
            int cnt = stoi(command.substr(2));
            for(int i=0;i<cnt;i++){
                k = list[k]->next->idx;
            }
        }
        else if(c == 'C'){
            k = clearWithIndex(k);
        }
        else if(c == 'Z'){
            rollback();
        }
    }
    
    bool isdeleted[1000001];
    for(int i=0;i<n;i++){
        isdeleted[i] = false;
    }

    while(!deleted.empty()){
        int temp = deleted.top();
        isdeleted[temp] = true;
        deleted.pop();
    }

    for(int i=0;i<n;i++){
        char c;
        if(isdeleted[i]){
            c = 'X';
        }
        else {
            c = 'O';
        }
        answer.push_back(c);
    }
    
    return answer;
}