import java.util.ArrayList;
import java.util.Scanner;

public class VasyaAndWrestling
{
    public static void main(String[] args)
    {
        boolean who = false;
        int n;
        long first = 0;
        long second = 0;
        long point;

        ArrayList<Long> f = new ArrayList<>();
        ArrayList<Long> s = new ArrayList<>();

        Scanner input = new Scanner(System.in);

        n = input.nextInt();

        for (int i = 0; i < n; i++)
        {
            point = input.nextInt();

            if (point > 0)
            {
                first += point;
                who = true;
                f.add(point);
            }

            else
            {
                second += (-1 * point);
                who = false;
                s.add(-1 * point);
            }
        }

        if(first > second)
        {
            System.out.println("first");
        }

        else if (second > first)
        {
            System.out.println("second");
        }

        else if (first == second)
        {
            for (int i = 0; i < Math.min(f.size(),s.size()); i++)
            {
                if (f.get(i) > s.get(i))
                {
                    System.out.println("first");
                    System.exit(0);
                }
                else if (f.get(i) < s.get(i))
                {
                    System.out.println("second");
                    System.exit(0);
                }

                else continue;
            }

            if (who)
                System.out.println("first");
            else System.out.println("second");
        }
    }
}
