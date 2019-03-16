import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        int n;
        n = scanner.nextInt();

        for (int i = 0; i < n; i++)
        {
            String a, b, c;
            BigInteger A, B, C;
            a = scanner.next();
            b = scanner.next();

            a = new StringBuffer(a).reverse().toString();
            b = new StringBuffer(b).reverse().toString();

            A = new BigInteger(a);
            B = new BigInteger(b);

            C = A.add(B);

            while (C.mod(BigInteger.TEN) == BigInteger.ZERO)
            {
                C = C.divide(BigInteger.TEN);
            }

            c = new StringBuffer(C.toString()).reverse().toString();

            System.out.println(c);

        }
    }
}
