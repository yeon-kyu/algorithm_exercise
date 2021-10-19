class Solution {
    public int solution(int[] absolutes, boolean[] signs) {
        int answer = 0;
        
        int size = absolutes.length;
        for(int i=0;i<size;i++){
            int sig;
            if(signs[i] == true){
                sig = 1;
            }
            else {
                sig = -1;
            }
            answer += absolutes[i] * sig;
        }
        
        return answer;
    }
}