package algorithm;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class Solution {
	
	ArrayList<Integer> node[];
	int size;
	int ans = 100;
	boolean visited[] = new boolean[52];
	
	void doDFS(int pos, int cnt) {
		visited[pos] = true;
		
		cnt++;
		
		if(pos==size+1) {
			if(cnt<ans) {
				ans = cnt;
			}
			return;
		}
		int s = node[pos].size();
		for(int i=0;i<s;i++) {
			if(visited[node[pos].get(i)]==false) {
				doDFS(node[pos].get(i),cnt);
				visited[node[pos].get(i)] = false;
			}
		}
	}
	
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        boolean flag = false;
        size = words.length;
        int word_size = words[0].length();
        node = new ArrayList[size+2]; //�� ��忡�� ���� ��尡 ����ִ�.
        for(int i=0;i<size+2;i++) {
        	node[i] = new ArrayList<Integer>();
        	visited[i] = false;
        }
        
        String[] words2 = new String[size+2];
        for(int i=0;i<size;i++) {
        	words2[i] = words[i];
        	if(words[i].equals(target)) {
        		flag=true;
        	}
        }
        if(flag==false) {
        	return 0;
        }
        words2[size] = begin;
        words2[size+1] = target;
        
        for(int i=0;i<size+2;i++) { //�� �ܾ ���ؼ�
        	String temp = words2[i];
        	for(int j=0;j<size+2;j++) {//�ٸ� �ܾ�� ���ؼ�
        		int cnt = 0;
        		if(i!=j) {
        			for(int k=0;k<word_size;k++) { //�ٸ� ���ĺ��� �ϳ����ٸ��� ã��
        				if(temp.charAt(k) != words2[j].charAt(k)) 
        					cnt++;
        			}
        			if(cnt==1) {
        				node[i].add(j);
        			}
        		}
        	}
        	
        }
       
        doDFS(size,0);
        
        answer = ans-1;
        return answer;
    }
    public static void main(String[] args){
    	Solution s = new Solution();
    	String[] ss = {"hot", "dot", "dog", "lot", "log", "cog"};
    	s.solution("hit","cog",ss);
    }
}