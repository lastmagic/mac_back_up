package Mid;

import java.util.Random;
import java.util.Scanner;

public class test {

	public static void main(String[] args) {
		
		boolean checkCom = false;
		boolean checkUser = false;
		Scanner in;
		in = new Scanner(System.in);
		int m = -1;
		int m2 = -1;
		
		Three t3 = new Three(3);
		Three t5 = new Three(5);
		Three t8 = new Three(8);
		printBoard b = new printBoard();

		System.out.println("Choose your mod");
		System.out.println("1. 3 x 3 Board");
		System.out.println("2. 5 x 5 Board");
		System.out.println("3. 8 x 8 Board");
		m = in.nextInt();

		System.out.println("Choose your mod");
		System.out.println("1. Computer mod");
		System.out.println("2. User mod");
		m2 = in.nextInt();
		
		if(m == 1)
		{
			if(m2 == 1){
				checkCom = t3.Computer(2);
				b.print(t3.getArray());
				t3.initBoard();
				t3.setCnt();
			}
			else if(m2 == 2){
				checkUser = t3.User(2);
				t3.initBoard();
				t3.setCnt();
			}
		}
		else if(m == 2)
		{
			if(m2 == 1){
				checkCom = t5.Computer(4);
				b.print(t5.getArray());
				t5.initBoard();
				t5.setCnt();
				while(checkCom == false){
					checkCom = t5.Computer(4);
					b.print(t5.getArray());
					t5.initBoard();
					t5.setCnt();
				}
			}
			else if(m2 == 2){
				checkUser = t5.User(4);
				t5.initBoard();
				t5.setCnt();
			}
		}
		else if(m == 3)
		{
			if(m2 == 1){
				checkCom = t8.Computer(7);
				b.print(t8.getArray());
				t8.initBoard();
				t8.setCnt();
			}
			else if(m2 == 2){
				checkUser = t8.User(7);
				t8.initBoard();
				t8.setCnt();
			}
		}
		
		
	
	}
}
