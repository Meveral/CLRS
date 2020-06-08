#include<vector>
#include"test.h"

using std::vector;
using std::string;

//Find the number n which meets 2^n > i >= 2^(n-1),in which i is a gvien int number; 
int FindSize2(const int i)
{
	int temp = i - 1;
	temp |= (temp >> 1);
	temp |= (temp >> 2);
	temp |= (temp >> 4);
	temp |= (temp >> 8);
	temp |= (temp >> 16);
	return (temp > 0) ? temp + 1 : 1;
}

int FindSize2k( int i)
{
	int n = 0;
	while (i)
	{
		i = (i >> 1);
		++n;
	}
	return n;
}

void Exchange(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}


void MaxHeapify(int(*A)[14], int i,int n)
{
//	std::vector<int> Array(std::move(*A), std::move(*A + n));
	--i;
	int largest = i;
	int h = FindSize2k(n);//height of tree;
	int l = i * 2 + 1 , r = l + 1;//kids

	if (l <= n && (*A)[l] > (*A)[largest]) largest = l;
	if (r <= n && (*A)[r] > (*A)[largest]) largest = r;
	if (largest != i)
	{
		Exchange((*A)[i], (*A)[largest]);
		MaxHeapify(A, largest + 1, n);
	}
}


int main()
{
	vector < string > equations = { "a==b","b==c","d!=e" };
	Solution so;
	bool i = so.equationsPossible(equations);
	return 0;
}
