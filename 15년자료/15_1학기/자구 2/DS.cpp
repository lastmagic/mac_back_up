#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

class LinkedList;

class Node
{
	friend class LinkedList;
public:
	Node *prev;
	int num;
	Node *next;
};

class LinkedList
{
public:
	void Create(LinkedList *list); // linkedlist 초기화
	void Insert(LinkedList *list, int n1, int n2); // 특정 노드 뒤에 삽입
	void InsertBack(LinkedList *list, int n); // 맨 뒤에 삽입
	void InsertFirst(LinkedList *list, int n); // 맨 앞에 삽입
	void Delete(LinkedList *list, int n); // 특정 노드 삭제
	void Print(LinkedList *list); // 리스트 내용 출력
	LinkedList* Reverse(LinkedList *list); // 리스트 노드 순서 뒤집기

	Node *headp; // head Node를 가르키는 포인터
	Node *tailp; // tail Node를 가르키는 포인터
	Node *curp; // 현재 작업중인 Node를 가르키는 포인터
	int len; // 실제 데이터가 저장되어 있는 노드의 갯수
};

void LinkedList::Create(LinkedList *lp)
{
	lp->headp = new Node;
	lp->tailp = new Node;

	lp->headp->next = lp->tailp;
	lp->tailp->prev = lp->headp;
	lp->headp->prev = lp->headp;
	lp->tailp->next = lp->tailp;

	lp->curp = NULL;
	lp->len = 0;
}

void LinkedList::Insert(LinkedList *lp, int n1, int n2)
{
	Node* nnew = new Node;
	int i;
		lp->curp = lp->headp->next;

		for (i = 0; i < lp->len; i++)
		{
			if (lp->curp->num == n1)
			{
				nnew->next = lp->curp->next;
				lp->curp->next->prev = nnew;
				nnew->prev = lp->curp;
				lp->curp->next = nnew;
				nnew->num = n2;
				lp->len++;

				printf("done\n");
				break;
			}
			lp->curp = lp->curp->next;
		}

		if (lp->len == i)
			printf("error\n");
}
void LinkedList::InsertBack(LinkedList *lp, int n)
{
	lp->curp = new Node;

	lp->curp->prev = lp->tailp->prev;
	lp->curp->next = lp->tailp;
	lp->tailp->prev->next = lp->curp;
	lp->tailp->prev = lp->curp;
	lp->len++;
	lp->curp->num = n;
}

void LinkedList::InsertFirst(LinkedList *lp, int n)
{
	lp->curp = new Node;

	lp->curp->prev = lp->headp; //
	lp->curp->next = lp->headp->next;
	lp->curp->next->prev = lp->curp;
	lp->headp->next = lp->curp;
	lp->len++;
	lp->curp->num = n;
}

void LinkedList::Delete(LinkedList *lp, int n)
{
	int i;
		lp->curp = lp->headp->next;

		for (i = 0; i < lp->len; i++)
		{
			if (lp->curp->num == n)
			{
				lp->curp->prev->next = lp->curp->next;
				lp->curp->next->prev = lp->curp->prev;

				delete lp->curp;
				lp->len--;
				printf("done\n");
				break;
			}

			lp->curp = lp->curp->next;
		}

		if (i == lp->len)
		{
			printf("error\n");
		}
}

void LinkedList::Print(LinkedList *lp)
{
	int i;
		lp->curp = lp->headp->next;

		if (lp->curp == lp->tailp)
			printf("error\n");
		else
		{
			for (i = 0; i< lp->len; i++)
			{
				if (lp->len - 1 == i)
					printf("%d\n", lp->curp->num);
				else
					printf("%d ", lp->curp->num);

				lp->curp = lp->curp->next;
			}
		}
}

LinkedList* LinkedList::Reverse(LinkedList *lp)
{
	int i;
	LinkedList* lp2 = new LinkedList;
	lp2->Create(lp2);
	lp->curp = lp->headp->next;

	if (lp->curp == lp->tailp)
		printf("error\n");
	else
	{
		for (i = 0; i < lp->len; i++)
		{
			lp2->curp = new Node;

			lp2->curp->prev = lp2->headp; //
			lp2->curp->next = lp2->headp->next;
			lp2->curp->next->prev = lp2->curp;
			lp2->headp->next = lp2->curp;
			lp2->len++;
			lp2->curp->num = lp->curp->num;
			lp->curp = lp->curp->next;
		}
		printf("done\n");
	}
	for(i = 0; i < lp->len; i++)
	{
		lp->curp = lp->headp->next;
		lp->headp->next = lp->curp->next;
		lp->curp->next->prev = lp->headp;
		delete lp->curp;
		}
	return lp2;
}

int main(void)
{
	char c[2], x;
	int a, b, ary[1000], i = 0, j;

	LinkedList* list = new LinkedList;
	list->Create(list);
	while (1)
	{
		fflush(stdin);
		if ((scanf("%s", c)) == EOF) exit(0);

		if (strcmp(c, "I") == 0)
		{
			scanf("%d %d", &a, &b);
			list->Insert(list, a, b);
		}
		else if (strcmp(c, "IB") == 0)
		{
			while (1)
			{
				scanf("%c", &x);
				if (x == '\n')
					break;
				else
				{
					scanf("%d", &a);
					list->InsertBack(list, a);
				}
			}
			printf("done\n");
		}
		else if (strcmp(c, "IF") == 0)
		{
			i = 0;
			while (1)
			{
				scanf("%c", &x);
				if (x == '\n')
					break;
				else
				{
					scanf("%d", &a);
					ary[i] = a;
					i++;
				}
			}
			for (j = i - 1; j >= 0; j--)
				list->InsertFirst(list, ary[j]);
			printf("done\n");
		}
		else if (strcmp(c, "D") == 0)
		{
			scanf("%d", &a);
			list->Delete(list, a);
		}
		else if (strcmp(c, "P") == 0)
		{
			list->Print(list);
		}
		else if (strcmp(c, "R") == 0)
		{
			list = list->Reverse(list);
		}
	}
}
