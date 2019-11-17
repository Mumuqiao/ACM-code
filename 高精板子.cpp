const int maxn = 1005;/*����λ��,���е���*/
//1.�����Ҫ�������λ���Ļ�����str()�����len������Ҫ��λ��
//2.�ܴ��λ���ǻ�re�ģ����������������Ļ����� ����x^p��λ��n, n=p*log(10)x+1;(ע��Ҫ��һ��
//3.�����Լ���qmul��ȡģ�Ĺ���Ҳ����str()��c_str()�ٸ�һ��
class bign
{
	//io*2 bign*5*2 bool*6
	friend istream& operator>>(istream&, bign&);
	friend ostream& operator<<(ostream&, const bign&);
	friend bign operator+(const bign&, const bign&);
	friend bign operator+(const bign&, int&);
	friend bign operator*(const bign&, const bign&);
	friend bign operator*(const bign&, int&);
	friend bign operator-(const bign&, const bign&);
	friend bign operator-(const bign&, int&);
	friend bign operator/(const bign&, const bign&);
	friend bign operator/(const bign&, int&);
	friend bign operator%(const bign&, const bign&);
	friend bign operator%(const bign&, int&);
	friend bool operator<(const bign&, const bign&);
	friend bool operator>(const bign&, const bign&);
	friend bool operator<=(const bign&, const bign&);
	friend bool operator>=(const bign&, const bign&);
	friend bool operator==(const bign&, const bign&);
	friend bool operator!=(const bign&, const bign&);

private://��������len,�ĳ�public
	int len, s[maxn];
public:
	bign()
	{
		memset(s, 0, sizeof(s));
		len = 1;
	}
	bign operator=(const char* num)
	{
		int i = 0, ol;
		ol = len = strlen(num);
		while (num[i++] == '0' && len > 1)
			len--;
		memset(s, 0, sizeof(s));
		for (i = 0; i < len; i++)
			s[i] = num[ol - i - 1] - '0';
		return *this;
	}
	bign operator=(int num)
	{
		char s[maxn];
		sprintf_s(s, "%d", num);
		*this = s;
		return *this;
	}
	bign(int num)
	{
		*this = num;
	}
	bign(const char* num)
	{
		*this = num;
	}
	string str() const
	{
		string res = "";
		for (int i = 0; i < len; i++)
			res = char(s[i] + '0') + res;
		if (res == "")
			res = "0";
		return res;
	}
};
bool operator<(const bign& a, const bign& b)
{
	int i;
	if (a.len != b.len)
		return a.len < b.len;
	for (i = a.len - 1; i >= 0; i--)
		if (a.s[i] != b.s[i])
			return a.s[i] < b.s[i];
	return false;
}
bool operator>(const bign& a, const bign& b)
{
	return b < a;
}
bool operator<=(const bign& a, const bign& b)
{
	return !(a > b);
}
bool operator>=(const bign& a, const bign& b)
{
	return !(a < b);
}
bool operator!=(const bign& a, const bign& b)
{
	return a<b || a>b;
}
bool operator==(const bign& a, const bign& b)
{
	return !(a<b || a>b);
}
bign operator+(const bign& a, const bign& b)
{
	int up = max(a.len, b.len);
	bign sum;
	sum.len = 0;
	for (int i = 0, t = 0; t || i < up; i++)
	{
		if (i < a.len)
			t += a.s[i];
		if (i < b.len)
			t += b.s[i];
		sum.s[sum.len++] = t % 10;
		t /= 10;
	}
	return sum;
}
bign operator+(const bign& a, int& b)
{
	bign c = b;
	return a + c;
}
bign operator*(const bign& a, const bign& b)
{
	bign res;
	for (int i = 0; i < a.len; i++)
	{
		for (int j = 0; j < b.len; j++)
		{
			res.s[i + j] += (a.s[i] * b.s[j]);
			res.s[i + j + 1] += res.s[i + j] / 10;
			res.s[i + j] %= 10;
		}
	}
	res.len = a.len + b.len;
	while (res.s[res.len - 1] == 0 && res.len > 1)
		res.len--;
	if (res.s[res.len])
		res.len++;
	return res;
}
bign operator*(const bign& a, int& b)
{
	bign c = b;
	return a * c;
}
//ֻ֧�ִ�����С��
bign operator-(const bign& a, const bign& b)
{
	bign res;
	int len = a.len;
	for (int i = 0; i < len; i++)
	{
		res.s[i] += a.s[i] - b.s[i];
		if (res.s[i] < 0)
		{
			res.s[i] += 10;
			res.s[i + 1]--;
		}
	}
	while (res.s[len - 1] == 0 && len > 1)
		len--;
	res.len = len;
	return res;
}
bign operator-(const bign& a, int& b)
{
	bign c = b;
	return a - c;
}
bign operator/(const bign& a, const bign& b)
{
	int i, len = a.len;
	bign res, f;
	for (i = len - 1; i >= 0; i--)
	{
		f = f * 10;
		f.s[0] = a.s[i];
		while (f >= b)
		{
			f = f - b;
			res.s[i]++;
		}
	}
	while (res.s[len - 1] == 0 && len > 1)
		len--;
	res.len = len;
	return res;
}
bign operator/(const bign& a, int& b)
{
	bign c = b;
	return a / c;
}
bign operator%(const bign& a, const bign& b)
{
	int len = a.len;
	bign f;
	for (int i = len - 1; i >= 0; i--)
	{
		f = f * 10;
		f.s[0] = a.s[i];
		while (f >= b)
			f = f - b;
	}
	return f;
}
bign operator%(const bign& a, int& b)
{
	bign c = b;
	return a % c;
}
bign& operator+=(bign& a, const bign& b)
{
	a = a + b;
	return a;
}
bign& operator-=(bign& a, const bign& b)
{
	a = a - b;
	return a;
}
bign& operator*=(bign& a, const bign& b)
{
	a = a * b;
	return a;
}
bign& operator/=(bign& a, const bign& b)
{
	a = a / b;
	return a;
}
bign& operator++(bign& a)
{
	a = a + 1;
	return a;
}
bign& operator++(bign& a, int)
{
	bign t = a;
	a = a + 1;
	return t;
}
bign& operator--(bign& a)
{
	a = a - 1;
	return a;
}
bign& operator--(bign& a, int)
{
	bign t = a;
	a = a - 1;
	return t;
}
istream& operator>>(istream& in, bign& x)
{
	string s;
	in >> s;
	x = s.c_str();
	return in;
}
ostream& operator<<(ostream& out, const bign& x)
{
	out << x.str();
	return out;
}

const int maxnn = 1e6;
double aa[maxnn + 1];
int main() {
	bign n;
	aa[0] = 0;
	for (double i = 1; i <= 1e6; ++i) {
		aa[(int)i] = aa[(int)i - 1] + 1 / (i * i);
	}
	while (cin >> n) {
		if (n > 1e6)
			printf("%.5lf\n", aa[maxnn]);
		else {
			int d = 0;
			for (int i = n.len - 1; i >= 0; --i) {
				d *= 10;
				d += n.s[i];
			}
			printf("%.5lf\n", aa[d]);
		}
	}
}