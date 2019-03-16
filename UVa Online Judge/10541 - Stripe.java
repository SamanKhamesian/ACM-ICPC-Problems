import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();

        for (int i = 0; i < t; i++)
        {
            int n, k, white = 0, temp = 0;

            n = scanner.nextInt();
            k = scanner.nextInt();

            for (int j = 0; j < k; j++)
            {
                int a = scanner.nextInt();

                temp += a;
            }

            white = n - temp + 1;

            if (k > white) { System.out.println(0); }

            else
            {
                BigInteger a = BigInteger.valueOf(white);
                BigInteger b = BigInteger.valueOf(k);
                BigInteger ans = BigInteger.ONE;

                BigInteger maxim = b.max(a.subtract(b));
                BigInteger minim = b.min(a.subtract(b));

                for (BigInteger j = a; j.compareTo(maxim) == 1 ; j = j.subtract(BigInteger.ONE))
                {
                    ans = ans.multiply(j);
                }

                for (BigInteger j = BigInteger.ONE; j.compareTo(minim) < 1 ; j = j.add(BigInteger.ONE))
                {
                    ans = ans.divide(j);
                }

                System.out.println(ans);
            }
        }
    }
}
