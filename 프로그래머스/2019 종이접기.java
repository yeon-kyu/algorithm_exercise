package algorithm;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class Solution {
	
	int ans[];
	
	int no(int x) {
		if(x==0)
			return 1;
		else
			return 0;
	}
	
	void doit(int cur) { 
		int target = cur*2+1; 
		ans[cur] = 0;
		System.out.println(cur+"번째값: "+ans[cur]);
		for(int i=cur+1;i<target;i++) {
			ans[i] = no(ans[2*cur-i]);
			System.out.println(i+"번째값: "+ans[i]);
		}
	}
	
	public int[] solution(int n) {
        int[] answer;
        int s = (int) (Math.pow(2,n)-1);
        
        answer = new int[s];
        ans = new int[s];
        
        ans[0] = 0;
        for(int i=1;i<n;i++) { //n-1번 반복
        	int cur = (int)Math.pow(2, i)-1;//1,3,7..
        	doit(cur);
        }
        
       
        answer = ans;
        
        return answer;
        
    }
	
    public static void main(String[] args){
    	Solution s = new Solution();
    	
    	s.solution(3);
    }
}