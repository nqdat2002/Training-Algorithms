import java.util.Scanner;
public class Tichnhonhat{
    public static long calc(long a, long b, long x, long y, long n){
        if(a - x <= n)
        {
            n -= (a - x);
            a = x;
            b = Math.max(y,b - n);
        }
        else a -= n;
        return a * b;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        long a, b, x, y, n;
        while(t-- > 0){
            a = sc.nextLong();
            b = sc.nextLong();
            x = sc.nextLong();
            y = sc.nextLong();
            n = sc.nextLong();
            System.out.println(Math.min(calc(a, b, x, y, n), calc(b, a, y, x, n)));
        }
        sc.close();
    }
}