#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;


class Node
{
	friend class List;


	private:
	int data;
	Node *left;
	Node *right;

	public:
	Node()
	{
	}
	Node(int getdata)
	{
		data = getdata;
	}
};

class List
{
	private:
		Node *first;
		Node *last;


	public:

		List()
		{
			first = new Node();
			last = new Node();
			first->right = last;
			last->left = first;
		}

		void InsertFront(int a)
		{
			Node *p = new Node(a);
			p->left = first;
			p->right = first->right;
			first->right->left = p;
			first->right = p;		
		}


		void InsertBack(int a)
		{
			Node *p = new Node(a);
			p->right= last;
			p->left = last->left;
			last->left->right = p;
			last->left = p;
		}

		bool Insert(int a, int b)
		{
			for (Node *temp = first->right; temp != last; temp = temp->right)
			{
				if (temp->data == a)
				{
					Node *p = new Node(b);
					p->left = temp;
					p->right = temp->right;
					temp->right->left = p;
					temp->right = p;
					return true;
				}

				else if ((temp->data != a) && (temp->right == last))
					return false;
			}

		}

bool InsertR(int a, int b)
		{
			for (Node *temp = last->left; temp != first; temp = temp->left)
			{
				if (temp->data == a)
				{
					Node *p = new Node(b);
					p->right = temp;
					p->left = temp->left;
					temp->left->right = p;
					temp->left = p;
					return true;
				}

				else if ((temp->data != a) && (temp->left == first))
					return false;
			}

		}


		bool Delete(int a)
		{
			for (Node *temp = first->right; temp != last; temp = temp->right)
			{
				if (temp->data == a)
				{
					temp->left->right = temp->right;
					temp->right->left = temp->left;
					delete temp;
					return true;
				}

				else if ((temp->data != a) && (temp->right == last))
					return false;
			}
		}

bool DeleteR(int a)
		{
			for (Node *temp = last->left; temp != first; temp = temp->left)
			{
				if (temp->data == a)
				{
					temp->right->left = temp->left;
					temp->left->right = temp->right;
					delete temp;
					return true;
				}

				else if ((temp->data != a) && (temp->left == first))
					return false;
			}
		}

		bool Print()
		{

			Node *temp = first->right;
			if(first->right == last)
				return false;

			for (; temp != last; temp = temp->right)
			{
				if (temp == first-> right)
					printf("%d", temp->data);
				else
					printf(" %d", temp->data);
			}
			printf("\n");
			return true;
		}

		bool PrintR()
		{

			Node *temp = last->left;
			if(last->left == first)
				return false;

			for (; temp != first; temp = temp->left)
			{
				if (temp == last-> left)
					printf("%d", temp->data);
				else
					printf(" %d", temp->data);
			}
			printf("\n");
			return true;
		}

		bool Reverse()
		{
			if(first->right == last)
			{
				return false;
			}
			else
			{	
				return true;
			}
		}
};

int main(void)
{

	List L;
	int getD;
	int getA, getB;
	int getIF[1000];
	int Fpos;
	int getIB[1000];
	int Bpos;

	string str;
	string str2;
	bool Check= false;
	bool CheckR=false;
	while (cin >> str)
	{
		if (cin.eof())
			break;
		if (str == "I")
		{
			cin >> str;
			getA = atoi(str.c_str());
			cin >> str;
			getB = atoi(str.c_str());
			if(CheckR == false)
				Check = L.Insert(getA, getB);
			else
				Check = L.InsertR(getA, getB);
			if (Check == false)
				printf("error\n");
			else
				printf("done\n");
			Check = false;
		}
		else if (str == "IF")
		{
			//while loop 이용 개행까지 받아서  x y z 순으로 받았으면 z y x 순으로 If에 넣을것
			if(CheckR == true)
			{
				Bpos = 0;
			while (1)
			{

				cin >> str;
				getIB[Bpos] = atoi(str.c_str());
				str2 = cin.get();
				if (!str2.compare("\n"))
				{
					for (int i = 0; i<Bpos+1; i++)
					{
						L.InsertBack(getIB[i]);
					}
					break;
				}
				Bpos++;
			}
			printf("done\n");
			}
			else
			{
			Fpos = 0;
			while (1)
			{

				cin >> str;
				getIF[Fpos] = atoi(str.c_str());
				str2 = cin.get();
				if (!str2.compare("\n"))
				{
					for (int i = Fpos; i >= 0; i--)
					{
						L.InsertFront(getIF[i]);
					}
					break;
				}
				Fpos++;
			}
			printf("done\n");
		}
		}
		else if (str == "IB")
		{
			//~~  x y z 순으로 받았으면 x y z 순으로 ib에 넣을것
			if(CheckR == true)
			{
				Fpos = 0;
			while (1)
			{

				cin >> str;
				getIF[Fpos] = atoi(str.c_str());
				str2 = cin.get();
				if (!str2.compare("\n"))
				{
					for (int i = Fpos; i >= 0; i--)
					{
						L.InsertFront(getIF[i]);
					}
					break;
				}
				Fpos++;
			}
			printf("done\n");
			}
			else{
			Bpos = 0;
			while (1)
			{

				cin >> str;
				getIB[Bpos] = atoi(str.c_str());
				str2 = cin.get();
				if (!str2.compare("\n"))
				{
					for (int i = 0; i<Bpos+1; i++)
					{
						L.InsertBack(getIB[i]);
					}
					break;
				}
				Bpos++;
			}
			printf("done\n");
				}
		}
		else if (str == "D")
		{
			cin >> str;
			getD = atoi(str.c_str());
			if(CheckR == true)
			{
				Check = L.DeleteR(getD);
			}
			else
			{
				Check = L.Delete(getD);
			}
			if (Check == false)
				printf("error\n");
			else
				printf("done\n");
			Check = false;
		}
		else if (str == "P")
		{
			if(CheckR == true)
			{
				Check = L.PrintR();
			}
			else
			{
				Check = L.Print();
			}
			if (Check == false)
				printf("error\n");
			Check = false;
		}
		else if (str == "R")
		{
			Check = L.Reverse();
			if (Check == false)
				printf("error\n");
			else
			{
				printf("done\n");
				CheckR = (!CheckR);
			}
			Check = false;
		}
	}
	return 0;
}
