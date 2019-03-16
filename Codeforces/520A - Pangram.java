import java.util.Scanner;

public class Pangram
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int size;

        String in;

        size = input.nextInt();

        in = input.next();

        if (size < 26)
            System.out.println("NO");

        else
        {
            for (char i = 'A'; i <= 'Z' ; i++)
            {
                if (in.indexOf(i) >= 0 || in.indexOf(i + 32) >= 0)
                {
                    continue;
                }

                else
                {
                    System.out.println("NO");
                    System.exit(0);
                }
            }

            System.out.println("YES");
        }
    }
}
