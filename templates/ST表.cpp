
int d[1000006][25];                     //ST表
int mn[1000006];
void rmq_init(int n)
{
	/*for (int i = 1; i <= n; i++)
		d[i][0] = a[i];*/
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
	for (int len = 1; len <= n; ++len) {
		int k = 0;
		while ((1 << (k + 1)) <= len)
			k++;
		mn[len] = k;
	}
}
int rmq(int L, int R)
{
	int k = mn[R - L + 1];
	return max(d[L][k], d[R - (1 << k) + 1][k]);
}
