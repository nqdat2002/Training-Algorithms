import java.util.Scanner;
import java.math.BigInteger;
public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while (t-- > 0) {
			int n = sc.nextInt();
			int k = sc.nextInt();
			BigInteger KK = new BigInteger(String.valueOf(k));
			String s = "";
			int cnt = 0;
			for (int i = 1; i <= n; ++i) {
				s += String.valueOf(i);
				BigInteger ss = new BigInteger(s);
				if (ss.mod(KK) == BigInteger.ZERO)
					cnt++;
			}
			System.out.println(cnt);
		}
	}
}