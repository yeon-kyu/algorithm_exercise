package algorithm;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class Solution {
	int parent[];
	int getParent(int x) {
		if(parent[x]==x) {
			return x;
		}
		else {
			return parent[x] = getParent(parent[x]);
		}
	}
	void unionParent(int a, int b) {
		int A,B;
		A = getParent(a);
		B = getParent(b);
		if(A!=B) {
            //System.out.println(A+" "+B);
			if(A>B) 
                parent[B] = A;
			else
				parent[A] = B;
		}
	}
	
	
    public int solution(int n, int[][] computers) {
        int answer = 0;
        parent = new int[n+1];
        for(int i=0;i<n;i++) {
        	parent[i] = i;
        }
        
        Map<Integer,Integer> m = new HashMap<>();
     
        
        for(int i=0;i<n;i++) {
        	for(int j=0;j<n;j++) {
        		if(i!=j) {
        			if(computers[i][j]==1)
        				unionParent(i,j);
        		}
        	}
        }
        
        for(int i=0;i<n;i++) {
        	int temp = getParent(i);
        	if(!m.containsKey(temp)) {
        		m.put(temp,1);
        		//System.out.println(temp);
        	}
        }
        
        answer = m.size();
        
        return answer;
    }
}