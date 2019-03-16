import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    static BigInteger ans[] = new BigInteger[1000001];

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        cal();

        while (n >= 3)
        {
            System.out.println(ans[n]);

            n = scanner.nextInt();
        }
    }

    public static void cal()
    {
        ans[3] = BigInteger.ZERO;

        for (int i = 4; i < 1000001; i++)
        {
            ans[i] = ans[i - 1];

            BigInteger temp;

            if (i % 2 == 0)
            {
                temp = (BigInteger.valueOf(i - 4).divide(BigInteger.valueOf(2)).add(BigInteger.ONE));

                temp = temp.multiply(temp);

                ans[i] = ans[i].add(temp);
            }

            else
            {
                temp = (BigInteger.valueOf(i - 1).multiply(BigInteger.valueOf(i - 3)).divide(BigInteger.valueOf(4)));

                ans[i] = ans[i].add(temp);
            }
        }
    }
}
