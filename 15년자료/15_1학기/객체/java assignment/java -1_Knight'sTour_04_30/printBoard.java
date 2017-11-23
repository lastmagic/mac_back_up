package Mid;

public class printBoard {

	private String a;
	public printBoard()
	{
	}
	
	public void print(int array[][])
	{
		a = "";
		for(int i=0;i<array.length;i++)
		{
			for(int j=0; j<array[i].length;j++)
			{
				a = a + "|" + array[i][j];
			}
			System.out.println(a);
			a = "";
		}
		System.out.println("*********************************");
		System.out.println();
	}
	
}
