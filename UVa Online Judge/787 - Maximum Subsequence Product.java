import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

class Main
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        long MINIMUM = -999999;

        while(input.hasNext())
        {
            ArrayList<BigInteger> myList = new ArrayList<>();

            BigInteger value = BigInteger.valueOf(input.nextLong());

            while (value.compareTo(BigInteger.valueOf(MINIMUM)) != 0)
            {
                myList.add(value);

                value = BigInteger.valueOf(input.nextLong());
            }

            System.out.println(function(myList));
        }
    }

    static BigInteger function(ArrayList a)
    {
        BigInteger result;
        BigInteger[] MAX = new BigInteger[a.size()];
        BigInteger[] MIN = new BigInteger[a.size()];

        result = (BigInteger) a.get(0);
        MAX[0] = (BigInteger) a.get(0);
        MIN[0] = (BigInteger) a.get(0);

        for (int i = 1; i < a.size(); i++)
        {
            BigInteger x = (BigInteger) a.get(i);

            if (x.compareTo(BigInteger.ZERO) > 0)
            {
                MAX[i] = x.max(x.multiply(MAX[i - 1]));
                MIN[i] = x.min(x.multiply(MIN[i - 1]));
            }

            else
            {
                MAX[i] = x.max(x.multiply(MIN[i - 1]));
                MIN[i] = x.min(x.multiply(MAX[i - 1]));
            }

            result = result.max(MAX[i]);
        }

        return result;
    }
}
