import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
    static BigInteger answer[]  =new BigInteger[27];
    static BigInteger catalan[] = new BigInteger[27];
    static BigInteger superCatalan[] = new BigInteger[27];

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        cal();

        while (scanner.hasNext())
        {
            int n = scanner.nextInt();

            System.out.println(answer[n]);
        }
    }

    public static void cal()
    {
        answer[1] = answer[2] = BigInteger.ZERO;

        catalan[0] = catalan[1] = BigInteger.ONE;

        superCatalan[1] = superCatalan[2] = BigInteger.ONE;

        for (int i = 2; i < 26; i++)
        {
            BigInteger temp = BigInteger.valueOf((4 * i) - 2);

            catalan[i] = catalan[i - 1].multiply(temp);
            catalan[i] = catalan[i].divide(BigInteger.valueOf(i + 1));

            BigInteger inx = BigInteger.valueOf((6 * (i + 1)) - 9);
            BigInteger iny = BigInteger.valueOf((i + 1) - 3);

            superCatalan[i + 1] = superCatalan[i].multiply(inx);
            superCatalan[i + 1] =  superCatalan[i + 1].subtract(superCatalan[i - 1].multiply(iny));
            superCatalan[i + 1] = superCatalan[i + 1].divide(BigInteger.valueOf(i + 1));

            answer[i + 1] = superCatalan[i + 1].subtract(catalan[i]);
        }
    }
}
