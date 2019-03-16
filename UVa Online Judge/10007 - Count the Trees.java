import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    static BigInteger[] num = new BigInteger[301];

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        calculate();

        int n = scanner.nextInt();

        while (n != 0)
        {
            System.out.println(num[n]);

            n = scanner.nextInt();
        }
    }

    public static void calculate()
    {
        int index = 2;

        num[1] = BigInteger.ONE;

        for (BigInteger i = num[1].add(BigInteger.ONE); i.compareTo(BigInteger.valueOf(300)) < 1; i = i.add
                (BigInteger.ONE))
        {
            BigInteger temp = BigInteger.ONE;

            for (BigInteger j = i.multiply(BigInteger.valueOf(2)); j.compareTo(i.add(BigInteger.ONE)) == 1 ; j = j
                    .subtract(BigInteger.ONE))
            {
                temp = temp.multiply(j);
            }

            num[index++] = temp;
        }
    }
}
