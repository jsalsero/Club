import java.math.*;
import java.io.*;
import java.util.*;

public class Main{

	public static BigInteger n, res;
	public static BigInteger A[] = new BigInteger[107];
	public static int i;

	public static BigInteger dp(int index, BigInteger prod) {
		if(index >= i)
			return prod;
		return prod.max( dp(index + 1, prod.multiply(A[index]) ) );
	}

	public static void main(String args[]) {

		Scanner in = new Scanner(System.in);
		do {
	      try{n = in.nextBigInteger();} catch(Exception e){break;};
	      if( !n.equals(BigInteger.valueOf(-999999)) )
	      	A[i++] = n;
	      else {
	      	res = BigInteger.valueOf(-10000000);
	      	for(int j = 0; j < i; j++) {
	      	  res = res.max( dp(j + 1, A[j]) );
	        }
	        System.out.println( res );
	      	i = 0;
	      }
		} while(true);
	}
}
