package algorithm;

import java.util.ArrayList;

public class Solution {
	
	public int[] solution(int[][] v) {
        int[] answer = {0,0};

        //System.out.println("Hello Java");

        ArrayList A = new ArrayList();
        int a1,a2;
        int x1 = v[0][0];
        int x2 = v[1][0];
        if(x1==x2)
        	a1 = x2 = v[2][0];
        else if(x1==v[2][0]) 
        	a1 = v[1][0];
        else
        	a1 = v[0][0];
        
        int y1 = v[0][1];
        int y2 = v[1][1];
        if(y1==y2)
        	a2 = y2 = v[2][1];
        else if(y1==v[2][1])
        	a2 = v[1][1];
        else
        	a2 = v[0][1];
        answer[0] = a1;
        answer[1] = a2;
        System.out.println(a1+" "+a2);
        return answer;
    }
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int v[][] = {{1,4},{3,4},{3,10}};
		Solution s = new Solution();
		s.solution(v);
	}

}
