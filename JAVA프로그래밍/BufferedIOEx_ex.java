import java.io.*;

public class BufferedIOEx_ex
{
	public static void main(String[] args)
	{
		FileReader fin = null;
		int c;
		try 
		{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			
			System.out.print("입력 >>> ");
			String str = br.readLine();
			System.out.println(str);
			
			br.close();
		}
		
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}
}