#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_right(string str){
    int open_cnt = 0;
    int close_cnt = 0;
    int size = str.size();
    for(int i=0;i<size;i++){
        if(str[i] == '('){
            open_cnt++;
        }
        else{
            close_cnt++;
        }
        
        if(open_cnt < close_cnt){
            return false;
        }
    }
    if(open_cnt != close_cnt){
        return false;
    }
    
    return true;
}

bool is_balanced(string str){
    int open_cnt = 0;
    int close_cnt = 0;
    int size = str.size();
    for(int i=0;i<size;i++){
        if(str[i] == '('){
            open_cnt++;
        }
        else{
            close_cnt++;
        }
    }
    if(open_cnt == close_cnt){
        return true;
    }
    else{
        return false;
    }
}

string reverse(string str){
    string ret = "";
    
    int size = str.size();
    for(int i=0;i<size;i++){
        if(str[i] == '('){
            ret.push_back(')');
        }
        else{
            ret.push_back('(');
        }
    }
    return ret;
}

string solve(string str){
    int size = str.size();
    if(size == 0){ //stage 1
        return "";
    }
    string u = "";
    string v = "";
    for(int i=2;i<=size;i+=2){ 
        if(is_balanced(str.substr(0,i))){
            u = str.substr(0,i);
            v = str.substr(i);
            break;
        }
    }
    
    if(is_right(u)){ //stage 3
        v = solve(v);
        return u+v;
    }
    else{ //stage 4
        string new_v = '(' + solve(v) + ')';
        
        int u_len = u.size();
        string new_u = reverse(u.substr(1,u_len-2));
        //cout<< "before : "<< u << ' '<< v << " after : "<<new_u<< ' '<< new_v<<endl;
        
        return new_v + new_u;
    }
}

string solution(string p) {
    string answer = "";
    
    if(p == ""){ //stage 1
        return "";
    }
    
    answer = solve(p);
    
    return answer;
}