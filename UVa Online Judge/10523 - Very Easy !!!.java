import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    public static void main(String[] args)
    {
        BigInteger a, b, ans;
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext())
        {
            ans = BigInteger.ZERO;
            a = scanner.nextBigInteger();
            b = scanner.nextBigInteger();

            for (BigInteger i = BigInteger.ONE; i.compareTo(a) != 1 ; i = i.add(BigInteger.ONE))
            {
                BigInteger tmp = b.pow(i.intValue());
                ans = ans.add(tmp.multiply(i));
            }

            System.out.println(ans);
        }
    }
}
