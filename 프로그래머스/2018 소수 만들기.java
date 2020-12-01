package algorithm;

import java.util.ArrayList;

class Solution {
	
	int size;
	int numss[];
	int ans = 0;
	
	
	boolean checkPrime(int n) {
		
		for(int i=2;i<n;i++) {
			if(n%i ==0) {//서로소가 아니면
				return false;
			}
		}
		
		return true;
	}
	
	void brute(int pos, int cnt,int sum) {
		cnt++;
		sum += numss[pos];
		if(cnt==3) {
			if(checkPrime(sum)==true)
				ans++;
		}
		else {
			for(int i=pos+1;i<size;i++) {
				brute(i,cnt,sum);
			}
		}
		
	}
	
    public int solution(int[] nums) {
        int answer = -1;
        
        size = nums.length;
        numss = nums;

        for(int i=0;i<size;i++) {
        	brute(i, 0, 0);
        }
        
        answer = ans;
        return answer;
    }
}
