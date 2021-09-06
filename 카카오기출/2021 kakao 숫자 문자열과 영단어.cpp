#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int size = s.size();
    for(int i=0;i<size;i++){
        int num;
        if(s[i]>= '0' && s[i] <='9'){
            num = s[i]-'0';
        } else {
            char c = s[i];
            if(c=='z'){
                num = 0; 
                i += 3;
            } else if(c=='o'){
                num = 1;
                i+=2;
            } else if(c=='t'){
                if(s[i+1] == 'w'){
                    num = 2;
                    i+=2;
                } else if(s[i+1] =='h'){
                    num = 3;
                    i+=4;
                }
            } else if(c=='f'){
                if(s[i+1] == 'o'){
                    num = 4;
                    i+= 3;
                } else if(s[i+1] == 'i'){
                    num = 5;
                    i+=3;
                }
            } else if(c=='s'){
                if(s[i+1] == 'i'){
                    num = 6;
                    i+=2;
                } else if(s[i+1] == 'e'){
                    num = 7;
                    i+=4;
                }
            } else if(c=='e'){
                num = 8;
                i+=4;
            } else if(c=='n'){
                num = 9;
                i+=3;
            } else{
                printf("no word error in index %d", i);
            }
        }
        
        answer = answer*10 + num;
    }
    
    return answer;
}