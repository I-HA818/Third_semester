
public class UsingExceptions {

	public static void main(String[] args) {
		try {
			throwException();
		}
		catch(Exception e) {
			System.err.println("Exception handeled in main.");
		}
		
		DoesNotThrowException();
	}
	
	public static void throwException() throws Exception
	{
		try {
			System.out.println("Method throwException");
			throw new Exception();
		}
		
		catch(Exception e) {
			System.err.println("Exception handeled in method throwException.");
			throw e;
		}
		
		finally {
			System.err.println("Finally block executed in throwException.");
				
		}
	}
	
	
	public static void DoesNotThrowException() {
		try {
			System.out.println("Method DoesNotThrowException");
		}
		catch(Exception e) {
			System.err.println(e);
		}
		finally {
			System.err.println("Finally block executed in doesNotThrowException.");
		}
		System.out.println("End of method DoesNotThrowException.");
	}
}
