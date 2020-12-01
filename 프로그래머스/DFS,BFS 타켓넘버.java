package algorithm;

import java.util.ArrayList;

class Solution {
	
	int nums[];
	int tar;
	int size;
	int ans = 0;
	void check(int sum) {
		if( sum==tar) {
			ans++;
		}
	}
	
	void brute(int pos,int sum) {
		
		if(pos==size-1) {
			check(sum+nums[pos]);
			check(sum-nums[pos]);
		}
		
		else {
			brute(pos+1,sum+nums[pos]);
			brute(pos+1,sum-nums[pos]);
		
		}
		
	}
	
    public int solution(int[] numbers, int target) {
        int answer = 0;
        nums = numbers;
        tar = target;
        size = numbers.length;
        
        brute(0,0);
        answer = ans;
        return answer;
    }
}