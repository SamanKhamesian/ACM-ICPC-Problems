import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        BigInteger num, temp;

        while (scanner.hasNext())
        {
            temp = BigInteger.ONE;

            num = scanner.nextBigInteger();

            for (BigInteger i = BigInteger.ONE; i.compareTo(num) != 1; i = i.add(BigInteger.ONE))
            {
                temp = temp.multiply(i);
            }

            String input = num.toString();
            String ans = temp.toString();

            System.out.println(input + "!");
            System.out.println(ans);
        }
    }
}
