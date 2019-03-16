import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;

class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        int n, sz;

        n = scanner.nextInt();

        while (n > 0)
        {
            n--;

            BigInteger m = scanner.nextBigInteger();
            ArrayList<BigInteger> set = new ArrayList<>();

            sz = scanner.nextInt();

            for (int i = 0; i < sz; i++)
            {
                BigInteger a;
                a = scanner.nextBigInteger();
                set.add(a);
            }

            boolean ok = true;

            for (int i = 0; i < sz && ok; i++)
            {
                BigInteger[] ans;
                BigInteger tmp = set.get(i);

                ans = m.divideAndRemainder(tmp);

                if (!Objects.equals(ans[1], BigInteger.ZERO)) ok = false;
            }

            if (ok) { System.out.println(m + " - Wonderful."); }

            else { System.out.println(m + " - Simple."); }
        }
    }
}
