import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	static int x = 1;
	static int O = 0;
	static int o = 0;
	static ArrayList<Integer> Arr = new ArrayList<Integer>();
	public static void abc(Stack<Character> S) {
		char c = S.pop();
		char next_c = 'a';
		if (!S.isEmpty()) {
			next_c = S.pop();
			S.push(next_c);
		}

		if (c == ')') {
			if (next_c == '(')
			{
				S.pop();
				Arr.add(x * 2);
			}
			else {
				x = x * 2;
				O++;
			}
		}
		else if (c == ']') {
			if (next_c == '[')
			{
				S.pop();
				Arr.add(x * 3);
			}
			else {
				x = x * 3;
				o++;
			}
		}
		else if (c == '(') {
			x = x / 2;
			O--;
		}
		else if (c == '[') {
			x = x / 3;
			o--;
		}
	}


	public static void main(String[] args) {
		Main M = new Main();
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		char c;
		int sum = 0;
		boolean fail = false;
		//M.abc(str);
		Stack<Character> S = new Stack<Character>();
		for (int i = 0; i<str.length(); i++) {
			S.push(str.charAt(i));

		}
		while (!S.isEmpty()) {
			abc(S);
			if (O<0) {
				fail = true;
				break;
			}
			else if (o<0) {
				fail = true;
				break;
			}
		}
		if (O>0) {
			fail = true;
		}
		else if (o>0)
			fail = true;
		if (fail == true)
			System.out.println("0");
		else {
			while (!Arr.isEmpty()) {
				sum = sum + Arr.remove(0);
			}
			System.out.println(sum);
		}
	}
}
