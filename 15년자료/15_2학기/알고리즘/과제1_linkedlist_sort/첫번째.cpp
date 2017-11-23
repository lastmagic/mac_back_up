#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct d_node{
	int data;
	struct d_node *left;
	struct d_node *right;
}d_node;


typedef struct d_list{
	d_node *head = (d_node*)malloc(sizeof(d_node));
	d_node *tale = (d_node*)malloc(sizeof(d_node));
}d_list;
// list �� �����ϱ� ���ؼ� head �� tail �κ��� �������� �Ҵ� �� �ش�. ������ ��� class �� �����ڰ� �ƴϹǷ� main������ ���ش�.

int list_cnt(d_list L){

	int cnt = 0;
	for (d_node *temp = L.head->right; temp != L.tale; temp = temp->right)
	{
		if (temp == L.tale)
			continue;
		else
			cnt++;
	}
	return cnt;
}
void list_insert_head(int data, d_list L){	//head�� right�� ���ο� ��带 �߰��Ѵ�.

	d_node* temp = (d_node*)malloc(sizeof(d_node));
	temp->data = data;
	L.head->right->left = temp;
	temp->right = L.head->right;
	L.head->right = temp;
	temp->left = L.head;
}

void list_insert_tail(int data, d_list L){	//tail�� left�� ���ο� ��带 �߰��Ѵ�.

	d_node* temp = (d_node*)malloc(sizeof(d_node));
	temp->data = data;
	L.tale->left->right = temp;
	temp->left = L.tale->left;
	L.tale->left = temp;
	temp->right = L.tale;
}
bool list_insert_index(int index, int getData, d_list L){

	int cnt = 1;

	for (d_node * temp = L.head; temp != L.tale; temp = temp->right)
	{
		if (index == cnt)
		{
			d_node *put = (d_node*)malloc(sizeof(d_node));
			put->data = getData;
			temp->right->left = put;
			put->right = temp->right;
			temp->right = put;
			put->left = temp;
			return true;
		}
		cnt++;
	}

	printf("There is no data that you enter. Please check--error insert_index\n");
	return false;

}
void list_delete_head(d_list L){
	d_node * temp;
	temp = L.head->right;
	L.head->right->right->left = L.head;
	L.head->right = L.head->right->right;
	free(temp);
}
void list_delete_tail(d_list L){
	d_node * temp;
	temp = L.tale->left;
	L.tale->left->left->right = L.tale;
	L.tale->left = L.tale->left->left;
	free(temp);
}
bool list_delete_data(int getData, d_list L){

	bool flag = false;
	for (d_node * temp = L.head->right; temp != L.tale; temp = temp->right)
	{
		if (temp->data == getData){
			temp->right->left = temp->left;
			temp->left->right = temp->right;
			free(temp);
			//free ���ִ°� �ʿ���
			flag = true;
			break;
		}
	}
	if (flag == true)
		return true;
	else
	{
		printf("There is no data that you enter. Please check--error delete_data\n");
		return false;
	}

}
bool list_delete_index(int index, d_list L){

	int cnt = 1;

	for (d_node * temp = L.head; temp != L.tale; temp = temp->right)
	{
		if (index == cnt)
		{
			d_node *toDel;
			toDel = temp->right;
			temp->right->right->left = temp;
			temp->right = temp->right->right;
			free(toDel);
			//���� free ���ִ°� �ʿ���.
			//�ߴµ� �� �Ǵ��� Ȯ���� �ʿ���
			return true;
		}
		cnt++;
	}

	printf("There is no data that you enter. Please check--error delete_index\n");
	return false;
}
bool list_search_index(int index, d_list L){

	int cnt = 1;

	for (d_node * temp = L.head; temp != L.tale; temp = temp->right)
	{
		if (index == cnt)
		{
			printf("search_index> index:%d,data:%d\n", index, temp->right->data);
			return true;
		}
		cnt++;
	}

	printf("There is no index that you enter. Please check--error search_index\n");
	return false;
}
bool list_search_data(int getData, d_list L){

	bool flag = false;
	for (d_node * temp = L.head->right; temp != L.tale; temp = temp->right)
	{
		if (temp->data == getData)
			flag = true;
	}
	if (flag == true)
		return true;
	else
	{
		printf("There is no data that you enter.Please check--error search_data\n");
		return false;
	}
}
void list_clear(d_list L){

	for (d_node * temp = L.head->right; temp != L.tale; temp = temp->right)
	{
		list_delete_head(L);
	}
}
d_list list_copy(d_list L){

	d_list L2;
	L2.head->right = L2.tale;
	L2.tale->left = L2.head;
	for (d_node * temp = L.head->right; temp != L.tale; temp = temp->right)
	{
		list_insert_tail(temp->data, L2);
	}
	return L2;
	//L2�� insert�� �ϱ� ���ؼ��� ���ο� ����Ʈ�� ��� �� �� �ֵ��� ��ü �ڵ带 �����ؾ��Ѵ�.
	//�ƹ����� list �� parameter�� �޾Ƽ� insert delete �ϴ� �Լ��� �ٽ� �����ؾ� �� ��.
	//�Լ��� �� �� �ʿ� ���� parameter ����
	//�ذ�
}
void swap_int(int* a, int* b){

	int temp = *a;
	*a = *b;
	*b = temp;
}
void list_sort_quick(d_list L, int list_size)
{

}
void list_sort_asc(d_list L){

	for (d_node * temp = L.head->right; temp != L.tale; temp = temp->right)
	{

		for (d_node * temp2 = L.head->right; temp2 != L.tale; temp2 = temp2->right)
		{
			if (temp->data <= temp2->data){
				swap_int(&temp->data, &temp2->data);
			}
		}
	}
}


