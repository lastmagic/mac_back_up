#include <stdio.h>
#include <iostream>

class Stack
{
public:
	
	char *stack;
	int top;
	int capacity;

public:

	Stack(int stackCapacity = 10001)
	{
		
		top = -1;
		capacity = stackCapacity;
		stack = new char[capacity];
	}

	bool IsEmpty() const
	{
		return top == -1;
	}

	char& Top() const
	{ 
		if (IsEmpty()) throw "Stack is empty";
		return stack[top];
	}

	void ChangeSize1D(char*& a, const int oldSize, const int newSize)
	{
		char * temp = new char[newSize];
		int number = oldSize;
		std::copy(a, a + number, temp);
		delete[] a;
		a = temp;
	}

	void Push(const char& x)
	{
		if (top == capacity - 1)
		{
			ChangeSize1D(stack, capacity, 2 * capacity);
			capacity *= 2;
		}

		stack[++top] = x;
		
	}

	void Pop()
	{
		if (IsEmpty()) throw "Stack is empty. Cannot delete";
		stack[top--];
	}
	
};
int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char pres=0;
	Stack S;
	bool first=true;
	char before=0;
	
	while (1)
	{
		before = pres;
		
		if (scanf("%c", &pres)==EOF)
		{
			while(S.top!=-1)
			{
				printf("%c ", S.Top());
				S.Pop();
			}
			break;
		}

		else if (pres == '\n')
		{
			while (!S.IsEmpty())
			{
				printf("%c ", S.Top());
				S.Pop();
			}
			printf("\n");
			first = true;
			continue;
		}

		else if (pres == '+')
		{
			// unary 의 경우 stack 에 넣지말고 그냥 무시할것 
			
			if ((first == true) || (before == '+') || (before == '-') || (before == '*') || (before == '/') || (before == '('))
			{
				continue;
			}
			// binary 의 경우 보통 stack 과 같이 표현
			// 우선순위에 따라서 출력 결과 결정
			if (S.top == -1)
			{
				S.Push('/');
			}
			else if (S.Top() == '+' || S.Top() == '-' || S.Top() == '*' || S.Top() == '/')
			{
				printf("%c ", S.Top());
				S.Pop();
				S.Push('+');
			}
			else if (S.Top() == '(')
			{
				S.Push('+');
			}
		}

		else if (pres == '-')
		{
			// unary 의 경우 stack 에 넣지 말고 바로 출력할것
			if ((first == true) || (before == '+') || (before == '-') || (before == '*') || (before == '/') || (before == '('))
			{
				printf("%c", '-');
				continue;
			}
			// binary 의 경우 보통 stack 과 같이 표현
			if (S.top == -1)
			{
				S.Push('/');
			}

			else if (S.Top() == '+' || S.Top() == '-' || S.Top() == '*' || S.Top() == '/')
			{
				printf("%c ", S.Top());
				S.Pop();
				S.Push('-');
			}
			else if (S.Top() == '(')
			{
				S.Push('-');
			}

		}

		else if (pres == '/')
		{
			// 보통 stack 과 같이 표현
			if (S.top == -1)
			{
				S.Push('/');
			}
			else if (S.Top() == '+' || S.Top() == '-')
			{
				S.Push('/');
			}
			else if (S.Top() == '*' || S.Top() == '/')
			{
				printf("%c ", S.Top());
				S.Pop();
				S.Push('/');
			}
			else if (S.Top() == '(')
			{
				S.Push('/');
			}
		}

		else if (pres == '*')
		{
			// 보통 stack 과 같이 표현
			if (S.top == -1)
			{
				S.Push('*');
			}

			else if (S.Top() == '+' || S.Top() == '-')
			{
				S.Push('*');
			}
			else if (S.Top() == '*' || S.Top() == '/')
			{
				printf("%c ", S.Top());
				S.Pop();
				S.Push('*');
			}
			else if (S.Top() == '(')
			{
				S.Push('*');
			}
		}

		else if (pres == '(')
		{
			// 무조건 stack에 쌓을 것
			S.Push('(');
		}


		else if (pres == ')')
		{
			// 가장 가까운 ( 까지  pop 하고 ()는 없앨것
			while (1)
			{
				if (S.Top() == '(')
				{
					S.Pop();
					break;
				}
				else
				{
					printf("%c ", S.Top());
					S.Pop();
				}
			}
		}

		else
		{

			// 두자릿 수 들어올때 예외 처리 
			// \b를 이용하려 했지만 앞에 붙이든 뒤에 붙이든 앞쪽 스페이스가 없어지는게 아닌 뒤쪽스페이스가 없어지는 결과가 나타남
			// 검색 후 확인하여 수정할것
			if (('0' <= before)&&(before<= '9')&&(S.top==-1))
			{
				printf("\b%c ", pres);
			}
			else
				printf("%c ", pres);
		}

		first = false;
	}

	return 0;
}


