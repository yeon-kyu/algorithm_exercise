#include <string>
#include <vector>

using namespace std;

vector<int> prio;
vector<int> n;

struct Data{
    int prio;
    int loc;
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int size= priorities.size();
    vector<Data> data;
    vector<Data> ans;
    
    for(int i=0;i<size;i++){
        Data temp;
        temp.prio = priorities[i];
        temp.loc = i;
        data.push_back(temp);
    }
    
    int i = 0;
    while(data.size()!=0){
        int cur_prio = data[i].prio;
        int flag = false;
        for(int j = i+1; j<data.size();j++){
            if(data[j].prio>cur_prio){ //맨 앞에놈을 맨 뒤로
                Data temp = data[i];
                data.erase(data.begin()+i);
                data.push_back(temp);
                flag = true;
                break;
            }
        }
        if(flag==false){ //맨 앞에놈이 우선순위 젤 큰놈이었음
            ans.push_back(data[i]);
            data.erase(data.begin()+i);
        }
    }
    
    for(int i = 0; i<ans.size();i++){
        //printf("%d",ans[i].loc);
        if(ans[i].loc == location){
            answer = i+1;
        }
    }
    
    return answer;
}