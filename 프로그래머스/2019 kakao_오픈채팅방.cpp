#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,string> name;

vector<string> split(string s, string delimiter) {
	vector<string> v;
	int pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos) {
		token = s.substr(0, pos);
		v.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	v.push_back(s);
	return v;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    int size = record.size();
    for(int i=0;i<size;i++){
        vector<string> message = split(record[i]," ");
        if(message[0][0]=='E'){
            name[message[1]] = message[2];
        }
        else if(message[0][0]=='L'){
            
        }
        else if(message[0][0]=='C'){
            name[message[1]] = message[2];
        }
    }
    for(int i=0;i<size;i++){
        vector<string> message = split(record[i]," ");
        if(message[0][0]=='E'){
            answer.push_back(name[message[1]]+"님이 들어왔습니다.");
        }
        else if(message[0][0]=='L'){
            answer.push_back(name[message[1]]+"님이 나갔습니다.");
        }
    }
    
    return answer;
}