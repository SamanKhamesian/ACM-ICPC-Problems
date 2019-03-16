import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        BigInteger[] fibo = new BigInteger[101];

        BigInteger a = BigInteger.ONE, b = a.add(BigInteger.ONE);

        fibo[0] = a;
        fibo[1] = b;

        for (int i = 2; i < 101; i++)
        {
            fibo[i] = a.add(b);

            a = b;

            b = fibo[i];
        }

        boolean ok = true;

        while (scanner.hasNext())
        {
            String num1, num2;

            num1 = scanner.next();
            num2 = scanner.next();

            BigInteger f = BigInteger.ZERO;

            for (int i = num1.length() - 1; i >= 0; i--)
            {
                if (num1.charAt(i) == '1') f = f.add(fibo[num1.length() - 1 - i]);
            }

            String ans = "0";

            for (int i = num2.length() - 1; i >= 0 ; i--)
            {
                if (num2.charAt(i) == '1') f = f.add(fibo[num2.length() - 1 - i]);
            }

            boolean first = false;

            for (int i = 100; i >= 0 ; i--)
            {
                if (fibo[i].compareTo(f) < 1)
                {
                    if (!first)
                    {
                        first = true;
                        ans = "";
                    }

                    f = f.subtract(fibo[i]);

                    ans += '1';


                }

                else if (fibo[i].compareTo(f) == 1)
                {
                    if (first)
                    {
                        ans += '0';
                    }
                }
            }

            if (ok) { ok = false; }

            else { System.out.println(); }

            System.out.println(ans);
        }
    }
}
