import java.util.Scanner;
public class Main {

	public int abc(String str) {
		Scanner sc = new Scanner(System.in);
		int a;
		int O = 0;
		int C = 0;
		for (int i = 0; i<str.length(); i++) {
			a = str.charAt(i);
			switch (a) {
			case '(':
				O++; break;
			case ')':
				C++; break;
			default:
				System.out.println("!");
			}
			if (O<C) {
				System.out.println("NO");
				return 0;
			}
		}
		if (C != O) {
			System.out.println("NO");
			return 0;
		}
		else
			System.out.println("YES"); return 0;
	}
	public static void main(String[] args) {
		Main M = new Main();
		Scanner sc = new Scanner(System.in);
		int count = sc.nextInt();
		sc.nextLine();
		while (count != 0) {
			count--;
			M.abc(sc.nextLine());
		}
	}
}