import java.util.Arrays;

class Solution {
    public int solution(int[] A, int[] B) {
            int answer = 0;

            Arrays.sort(A);
            Arrays.sort(B);
            int x=0,y=0;
            int s = B.length;
            while(y!=s) {
                if(A[x]<B[y]) {
                    answer++;
                    x++; y++;
                }
                else {
                    y++;
                }
            }

            return answer;
        }
}