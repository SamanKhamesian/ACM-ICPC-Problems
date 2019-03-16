import java.math.BigInteger;
import java.util.Objects;
import java.util.Scanner;

class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext())
        {
            int num = 0;

            BigInteger n, k, ans = BigInteger.ONE;

            n = scanner.nextBigInteger();
            k = scanner.nextBigInteger();

            BigInteger limit = k.max(n.subtract(k));
            BigInteger minim = k.min(n.subtract(k));

            for (BigInteger i = n; i.compareTo(limit) == 1 ; i = i.subtract(BigInteger.ONE))
            {
                ans = ans.multiply(i);
            }

            for (BigInteger i = BigInteger.ONE; i.compareTo(minim) < 1 ; i = i.add(BigInteger.ONE))
            {
                ans = ans.divide(i);
            }

            while (!Objects.equals(ans, BigInteger.ZERO))
            {
                ans = ans.divide(BigInteger.TEN);

                num++;
            }

            System.out.println(num);
        }
    }
}
