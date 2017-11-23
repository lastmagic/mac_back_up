#include <stdio.h>


int tree[120] = { 0 };


int in[7] = { 0 };


struct object
{
	int w;
	int p;

	double wperp;

};

object o[] = { {0,0,0}, { 2,20,10 },{ 5,30,6 },{ 7,35,5 },{ 3,12,4 },{ 1,3,3 } };

int W = 9;

int max = 0;

bool promising(int level, int no_po,int Weight,int now_profit)
{
	double bound = now_profit;
	int totWeight = Weight;
	int j;

	if (Weight >= W) return false;
	else
	{
		if (no_po % 2 == 0 || no_po ==1)
			 j = level;
		else
			j = level + 1;

		while ((j <= 6) && (totWeight + o[j].w <= W))
		{
			totWeight = totWeight + o[j].w;
			bound += o[j].p;
			j++;
		}
	
	
		int k = j;

		if (k <= 6)
		{
			bound = bound + (W - totWeight)*o[k].wperp;
			return bound > now_profit;
		}
	}

	return false;
}

void dfs(int level,int no_po,int Weight,int now_profit)
{


	if (promising(level,no_po,Weight, now_profit))
	{
		if (no_po % 2 == 0)
		{
			if (Weight + o[level].w > W)
				return;

			now_profit += o[level].p;
			Weight += o[level].w;
			in[level] = level;
		}
		else
			in[level] = 0;


		if (max < now_profit)
			max = now_profit;

		dfs(level + 1,no_po*2,Weight, now_profit);
		dfs(level + 1,no_po*2 +1,Weight, now_profit);
	}

}

int main()
{

	dfs(0,1,0,0);


	printf("max profit  : %d", max);

	return 0;
}