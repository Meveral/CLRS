//����¼�����Ż������쳲��������еĳ���


long long ans[1000];
char flag[1000];
long long fun(int n)
{
	int v1, v2;
	if (n == 1 || n == 2)
		return 1;
	if (flag[n - 1] == 0)//���֮ǰδ�����fun(n-1)
	{
		v1 = fun(n - 1);
		ans[n - 1] = v1;
		flag[n - 1] = 1;
	}
	else
		v1 = ans[n - 1]; //���֮ǰ�����fun(n-1)��ֱ�Ӵ�ans[n-1]ȡ��
	if (flag[n - 2] == 0)//���֮ǰδ�����fun(n-2)
	{
		v2 = fun(n - 2);
		ans[n - 2] = v2;
		flag[n - 2] = 1;
	}
	else
		v2 = ans[n - 2]; //���֮ǰ�����fun(n-2)��ֱ�Ӵ�ans[n-2]ȡ��
	return v1 + v2;
}

