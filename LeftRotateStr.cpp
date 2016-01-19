#include <iostream>
#include <cstdlib>

using namespace std;

/*
将字符串的前m个字符移动到字符串的后面
字符串:abcdef  将前两个ab移动到后面，就变成了cdefab
第一步：bacdef
第二步：bafedc
第三步：cdefab
*/
void ReverseStr(char *str,int from,int to)
{
	if (str == NULL)
	{
		return;
	}
	while (from < to)
	{
		char t = str[from];
		str[from++] = str[to];
		str[to--] = t;
	}
}
void LeftRotateString(char *s, int m)
{
	if (s == NULL)
	{
		return;
	}
	int len = strlen(s);
	if (m>len)
	{
		m %= len;
	}
	ReverseStr(s, 0, m - 1);
	ReverseStr(s, m, len - 1);
	ReverseStr(s, 0, len - 1);
}



int main()
{
	char s[] = "abcdef";
	cout << s << endl;
	LeftRotateString(s, 10);
	cout << s << endl;
	system("pause");
	return 0;
}
