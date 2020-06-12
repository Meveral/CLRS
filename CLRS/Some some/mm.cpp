//备忘录方法优化后的求斐波那契数列的程序


long long ans[1000];
char flag[1000];
long long fun(int n)
{
	int v1, v2;
	if (n == 1 || n == 2)
		return 1;
	if (flag[n - 1] == 0)//如果之前未计算过fun(n-1)
	{
		v1 = fun(n - 1);
		ans[n - 1] = v1;
		flag[n - 1] = 1;
	}
	else
		v1 = ans[n - 1]; //如果之前计算过fun(n-1)，直接从ans[n-1]取数
	if (flag[n - 2] == 0)//如果之前未计算过fun(n-2)
	{
		v2 = fun(n - 2);
		ans[n - 2] = v2;
		flag[n - 2] = 1;
	}
	else
		v2 = ans[n - 2]; //如果之前计算过fun(n-2)，直接从ans[n-2]取数
	return v1 + v2;
}

