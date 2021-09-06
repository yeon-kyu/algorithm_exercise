#include <string>
#include <vector>

using namespace std;

string phase1(string id){
    int size = id.size();
    int diff = 'A'-'a';
    for(int i=0;i<size;i++){
        char c = id[i];
        if(c>='A'&&c<='Z'){
            id[i] = c-diff;
        }
    }
    return id;
}

string phase2(string id){
    string str = "";
    int size = id.size();
    for(int i=0;i<size;i++){
        char c = id[i];
        if(c>='a'&&c<='z' || c>='0' && c<='9' || c=='-' || c=='_' || c=='.'){
            str += c;
        }
    }
    return str;
}

string phase3(string id){
    int size = id.size();
    for(int i=1;i<size;i++){
        char c = id[i];
        if(c == '.'){
            if(id[i-1] == '.'){
                id[i-1] = ' ';//삭제할 문자를 ' '으로 임시로 표현
            }
        }
    }
    string str = "";
    for(int i=0;i<size;i++){
        if(id[i] != ' '){
            str += id[i];
        }
    }
    return str;
}
string phase4(string id){
    int size = id.size();
    if(id[size-1] == '.'){
        id.erase(size-1,1);
    }
    if(id[0] == '.'){
        id.erase(0,1);
    }
    return id;
}

string phase6(string id){
    int size = id.size();
    if(size>=16){
        id.erase(15);
    }
    return phase4(id);
}

string phase7(string id){
    int size = id.size();
    if(size == 1){
        //id += id[0]+id[0];
        id.append(2,id[0]);
    }
    else if(size == 2){
        //id = id + id[1];
        id.append(1,id[1]);
    }
    return id;
}

string solution(string new_id) {
    string answer = "";
    
    string id1 = phase1(new_id);
    string id2 = phase2(id1);
    string id3 = phase3(id2);
    string id4 = phase4(id3);
    string id5 = id4;
    if(id5 == ""){
        id5 = "a";
    }
    string id6 = phase6(id5);
    string id7 = phase7(id6);
    
    answer = id7;
    
    return answer;
}