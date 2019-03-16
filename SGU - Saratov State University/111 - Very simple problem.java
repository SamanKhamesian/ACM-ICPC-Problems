import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Solution
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(new BufferedInputStream(System.in));

        BigInteger x = scanner.nextBigInteger();

        BigInteger l = BigInteger.ONE, h = BigInteger.TEN.pow(1000), two = l.add(BigInteger.ONE);

        while (h.subtract(l).compareTo(BigInteger.ONE) == 1)
        {
            BigInteger m = l.add(h.subtract(l).divide(two));

            if (m.multiply(m).compareTo(x) >= 0)
            {
                h = m;
            }

            else
            {
                l = m;
            }
        }

        if (h.multiply(h).compareTo(x) == 0) { System.out.println(h); }

        else { System.out.println(l); }
    }
}
