#include <stdio.h>
#include <fstream>
#include <string.h>


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
	int X[10];
	int o = 1;
	Matrix A, L, U, P, b, forP;
	Row temp, temp2, temp3, temp4;
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
					multi = -(A.Mat[vertical + 1].row[pivot] / A.Mat[pivot].row[pivot]);
					L.Mat[vertical + 1].row[pivot] = -multi;

					// b 에 대하여 GE 실행 

					//b.Mat[vertical + 1].row[0] = b.Mat[vertical + 1].row[0] + (multi)*b.Mat[pivot].row[0];

					// 왜 안되는지 확인할것.
					// 확인완료 row[0] 이어야 가능;
					for (int horizon = pivot; horizon < sizeM; horizon++)
					{
						A.Mat[vertical + 1].row[horizon] = A.Mat[vertical + 1].row[horizon] + (multi)*A.Mat[pivot].row[horizon];
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



					if (A.Mat[pivot + i].row[pivot] != 0)
					{
						for (int j = 0; j < sizeM - pivot; j++)
						{
							temp.row[j] = A.Mat[pivot].row[pivot + j];
							A.Mat[pivot].row[pivot + j] = A.Mat[pivot + i].row[pivot + j];
							A.Mat[pivot + i].row[pivot + j] = temp.row[j];
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

					if (A.Mat[pivot].row[pivot] != 0)
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

		for (int i = 0; i < sizeM; i++)
		{
			forP.Mat[i].row[0] = b.Mat[i].row[0];
		}
		for (int i = 0; i < sizeM; i++)
		{
			for (int j = 0; j < sizeM; j++)
			{
				if (P.Mat[i].row[j] == 1)
				{
					b.Mat[i].row[0] = forP.Mat[j].row[0];
				}
			}
		}


		// solve function implement; 

		// UX = J  exchange after that using LJ = b  find solution of J
		int Q[10];
		for (int i = 0; i < 10; i++)
		{
			Q[i] = 0;
		}

		if (L.Mat[0].row[0] != 0)
			Q[0] = b.Mat[0].row[0] / L.Mat[0].row[0];
		else
			Q[0] = 0;
		if (L.Mat[1].row[1] != 0)
			Q[1] = (-(L.Mat[1].row[0] * Q[0]) + b.Mat[1].row[0]) / L.Mat[1].row[1];
		else
			Q[1] = 0;
		if (L.Mat[2].row[2] != 0)
			Q[2] = (-(L.Mat[2].row[0] * Q[0] + L.Mat[2].row[1] * Q[1]) + b.Mat[2].row[0]) / L.Mat[2].row[2];
		else
			Q[2] = 0;
		if (L.Mat[3].row[3] != 0)
			Q[3] = (-(L.Mat[3].row[0] * Q[0] + L.Mat[3].row[1] * Q[1] + L.Mat[3].row[2] * Q[2]) + b.Mat[3].row[0]) / L.Mat[3].row[3];
		else
			Q[3] = 0;
		if (L.Mat[4].row[4] != 0)
			Q[4] = (-(L.Mat[4].row[0] * Q[0] + L.Mat[4].row[1] * Q[1] + L.Mat[4].row[2] * Q[2] + L.Mat[4].row[3] * Q[3]) + b.Mat[4].row[0]) / L.Mat[4].row[4];
		else
			Q[4] = 0;
		if (L.Mat[5].row[5] != 0)
			Q[5] = (-(L.Mat[5].row[0] * Q[0] + L.Mat[5].row[1] * Q[1] + L.Mat[5].row[2] * Q[2] + L.Mat[5].row[3] * Q[3] + L.Mat[5].row[4] * Q[4]) + b.Mat[5].row[0]) / L.Mat[5].row[5];
		else
			Q[5] = 0;
		if (L.Mat[6].row[6] != 0)
			Q[6] = (-(L.Mat[6].row[0] * Q[0] + L.Mat[6].row[1] * Q[1] + L.Mat[6].row[2] * Q[2] + L.Mat[6].row[3] * Q[3] + L.Mat[6].row[4] * Q[4] + L.Mat[6].row[5] * Q[5]) + b.Mat[6].row[0]) / L.Mat[6].row[6];
		else
			Q[6] = 0;
		if (L.Mat[7].row[7] != 0)
			Q[7] = (-(L.Mat[7].row[0] * Q[0] + L.Mat[7].row[1] * Q[1] + L.Mat[7].row[2] * Q[2] + L.Mat[7].row[3] * Q[3] + L.Mat[7].row[4] * Q[4] + L.Mat[7].row[5] * Q[5] + L.Mat[7].row[6] * Q[6]) + b.Mat[7].row[0]) / L.Mat[7].row[7];
		else
			Q[7] = 0;
		if (L.Mat[8].row[8] != 0)
			Q[8] = (-(L.Mat[8].row[0] * Q[0] + L.Mat[8].row[1] * Q[1] + L.Mat[8].row[2] * Q[2] + L.Mat[8].row[3] * Q[3] + L.Mat[8].row[4] * Q[4] + L.Mat[8].row[5] * Q[5] + L.Mat[8].row[6] * Q[6] + L.Mat[8].row[7] * Q[7]) + b.Mat[8].row[0]) / L.Mat[8].row[8];
		else
			Q[8] = 0;
		if (L.Mat[9].row[9] != 0)
			Q[9] = (-(L.Mat[9].row[0] * Q[0] + L.Mat[9].row[1] * Q[1] + L.Mat[9].row[2] * Q[2] + L.Mat[9].row[3] * Q[3] + L.Mat[9].row[4] * Q[4] + L.Mat[9].row[5] * Q[5] + L.Mat[9].row[6] * Q[6] + L.Mat[9].row[7] * Q[7] + L.Mat[9].row[8] * Q[8]) + b.Mat[9].row[0]) / L.Mat[9].row[9];
		else
			Q[9] = 0;


		// 여기부터 x 계산
		for (int i = 0; i < 10; i++)
		{
			X[i] = 0;
		}

		if (A.Mat[9].row[9] != 0)
			X[9] = Q[9] / A.Mat[9].row[9];
		else
			X[9] = 0;
		if (A.Mat[8].row[8] != 0)
			X[8] = (-(A.Mat[8].row[9] * X[9]) + Q[8]) / A.Mat[8].row[8];
		else
			X[8] = 0;
		if (A.Mat[7].row[7] != 0)
			X[7] = (-(A.Mat[7].row[9] * X[9] + A.Mat[7].row[8] * X[8]) + Q[7]) / A.Mat[7].row[7];
		else
			X[7] = 0;
		if (A.Mat[6].row[6] != 0)
			X[6] = (-(A.Mat[6].row[9] * X[9] + A.Mat[6].row[8] * X[8] + A.Mat[6].row[7] * X[7]) + Q[6]) / A.Mat[6].row[6];
		else
			X[6] = 0;
		if (A.Mat[5].row[5] != 0)
			X[5] = (-(A.Mat[5].row[9] * X[9] + A.Mat[5].row[8] * X[8] + A.Mat[5].row[7] * X[7] + A.Mat[5].row[6] * X[6]) + Q[5]) / A.Mat[5].row[5];
		else
			X[5] = 0;
		if (A.Mat[4].row[4] != 0)
			X[4] = (-(A.Mat[4].row[9] * X[9] + A.Mat[4].row[8] * X[8] + A.Mat[4].row[7] * X[7] + A.Mat[4].row[6] * X[6] + A.Mat[4].row[5] * X[5]) + Q[4]) / A.Mat[4].row[4];
		else
			X[4] = 0;
		if (A.Mat[3].row[3] != 0)
			X[3] = (-(A.Mat[3].row[9] * X[9] + A.Mat[3].row[8] * X[8] + A.Mat[3].row[7] * X[7] + A.Mat[3].row[6] * X[6] + A.Mat[3].row[5] * X[5] + A.Mat[3].row[4] * X[4]) + Q[3]) / A.Mat[3].row[3];
		else
			X[3] = 0;
		if (A.Mat[2].row[2] != 0)
			X[2] = (-(A.Mat[2].row[9] * X[9] + A.Mat[2].row[8] * X[8] + A.Mat[2].row[7] * X[7] + A.Mat[2].row[6] * X[6] + A.Mat[2].row[5] * X[5] + A.Mat[2].row[4] * X[4] + A.Mat[2].row[3] * X[3]) + Q[2]) / A.Mat[2].row[2];
		else
			X[2] = 0;
		if (A.Mat[1].row[1] != 0)
			X[1] = (-(A.Mat[1].row[9] * X[9] + A.Mat[1].row[8] * X[8] + A.Mat[1].row[7] * X[7] + A.Mat[1].row[6] * X[6] + A.Mat[1].row[5] * X[5] + A.Mat[1].row[4] * X[4] + A.Mat[1].row[3] * X[3] + A.Mat[1].row[2] * X[2]) + Q[1]) / A.Mat[1].row[1];
		else
			X[1] = 0;
		if (A.Mat[0].row[0] != 0)
			X[0] = (-(A.Mat[0].row[9] * X[9] + A.Mat[0].row[8] * X[8] + A.Mat[0].row[7] * X[7] + A.Mat[0].row[6] * X[6] + A.Mat[0].row[5] * X[5] + A.Mat[0].row[4] * X[4] + A.Mat[0].row[3] * X[3] + A.Mat[0].row[2] * X[2] + A.Mat[0].row[1] * X[1]) + Q[0]) / A.Mat[0].row[0];
		else
			X[0] = 0;
		// output impAement;

		fprintf(out, "\nCase");
		fprintf(out, "%d", o);
		o++;
		fprintf(out, "\nL");
		for (int i = 0; i < sizeM; i++)
		{
			fprintf(out, "\n");
			for (int j = 0; j < sizeM; j++)
			{
				fprintf(out, " %d", L.Mat[i].row[j]);
			}
		}
		fprintf(out, "\nU");
		for (int i = 0; i < sizeM; i++)
		{
			fprintf(out, "\n");
			for (int j = 0; j < sizeM; j++)
			{
				fprintf(out, " %d", A.Mat[i].row[j]);
			}
		}

		fprintf(out, "\nP");
		for (int i = 0; i < sizeM; i++)
		{
			fprintf(out, "\n");
			for (int j = 0; j < sizeM; j++)
			{
				fprintf(out, " %d", P.Mat[i].row[j]);
			}
		}

		fprintf(out, "\nX\n");
		for (int i = 0; i < sizeM; i++)
		{
			fprintf(out, " %d", X[i]);
		}


	}


}
