#include <string>
#include <vector>
#include <iostream>

using namespace std;

int visited[360001];
int p_time;
int ad_time;
long long pre_sum[360001];

int convert_string_to_int(string str){
    int ret = stoi(str.substr(6,2));
    ret += stoi(str.substr(3,2)) * 60;
    ret += stoi(str.substr(0,2)) * 3600;
    return ret;
}

string convert_llong_to_string(long long num){
    string str = "";
    long long a = num/3600;
    if(a<10){
        str += "0"+to_string(a) + ":";
    }
    else{
        str += to_string(a) + ":";
    }
    
    long long b = num%3600;
    b = b/60;
    if(b<10){
        str += "0"+to_string(b) + ":";
    }
    else{
        str += to_string(b) + ":";
    }
    
    long long c = num%3600;
    c = c%60;
    if(c<10){
        str += "0"+to_string(c);
    }
    else {
        str += to_string(c);
    }
    return str;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    p_time = convert_string_to_int(play_time);
    ad_time = convert_string_to_int(adv_time);
    
    for(int i=0;i<p_time;i++){
        visited[i] = 0;
    }
    
    for(string log : logs){
        int start = convert_string_to_int(log.substr(0,8));
        int end = convert_string_to_int(log.substr(9,8));
        for(int i=start;i<end;i++){
            visited[i]++;
        }
    }
    
    for(int i=0;i<ad_time;i++){
        pre_sum[0] = visited[i];
    }
    
    long long maxi = pre_sum[0];
    int maxi_idx = 0;
    for(int i=1;i<=p_time-ad_time;i++){
        pre_sum[i] = pre_sum[i-1] - visited[i-1] + visited[i+ad_time-1];
        if(pre_sum[i] > maxi){
            maxi_idx = i;
            maxi = pre_sum[i];
        }
    }
    answer = convert_llong_to_string(maxi_idx);
    
    return answer;
}