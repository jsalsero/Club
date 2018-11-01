import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
    static long expo(long a, long n) {
        long ans = 1;
        
        for (; n > 0; n >>= 1) {
            if ((n & 1) > 0)
                ans = (ans * a) % 10;
            a = (a * a) % 10;
        }
        
        return ans;
    }
    
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        
        int casos = in.nextInt();
        
        for (int i = 0; i < casos; ++i) {
            long a = in.nextInt();
            long b = in.nextInt();
            
            out.println(expo(a, b));
        }
        out.flush();
    }
}
