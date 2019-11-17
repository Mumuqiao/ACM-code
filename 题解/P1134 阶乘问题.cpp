//详细题解地址！！
//https://www.luogu.org/blog/lsoer/ti-xie-p1134-jie-sheng-wen-ti-post
 
 N!最终阶乘得到的尾数去掉0一定是2,4,6,8中的一个！
 1~9 的除去5的阶乘的尾数是6， 6乘上任何尾数(2,4,6,8)都是尾数本身
 观察剩下的5的倍数的相乘 = 5^(n/5) *(n/5)!
 
 由于2^n*5^m (=) 2^n * 8^m   (=) 表示尾数相同
 
 8^m的尾数有规律{6,8,4,2}
 然后此时只需要计算n的尾数的阶乘就好了之后递归。
 就可得递归算法！！！
 
 
 
 #include <cstdio>
using namespace std;
int n,ans=1;
int a[4]= {6,8,4,2};
int main() {
    scanf("%d",&n);
    while (n>0) {
        for (int i=1; i<=n%10;++i)//除了5之外,其他数字原样乘.
        //n%10 的原因:答案只受末尾数字影响 
            if (i!=5) ans=ans*i%10;//跳过乘5(此时可以放心%10) 
        n=n/5;//n/5即少乘了多少次5
        //即乘8的次数 
        ans=ans*a[n%4]%10;//四次一循环(此时可以放心%10) 
    }
    printf("%d",ans);
    return 0;
}


 之后优化 可发现，除去5后尾数为n的数的阶乘的尾数为 {6,6,2,6,4,4,4,8,4,6}
 最终得出优化代码
 
 
#include<cstdio>
int main()
{
	int a[]{ 6,6,2,6,4,4,4,8,4,6 }, b[]{ 6,8,4,2 }, r = 1, n;
	scanf("%d", &n);
	while (n)r = r * a[n % 10] * b[(n = n / 5) % 4] % 10;
	printf("%d", r);
	return 0;
}
