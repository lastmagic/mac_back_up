#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct vertex

{

	int ess;

	int lss;

	int indeg;

	int outdeg;

	

};

class aoe

{

private:

	

	int **e;

	int **l;

	int **aoeNet;

	int size;

	bool **check;

	vertex *v;

	

public:

	aoe(int gsize)

	{

		size = gsize;

		e = new int*[size];

		l = new int*[size];

		aoeNet = new int*[size];

		check = new bool*[size];

		v = new vertex[size];

		for (int i = 0; i < size; i++)

		{

			e[i] = new int[size];

			l[i] = new int[size];

			aoeNet[i] = new int[size];

			check[i] = new bool[size];

			v[i].ess = 0;

			v[i].lss = -1;

			v[i].indeg = 0;

			v[i].outdeg = 0;

		}

 

		for (int i = 0; i < size; i++)

		{

			for (int j = 0; j < size; j++)

			{

				e[i][j] = -1;

				l[i][j] = -1;

				aoeNet[i][j] = 0;

				check[i][j] = false;

			}

		}

 

	}

	

public:

	//directed cycle 존재여부 판단함수만 짜면 완성임;

	bool dCycle()

	{

 

		return false;

	}

	bool twoStart()

	{

		int cnt = 0;

		for (int i = 0; i < size; i++)

		{

			if (v[i].indeg == 0)

				cnt++;

		}

		if (2 <= cnt)

			return true;

		else

			return false;

	}

	void setSize(int gsize)

	{

		size = gsize;

	}

	void print()

	{

		for (int i = 0; i < size; i++)

		{

			for (int j = 0; j < size; j++)

			{

				printf("%d ", aoeNet[i][j]);

			}

			printf("\n");

		}

	}

	void printEss()

	{

		for (int i = 0; i < size; i++)

		{

			printf("%d: %d\n", i,v[i].ess);

		}

	}

	void printLss()

	{

		for (int i = 0; i < size; i++)

		{

			printf("%d: %d\n", i, v[i].lss);

		}

	}

	void setAoe(int first, int last, int weight)

	{

		aoeNet[first][last] = weight;

	}

	

	void setdeg(int index)

	{

		v[index].indeg++;

	}

	void setOdeg(int index)

	{

		v[index].outdeg++;

	}

	// earlist start time 구하기

	void printCritical()

	{

		bool check = false;

		for (int i = 0; i < size; i++)

		{

			for (int j = 0; j < size; j++)

			{

				if (aoeNet[i][j] != 0)

				{

					e[i][j] = v[i].ess;

					l[i][j] = v[j].lss - aoeNet[i][j];

					if (e[i][j] == l[i][j])

						printf("%d,%d %d %d %d %s\n", i, j, e[i][j], l[i][j], 0, "yes");

					else

						printf("%d,%d %d %d %d %s\n", i, j, e[i][j], l[i][j], l[i][j]-e[i][j], "no");

				}

			}

		}

	}

	bool findEss()

	{

		

		stack s;

		int j = 0;

		int cntD = 0;

		for (int i = 0; i < size; i++)

		{

			if (v[i].indeg == 0)

			{

				j = i;

				cntD++;

			}

		}

		if (cntD == 0)

			return false;

		while (1)

		{

		

				for (int i = 0; i < size; i++)

				{

					if ((aoeNet[j][i] != 0) )

					{ 

						if (v[i].ess <= v[j].ess + aoeNet[j][i])

						{

							v[i].ess = v[j].ess + aoeNet[j][i];

						

						}

						

						v[i].indeg--;

						if (v[i].indeg == 0)

						{

							s.Push(i);

							cntD++;

						}

						//선행자가 없는 정점들만 넣을 수 있도록 if문 추가해야함.

						//i 를 stack 에 저장

						

					}

				}

			// j 를 stack에서 pop 한놈으로 변경

				if (s.IsEmpty())

					break;

				j = s.getTop();

				s.Pop();

				

		}

		return true;

 

	}		

	void printIn()

	{

 

		for (int i = 0; i < size;i++)

		{ 

			printf("%d\n", v[i].indeg);

 

		}

	}

	void printOln()

	{

		for (int i = 0; i < size; i++)

		{

			printf("%d\n", v[i].outdeg);

		}

	}

	// latest start time 구하기

	void findLss()

	{

		v[size-1].lss = v[size-1].ess;

		for (int i = 0; i < size; i++)

		{

			v[i].lss = v[size-1].lss;

		}

		stack s;

 

		int j = size-1;

		while (1)

		{

 

			for (int i = 0; i < size; i++)

			{

				if ((aoeNet[i][j] != 0))

				{

					if (v[j].lss - aoeNet[i][j] <= v[i].lss)

						v[i].lss = v[j].lss - aoeNet[i][j];

					v[i].outdeg--;

					//v[i].indeg--;

					if (v[i].outdeg == 0)

						s.Push(i);

 

					//선행자가 없는 정점들만 넣을 수 있도록 if문 추가해야함.

					//i 를 stack 에 저장

 

				}

			}

			// j 를 stack에서 pop 한놈으로 변경

			if (s.IsEmpty())

				break;

			j = s.getTop();

			s.Pop();

 

		}

	}

 

	

	class stack

	{

	private:

		int top;

		int capacity;

		int size;

		int *v;

	public:

		stack()

		{

			capacity = 10000;

			size = 0;

			v = new int[capacity];

			top = -1;

		}

		bool IsEmpty()

		{

			if (top == -1)

				return true;

			else

				return false;

		}

		void Push(int gv)

		{

			if (capacity == size + 1)

			{

				int *temp = new int[capacity * 2];

				for (int i = 0; i < capacity; i++)

				{

					temp[i] = v[i];

				}

				temp = v;

				delete v;

			}

			size++;

			v[++top] = gv;

		}

		void Pop()

		{

			v[top--];

		}

		int getTop()

		{

			return v[top];

		}

	};

	// 이를 이용해 early time, late time 구하기

	

	

};

 

 

int main(void)

{

	aoe a(10000);

	

	string str;

	string str2;

	char *ctr;

	char *ctr2;

	bool nline = true;

	int first;

	int last;

	int weight;

	int cnt=1;

	

	while (1)

	{

		cin >> str;

		if (cin.eof())

		{

			a.setSize(cnt);

			break;

		}

		if (nline == true)

		{

			nline = false;

			first = atoi(str.c_str());

			

		}

		else

		{

			ctr = strtok_r((char *)str.c_str(), ",", &ctr2);

			last = atoi(ctr);

			weight = atoi(ctr2);

			a.setAoe(first, last, weight);

			a.setdeg(last);

			a.setOdeg(first);

			str2 = cin.get();

			if (str2 == "\n")

			{

				nline = true;

				first = first + 1;

				cnt++;

				

				continue;

			}

			else if (str2 == " ")

			{

				continue;

			}

		}

		

	}

 

	bool checkDC = true;

 

	if (a.twoStart())

	{

		printf("AOE network error\n");

		return 0;

	}


	checkDC = a.findEss();

	a.findLss();

	if (checkDC == true)

	{

		a.printCritical();

	}

	else

		printf("AOE network error\n");


	

	

	return 0;

}
