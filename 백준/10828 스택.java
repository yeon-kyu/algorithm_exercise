import java.util.Scanner;

public class Main {

	private int n = 0;

	private int[] A;
	Main(int TotalSize) {
		A = new int[TotalSize];
	}

	public void push(int x) {
		A[n] = x;
		n++;
	}
	public int pop() {
		if (n == 0) {
			return -1;
		}
		else {
			int temp = A[n - 1];
			n--;
			return temp;
		}
	}
	public int size() {
		return n;
	}

	public int empty() {
		if (n == 0) {
			return 1;
		}
		else
			return 0;
	}
	public int top() {
		if (n == 0)
			return -1;
		else
			return A[n - 1];
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int TotalSize = sc.nextInt();
		Main P = new Main(TotalSize);
		while (TotalSize != 0) {
			String Inst = sc.next();
			if (Inst.equals("push")) {
				String num = sc.next();
				//System.out.println(num);
				int pushInt = 0;
				//int len = num.length();
				pushInt = Integer.parseInt(num);
				//System.out.println(pushInt);
				P.push(pushInt);
			}
			else if (Inst.equals("pop")) {
				System.out.println(P.pop());
			}
			else if (Inst.equals("size")) {
				System.out.println(P.size());
			}
			else if (Inst.equals("empty")) {
				System.out.println(P.empty());
			}
			else if (Inst.equals("top")) {
				System.out.println(P.top());
			}
			TotalSize--;
		}
	}

}
