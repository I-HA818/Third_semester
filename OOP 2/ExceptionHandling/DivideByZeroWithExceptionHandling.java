import java.util.InputMismatchException;
import java.util.Scanner;

public class DivideByZeroWithExceptionHandling {
	
	public static int result(int a,int b) 
		throws ArithmeticException
	{
		return a/b;
	}
	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		boolean loop=true;
		
		do {
			try {
				System.out.println("Enter an integer: ");
				int a= scanner.nextInt();
				System.out.println("Enter another integer: ");
				int b= scanner.nextInt();
				
				int res=result(a,b);
				System.out.printf("The result is %d / %d = %d\n",a,b,res);
				loop=false;
			}
			
			catch(InputMismatchException e) {
				
				System.err.printf("\nException: %s\n",e);
				scanner.nextLine();
				System.out.println("You must input an integer.");
			}
			
			catch(ArithmeticException e){
				System.err.printf("\nException:%s\n",e);
				System.out.println("Zero is an invalid denominator.Please try again.\n");
				
			}
		}while(loop);
	}

}
