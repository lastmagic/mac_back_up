package Mid;

import java.util.Random;
import java.util.Scanner;

public class Three {

	private int array[][];
	private int size;
	private boolean finish = false;
	private int cnt = 0;
	private final int rArray[] = { -2, -1, +1, +2, +2, +1, -1, -2 };
	private final int cArray[] = { +1, +2, +2, +1, -1, -2, -2, -1 };

	public Three(int getSize) {
		array = new int[getSize][getSize];
		size = getSize;
		for (int i = 0; i < getSize; i++) {
			for (int j = 0; j < getSize; j++) {
				array[i][j] = -1;
			}
		}
	}

	public boolean Computer(int getNum)
	{
		Random rand = new Random();
		int r= rand.nextInt(getNum);
		int c= rand.nextInt(getNum);
		int min=8;
		int num=-1;
		boolean check=false;
		this.check(r, c);
		
		while(!this.Success())
		{
			int waySize[] = new int[8];
			
			if(this.fail(r, c))
			{
				System.out.println("Fail");
				check = false;
				break;
			}
			
			for(int i=0; i<8; i++)
			{
				waySize[i]=10;
				if(this.movePossible(r+rArray[i], c+cArray[i]))
				{
					waySize[i]=this.waySize(r+rArray[i], c+cArray[i]);
				}
			}
			min = 8;
			for(int i=0; i<8; i++)
			{
				if(min>=waySize[i])
				{
					min = waySize[i];
					num = i;
				}
			}
//			if(this.movePossible(, C))
			if(num == -1)
			{
				this.cnt = 1;
				break;
			}
			r = r+rArray[num];
			c = c+cArray[num];
			this.check(r,c);
			num=-1;
			check = true;
		}
		
		// start from [r][c]
		// 더 이상 움직일 수 없는 상태일때 0
		// for loop 돌면서 -1인 것이 있으면 false
		// for 탈출 시 true
		
		return check;
	}

	public int waySize(int r, int c) {

		int wSize = 0;

		for (int i = 0; i < size; i++) {
			if (this.movePossible(r + rArray[i], c + cArray[i]))
				wSize++;
		}
		return wSize;
	}

	public boolean User(int getNum) {
		
		Random rand = new Random();
		int r = rand.nextInt(getNum);
		int c = rand.nextInt(getNum);
		this.check(r, c);
		Scanner in;
		int g=0;
		boolean move=false;
		in = new Scanner(System.in);
		while(!this.Success())
		{	
			if(this.fail(r, c))
			{
				System.out.println("Fail");
				break;
			}
			
			System.out.println();
			System.out.println();
			System.out.println("-------------------------------------");
			
			System.out.println(this.toString());
			
			System.out.println("-------------------------------------");
			System.out.println();
			System.out.println();
			System.out.println("Input your number");
			System.out.println("  7  0  ");
			System.out.println(" 6    1 ");
			System.out.println(" 5    2 ");
			System.out.println("  4  3  ");
			System.out.println("-------------------------------------");
			
			g = in.nextInt();
			
			switch (g){
			case 0:
				move = this.movePossible(r-2, c+1);
				if(move)
				{
					r = r-2;
					c = c+1;
					this.check(r, c);
				}
				else
					System.out.println("Wrong Number");
				break;
			case 1:
				move = this.movePossible(r-1, c+2);
				if(move)
				{
					r = r-1;
					c = c+2;
					this.check(r, c);
				}
				else
					System.out.println("Wrong Number");
				break;
			case 2:
				move = this.movePossible(r+1, c+2);
				if(move)
				{
					r = r+1;
					c = c+2;
					this.check(r, c);
				}
				else
					System.out.println("Wrong Number");
				break;
			case 3:
				move = this.movePossible(r+2, c+1);
				if(move)
				{
					r = r+2;
					c = c+1;
					this.check(r, c);
				}
				else
					System.out.println("Wrong Number");
				break;
			case 4:
				move = this.movePossible(r+2, c-1);
				if(move)
				{
					r = r+2;
					c = c-1;
					this.check(r, c);
					
				}
				else
					System.out.println("Wrong Number");
				break;
			case 5:
				move = this.movePossible(r+1, c-2);
				if(move)
				{
					r = r+1;
					c = c-2;
					this.check(r, c);
				}
				else
					System.out.println("Wrong Number");
				break;
			case 6:
				move = this.movePossible(r-1, c-2);
				if(move)
				{
					r = r-1;
					c = c-2;
					this.check(r, c);
				}
				else
					System.out.println("Wrong Number");
				break;
			case 7:
				move = this.movePossible(r-2, c-1);
				if(move)
				{
					r = r-2;
					c = c-1;
					this.check(r, c);
				}
				else
					System.out.println("Wrong Number");
				break;
			}
				
				
		}
	
		if(this.Success())
			System.out.println("Success! GAME OVER");
		else
		{
			System.out.println("You failed to this round");
			System.out.println("You move "+this.getCnt()+"  times");
		}
		
		return false;
	}

	public int[][] getArray() {
		return array;
	}

	public boolean isExist(int R, int C) {
		if (((0 <= R) && (R <= size - 1)) && ((0 <= C) && (C <= size - 1)))
			return true;
		else
			return false;
	}

	public boolean movePossible(int R, int C) {
		if (this.isExist(R, C) && (this.array[R][C] == -1))
			return true;
		else
			return false;
	}

	public void check(int R, int C) {
		this.cnt++;
		this.array[R][C] = this.cnt;
	}

	// success 가 3에 한정되어 있음 수정해야함.
	public boolean Success() {
		int f = 0;
		for (int i = 0; i < this.array.length; i++)
			for (int j = 0; j < this.array[i].length; j++) {
				if (array[i][j] == -1)
					f++;
			}
		if (f == 0)
			return true;
		else
			return false;
	}

	public boolean fail(int r, int c) {
		if (!this.movePossible(r - 2, c + 1)
				&& !this.movePossible(r - 1, c + 2)
				&& !this.movePossible(r + 1, c + 2)
				&& !this.movePossible(r + 2, c + 1)
				&& !this.movePossible(r + 2, c - 1)
				&& !this.movePossible(r + 1, c - 2)
				&& !this.movePossible(r - 1, c - 2)
				&& !this.movePossible(r - 2, c - 1))
			return true;
		else
			return false;
	}

	public int getCnt() {
		return cnt;
	}
	
	public void setCnt()
	{
		this.cnt = 0; 
	}
	public void initBoard()
	{
		for(int i=0; i<this.array.length; i++)
		{
			for(int j=0; j<this.array[i].length; j++)
			{
				this.array[i][j] = -1;
			}
		}
	}
	
	public String toString()
	{
		String a="";
		
		for(int i=0;i<array.length;i++)
		{
			for(int j=0; j<array[i].length;j++)
			{
				a = a + "|" + array[i][j];
			}
			
			a = a + '\n';
		}
		
		return a;
	}
}
