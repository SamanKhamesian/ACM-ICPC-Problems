import java.util.Arrays;
import java.util.Scanner;

class Main
{
    public static void main(String[] args)
    {
        long ans, A, B;
        String n, a, b;
        char[] N;

        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext())
        {
            n = scanner.next();
            N = n.toCharArray();

            Arrays.sort(N);
            a = new String(N);
            b = new StringBuffer(a).reverse().toString();

            int count = 0;

            while (a.charAt(count) == '0')
            {
                count++;
            }

            if (count != 0)
            {
                count = b.length() - count - 1;

                String temp = new StringBuffer(b.substring(0, count)).reverse().toString();

                a = b.substring(count, b.length()) + temp;
            }

            A = Long.parseLong(a);
            B = Long.parseLong(b);

            ans = B - A;

            System.out.println(B + " - " + A + " = " + ans +  " = 9 * " + ans / 9);
        }
    }
}
