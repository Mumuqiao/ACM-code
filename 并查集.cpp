int pre[1000];   //并查集
int find(int x)                                       //查找根节点
{
	int r = x;
	while (pre[r] != r)                           //返回根节点 r
		r = pre[r];

	int i = x, j;
	while (i != r)                                   //路径压缩
	{
		j = pre[i]; 				// 在改变上级之前用临时变量  j 记录下他的值 
		pre[i] = r; 				//把上级改为根节点
		i = j;
	}
	return r;
}
void join(int x, int y)                           //判断x y是否连通，
											   //如果已经连通，就不用管了 如果不连通，就把它们所在的连通分支合并起,
{
	int fx = find(x), fy = find(y);
	if (fx != fy)
		pre[fx] = fy;
}

注意种类并查集：
食物链类型题目：POJ 1182为例子
1. 选择使用取余的方法：
const int maxn = 5 * 1e4 + 5;

int pre[maxn];
int r[maxn];

int find(int x) {
	int fx = pre[x];
	if (pre[x] != x) {
		pre[x] = find(pre[x]);
		r[x] = (r[x] + r[fx]) % 3;

	}
	return pre[x];
}

int main() {

	int N, K, ans;
	scanf_s("%d%d", &N, &K);
	for (int i = 0; i <= N; i++) {
		pre[i] = i;
		r[i] = 0;

	}

	ans = 0;
	while (K--) {
		int x, y, d;
		scanf_s("%d%d%d", &d, &x, &y);
		int fx = find(x);
		int fy = find(y);
		if (x > N || y > N || (d == 2 && x == y))
			ans++;
		else if (fx == fy && (r[x] - r[y] + 3) % 3 != d - 1)
			ans++;
		else if (fx != fy) {
			pre[fx] = fy;
			r[fx] = ((d - 1) + r[y] - r[x] + 3) % 3;
		}
	}

	printf("%d\n", ans);
}

第二种是开n倍的并查集空间，进行join操作
int fa[300005];
int n,k,ans;
inline int read()
{
    int sum=0;
    char ch=getchar();
    while(ch>'9'||ch<'0') ch=getchar();
    while(ch>='0'&&ch<='9') sum=sum*10+ch-48,ch=getchar();
    return sum;
}//读入优化
int find(int x)
{
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}//查询
int unity(int x,int y)
{
    int r1=find(fa[x]),r2=find(fa[y]);
    fa[r1]=r2;
}//合并
int main()
{
    int x,y,z;
    n=read(),k=read();
    for(int i=1;i<=3*n;++i) fa[i]=i; //对于每种生物：设 x 为本身，x+n 为猎物，x+2*n 为天敌
    for(int i=1;i<=k;++i) 
    {
        z=read(),x=read(),y=read();
        if(x>n||y>n) {ans++; continue;} // 不属于该食物链显然为假
        if(z==1)
        {
            if(find(x+n)==find(y)||find(x+2*n)==find(y)) {ans++; continue;}
            //如果1是2的天敌或猎物，显然为谎言
            unity(x,y); unity(x+n,y+n); unity(x+2*n,y+2*n);
            //如果为真，那么1的同类和2的同类，1的猎物是2的猎物，1的天敌是2的天敌
        }
        else if(z==2)
        {
            if(x==y) {ans++; continue;} //其实是废话但是可以稍微省点时间
            if(find(x)==find(y)||find(x+2*n)==find(y)) {ans++; continue;}
            //如果1是2的同类或猎物，显然为谎言
            unity(x,y+2*n); unity(x+n,y); unity(x+2*n,y+n);
            //如果为真，那么1的同类是2的天敌，1的猎物是2的同类，1的天敌是2的猎物
        }
    }
    printf("%d\n",ans);
    return 0;
}
