import java.util.ArrayList;
import java.util.Collections;

class Solution {
    
    boolean[] visited = new boolean[10];
    
    public int solution(int[] numbers) {
        int answer = 0;
        
        int size = numbers.length;
        
        for(int i=0;i<10;i++){
            visited[i] = false;
        }
        
        for(int i=0;i<size;i++){
            visited[numbers[i]] = true;
        }
        
        for(int i=0;i<10;i++){
            if(visited[i] == false){
                answer += i;
            }
        }
        return answer;
    }
}