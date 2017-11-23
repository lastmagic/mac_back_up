#include <stdio.h>
#include <fstream>
#include <string>


class Row
{
public:
	int row[10];

	Row()
	{
		for (int i = 0; i < 10; i++)
		{
			row[i] = 0;
		}
	}
};


class Matrix
{
public:
	Row Mat[10];
	int mPos = 0;
	int pivot = 0;

	Matrix()
	{

	}
};

int main(void)
{
	int testCase, sizeM;
	int multi;
	int pivot;
	Matrix A, L, U, P, b;
	Row temp,temp2,temp3;
	FILE * in, *out;
	in = fopen("input.txt", "rt");
	out = fopen("output.txt", "at");
	fscanf(in, "%d", &testCase);




	// 코드 시작
	for (int i = 0; i < testCase; i++)
	{
		fscanf(in, "%d", &sizeM);

		//기본 p 생성
		for (int i = 0; i < sizeM; i++)
		{
			for (int j = 0; j < sizeM; j++)
			{
				P.Mat[i].row[j] = 0;

				if (i == j)
				{
					P.Mat[i].row[j] = 1;
				}
			}
		}
	// 기본 l 생성
		for (int i = 0; i < sizeM; i++)
		{
			for (int j = 0; j < sizeM; j++)
			{
				L.Mat[i].row[j] = 0;

				if (i == j)
				{
					L.Mat[i].row[j] = 0;
					// 생성시 모두 0으로 초기화 후 row를 서로 바꾸는 방법을 이용, 마지막에 모든 대각선에 1을 채움
				}
			}
		}
		// A 읽어서 저장
		for (int mPos = 0; mPos < sizeM; mPos++)
		{
			for (int rPos = 0; rPos < sizeM; rPos++)
			{
				fscanf(in, "%d", &A.Mat[mPos].row[rPos]);
			}

		}
		// construct b
		for (int mPos = 0; mPos < sizeM; mPos++)
		{
			fscanf(in, "%d", &b.Mat[mPos].row[0]);
		}
		
		
		
		
		
		
		// pivot 을 잡아서 GE 실행
		for (pivot = 0; pivot < sizeM; pivot++)
		{
			if (A.Mat[pivot].row[pivot] != 0)
			{

				for (int vertical = pivot; vertical < sizeM; vertical++)
				{
					multi = -(A.Mat[vertical+1].row[pivot] / A.Mat[pivot].row[pivot]);
					L.Mat[vertical + 1].row[pivot] = -multi;
					for (int horizon = pivot; horizon < sizeM; horizon++)
					{
						A.Mat[vertical + 1].row[horizon] = A.Mat[vertical + 1].row[horizon]+(multi)*A.Mat[pivot].row[horizon];
					}
				}

			}
			//pivot 이 0인경우 p에 data저장 후 row 교체
			
else 
			{
			

				int i = 1;
				// 이미 M[pivot].r[pivot] == 0 이 확실하기때문에 1부터 시작

				while (1)
				{
				
					
					
					if (A.Mat[pivot + i].row[pivot]!=0)
					{
						for (int j = 0; j < sizeM-pivot; j++)
						{
							temp.row[j] = A.Mat[pivot].row[pivot+j];
							A.Mat[pivot].row[pivot + j] = A.Mat[pivot + i].row[pivot + j];
							A.Mat[pivot+i].row[pivot + j] = temp.row[j];
							// 여기까지 성공 코드 이후 L 에 P 곱, P 변환 코드 구성
							
						}

						for (int k = 0; k < sizeM; k++)
						{
							temp2.row[k] = L.Mat[pivot].row[k];
							L.Mat[pivot].row[k] = L.Mat[pivot + i].row[k];
							L.Mat[pivot + i].row[k] = temp2.row[k];
						}

						for (int k = 0; k < sizeM; k++)
						{
							temp3.row[k] = P.Mat[pivot].row[k];
							P.Mat[pivot].row[k] = P.Mat[pivot + i].row[k];
							P.Mat[pivot + i].row[k] = temp3.row[k];
						}

					}
					
					i++;		

					if (A.Mat[pivot].row[pivot]!= 0)
					{
						break;
					}
				}
			
			
			}
		}

		for (int i = 0; i < sizeM; i++)
		{
			for (int j = 0; j < sizeM; j++)
			{
				if (i == j)
				{
					L.Mat[i].row[j] = 1;
					// 생성시 모두 0으로 초기화 후 row를 서로 바꾸는 방법을 이용, 마지막에 모든 대각선에 1을 채움
				}
			}
		}
		

	}


}