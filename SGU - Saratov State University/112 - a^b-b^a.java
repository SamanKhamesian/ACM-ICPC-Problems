import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);

        int a, b;

        a = cin.nextInt();
        b = cin.nextInt();

        BigInteger A = BigInteger.valueOf((long)a);
        BigInteger B = BigInteger.valueOf((long)b);

        System.out.println(A.pow(b).subtract(B.pow(a)));
    }
}
