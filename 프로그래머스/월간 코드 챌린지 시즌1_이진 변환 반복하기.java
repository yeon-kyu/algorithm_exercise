class Solution {
    int removedCnt = 0;
    
    public String getBinary(String str){
        int c = str.length();
        
        String ret = "";
        while(true){
            if(c == 1){
                ret += c;
                break;
            }
            int add = c%2;
            c = c/2;
            ret += add; //숫자를 char로 바꿔야함. java는 알아서 바꿔줌
        }
        return ret;
    }
    
    public String removeZero(String s){
        String str = "";
        int size = s.length();
        for(int i=0;i<size;i++){
            if(s.charAt(i) == '1'){
                str += '1';
            }
        }
        removedCnt += size - str.length();
        return str;
    }
    
    public int[] solution(String s) {
        int[] answer = {0,0};
        
        int cnt = 0;
        while(true){
            if(s.equals("1")){
                break;
            }
            s = removeZero(s);
            s = getBinary(s);
            cnt++;
        }
        answer[0] = cnt;
        answer[1] = removedCnt;
        
        return answer;
    }
}