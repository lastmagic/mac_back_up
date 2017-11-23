#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;// cin을 사용하기 위해서 네임스페이스 영역 std 사용.
class MaxHeap // 기본적인 최대 힙 구조는 책과 동일.
{
private:

	int heapSize;
	int capacity;
	int *heap;

public:
	
	MaxHeap(int theCapacity = 10)
	{
		capacity = theCapacity;
		heapSize = 0;
		heap = new int[capacity + 1];
	}

	bool IsEmpty()
	{
		if (heapSize < 1)
		{
			return true;
		}

		else
			return false;
	}

	int Top()
	{
		return heap[1];
	}

	void Push(int e)
	{
		if (heapSize == capacity)
		{
			// changesize1D 귀찮아서 내가 구현했음, 틀렸을 경우 수정이 필요함. for loop 내에 변수 위치만 확인하면 될듯
			int *temp = new int[2 * capacity];
			for (int i = 1; i <= capacity; i++)
			{
				temp[i] = heap[i];
			}
			delete(heap);
			heap = temp;
			capacity = capacity * 2;
		}

		int currentNode = ++heapSize;
		while (currentNode != 1 && heap[currentNode / 2] < e)
		{
			heap[currentNode] = heap[currentNode / 2];
			currentNode /= 2;
		}
		heap[currentNode] = e;
	}

	void Pop()
	{
		int lastE = heap[heapSize--];
		int currentNode = 1;
		int child = 2;
		while (child <= heapSize)
		{
			if (child < heapSize && heap[child] < heap[child + 1])
				child++;
			if (lastE >= heap[child])
				break;
			heap[currentNode] = heap[child];
			currentNode = child;
			child *= 2;
		}

		heap[currentNode] = lastE;
	}

	void Print()
	{
		for (int i = 1; i <= heapSize; i++)
		{
			if (i == heapSize)
				printf("%d\n", heap[i]);
			else
			{
				printf("%d ", heap[i]);
			}
			
		}
	}

	int getHeapSize()
	{
		return heapSize;
	}
};

int main(void)
{
	MaxHeap H;
	int getA = 0;
	int *getSize;
	
	string str;
	
	while (cin >> str)
	{
		if (cin.eof())
			break;

		if (str == "I")
		{
			cin >> str;
			getA = atoi(str.c_str());
			H.Push(getA);
			printf("done\n");
		}
		else if (str == "D")
		{
			if (cin.get() == '\n')
			{
				if (H.IsEmpty())
					printf("error\n");
				else
				{
					H.Pop();
					printf("done\n");
				}
			}
			else
			{
				if (H.IsEmpty())
					printf("error\n");
				else
				{
					cin >> str;
					getA = atoi(str.c_str());
					if (getA > H.getHeapSize())
					{
						printf("error\n");
						continue;
					}
					getSize = new int[getA];
					for (int i = 0; i < getA; i++)
					{
						getSize[i] = H.Top();
						H.Pop();
					}
					for (int i = 0; i < getA - 1; i++)
					{
						H.Push(getSize[i]);
					}
					printf("done\n");
					delete(getSize);
				}
				
			}
		}
		else if (str == "T")
		{

			if (cin.get() == '\n')
			{
				if (H.IsEmpty())
					printf("error\n");
				else
				{
					printf("%d\n", H.Top());
				}
			}
			else
			{
				if (H.IsEmpty())
					printf("error\n");
				else
				{
					cin >> str;
					getA = atoi(str.c_str());
					if (getA > H.getHeapSize())
					{
						printf("error\n");
						continue;
					}
					getSize = new int[getA];
					for (int i = 0; i < getA; i++)
					{
						getSize[i] = H.Top();
						H.Pop();
					}
					for (int i = 0; i < getA; i++)
					{
						H.Push(getSize[i]);
					}
					printf("%d\n", getSize[getA - 1]);
					delete(getSize);
				}
				
			}

		}
		else if (str == "P")
		{
			if (H.IsEmpty())
				printf("error\n");
			else
			{
				H.Print();
			}
		}
	}
	return 0;
}