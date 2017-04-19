
import java.math.BigInteger;
public class mult 
{
  public static void main(String[] args) 
  {
  //BigInteger bigInteger1 = new BigInteger ("931275469");
  //BigInteger bigInteger2 = new BigInteger ("897512436");
  BigInteger bigInteger1 = new BigInteger (args[0]);
  BigInteger bigInteger2 = new BigInteger (args[1]);

  BigInteger bigIntResult =
    bigInteger1.multiply(bigInteger2); 
  System.out.println("Result is  ==> " + bigIntResult);
    //System.out.println("argv1  ==> " + args[0]);
  }
}
