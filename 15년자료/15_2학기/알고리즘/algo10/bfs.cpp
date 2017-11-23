#include <stdio.h>
#include <queue>


int tree[120] = { 0 };
int in[7] = { 0 };



struct object
{
	int w;
	int p;
	double wperp;

};

struct nodes
{
	int now_profit;
	int now_weight;
	int level;
	int pos;
};

object o[] = { { 0,0,0 },{ 2,20,10 },{ 5,30,6 },{ 7,35,5 },{ 3,12,4 },{ 1,3,3 } };
std::queue<nodes> Q;
int W = 9;

int max = 0;

bool promising(nodes m)
{
	if (m.now_weight > W) return false;
	else
	{
		int bound = m.now_profit;
		int j = m.level + 1;
		int w = m.now_weight;

		while ((j <= 5) && (w + o[j].w) < W)
		{
			bound += o[j].p;
			w += o[j].w;
			j++;
		}

		if (j <= 5)
		{
			bound += (W - w)*o[j].wperp;

			return bound > max;
		}

	}

	return false;
}


int main()
{
	nodes temp;

	temp.now_profit = 0;
	temp.now_weight = 0;
	temp.pos = 1;
	temp.level = 0;

	Q.push(temp);

	while (!Q.empty())
	{
		nodes tmp = Q.front();

		if (max < tmp.now_profit && (tmp.now_weight<= W))
			max = tmp.now_profit;

		if (promising(tmp))
		{
			nodes in = tmp;

			in.level++;
			in.now_profit += o[in.level].p;
			in.now_weight += o[in.level].w;
			in.pos *= 2;

			Q.push(in);

			in = tmp;
			in.level++;
			in.pos *= 2;
			in.pos++;
			Q.push(in);
		}


		Q.pop();
	}

	printf("%d", max);

}