void list_sort_dec(d_list L){

	for (d_node * temp = L.head->right; temp != L.tale; temp = temp->right)
	{
		int getT = 0;
		for (d_node * temp2 = L.head->right; temp2 != L.tale; temp2 = temp2->right)
		{
			if (temp->data >= temp2->data){
				swap_int(&temp->data, &temp2->data);
			}
		}
	}
}

void print_list(d_list L){

	for (d_node * temp = L.head->right; temp != L.tale; temp = temp->right)
		printf(" %d", temp->data);
	printf("\n");
}
void changeSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int temp=0;
		for (int j = 0; j < size; j++)
		{
			if (array[i] >= array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
int main(void){
	struct d_list L;
	L.head->right = L.tale;
	L.tale->left = L.head;
	L.head->left = NULL;
	L.tale->right = NULL;
	list_insert_head(1, L);
	list_insert_head(20, L);
	list_insert_head(3, L);
	list_insert_head(4, L);
	list_insert_head(5, L);
	list_insert_head(6, L);
	list_insert_head(7, L);
	list_insert_head(8, L);
	list_insert_head(9, L);
	list_insert_head(10, L);
	list_sort_asc(L);
	print_list(L);
	list_sort_dec(L);
	print_list(L);

	int array[100];
	for (int i = 0; i = 100; i++)
		array[i] = rand() % 1000;
	changeSort(array, 100);
	for (int i = 0; i < 100; i++)
		printf("%d ", array[i]);
	printf("asdf");
	/*
	int num = list_cnt(L);
	list_insert_head(5,L);
	list_insert_head(4,L);
	list_insert_head(3,L);
	list_insert_head(2,L);
	list_insert_head(1,L);
	list_insert_tail(10,L);
	int num2 = list_cnt(L);
	printf("num = %d, num2 = %d\n", num,num2);
	list_delete_head(L);
	list_delete_tail(L);
	list_delete_data(1,L);
	list_clear(L);
	list_insert_index(1, 1,L);
	list_insert_index(2, 2,L);
	list_insert_index(3, 3,L);
	list_delete_index(1, L);
	list_delete_index(2, L);
	list_search_index(1, L);
	list_search_index(10, L);*/
}
