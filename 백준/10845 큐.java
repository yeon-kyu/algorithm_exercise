import java.util.Scanner;

public class Main {
	int[] Queue = new int[10000];
	int n = 0;
	public void push(int X) {
		Queue[n] = X;
		n++;
	}
	public int pop() {
		if (n == 0)
			return -1;
		else {
			int temp = Queue[0];
			int[] shadow = new int[n - 1];
			for (int i = 0; i<n - 1; i++) {
				shadow[i] = Queue[i + 1];
			}
			for (int i = 0; i<n - 1; i++) {
				Queue[i] = shadow[i];
			}
			n--;
			return temp;
		}
	}
	public int size() {
		return n;
	}
	public int empty() {
		if (n == 0)
			return 1;
		else
			return 0;
	}
	public int front() {
		if (n == 0)
			return -1;
		else
			return Queue[0];
	}
	public int back() {
		if (n == 0)
			return -1;
		else
			return Queue[n - 1];
	}
	public static void main(String[] args) {
		Main M = new Main();
		Scanner sc = new Scanner(System.in);
		int count = sc.nextInt();
		while (count != 0) {
			count--;
			String command = sc.next();
			if (command.equals("push")) {
				int command2 = sc.nextInt();
				M.push(command2);
			}
			else if (command.equals("pop"))
				System.out.println(M.pop());
			else if (command.equals("size"))
				System.out.println(M.size());
			else if (command.equals("empty"))
				System.out.println(M.empty());
			else if (command.equals("front"))
				System.out.println(M.front());
			else if (command.equals("back"))
				System.out.println(M.back());
		}

	}

}
