import java.util.ArrayList;

class Solution {
    
    public boolean isRight(String s){
        
        ArrayList<Character> Q = new ArrayList<>();
        int size = s.length();
        for(int i=0;i<size;i++){
            char c = s.charAt(i);
            if(c=='{' || c=='[' || c=='('){
                Q.add(c);
            }
            else{
                if(Q.size()==0){
                    return false;
                }
                char back = Q.get(Q.size()-1);
                if(c=='}'){
                    if(back =='{'){
                        Q.remove(Q.size()-1);
                    }
                    else{
                        return false;
                    }
                }
                else if(c==']'){
                    if(back=='['){
                        Q.remove(Q.size()-1);
                    }
                    else{
                        return false;
                    }
                }
                else if(c==')'){
                    if(back=='('){
                        Q.remove(Q.size()-1);
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(Q.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
    
    public int solution(String s) {
        int answer = 0;
        
        int size = s.length();
        for(int i=0;i<size;i++){
            if(isRight(s)){
                answer++;
            }
            char front = s.charAt(0);
            s = s.substring(1) + front;
        }
        
        return answer;
    }
}