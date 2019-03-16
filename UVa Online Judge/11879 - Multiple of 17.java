import java.math.BigInteger;
import java.util.Objects;
import java.util.Scanner;

class Main
{
    public static void main(String[] args)
    {
        long a = 17;
        BigInteger n;
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextBigInteger();

        while (n.compareTo(BigInteger.ZERO) != 0)
        {
            if (Objects.equals(n.mod(BigInteger.valueOf(a)), BigInteger.ZERO)) { System.out.println(1); }
            else { System.out.println(0); }

            n = scanner.nextBigInteger();
        }
    }
}
