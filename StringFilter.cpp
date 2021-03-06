#include<iostream>
#include<cstdlib>

using namespace std;

/*
通过键盘输入一串小写字母(a~z)组成的字符串。请编写一个字符串过滤程序，若字符串中出现多个相同的字符，将非首次出现的字符过滤掉。
比如字符串“abacacde”过滤结果为“abcde”。

要求实现函数：void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr);

【输入】 pInputStr：  输入字符串
            lInputLen：  输入字符串长度        
【输出】 pOutputStr： 输出字符串，空间已经开辟好，与输入字符串等长； 

【注意】只需要完成该函数功能算法，中间不需要有任何IO的输入输出

示例
输入：“deefd”        输出：“def”
输入：“afafafaf”     输出：“af”
输入：“pppppppp”     输出：“p”

main函数已经隐藏，这里保留给用户的测试入口，在这里测试你的实现函数，可以调用printf打印输出
当前你可以使用其他方法测试，只要保证最终程序能正确执行即可，该函数实现可以任意修改，但是不要改变函数原型。一定要保证编译运行不受影响。
*/

void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	bool hash[26] = {0};
	int i = 0;
	int j = 0;
	for(;i<lInputLen;i++)
	{
		if(hash[pInputStr[i] - 'a'] == 0)
		{
			hash[pInputStr[i] - 'a'] = 1;
			pOutputStr[j++] = pInputStr[i];
		}
	}
	//一定不能忘记这一句
	pOutputStr[j] = '\0';
}

int main1()
{
	char pInputStr[1000];
	char pOutputStr[1000];
	int len;
	while(scanf("%s",pInputStr) != EOF)
	{
		len = strlen(pInputStr);
		stringFilter(pInputStr,len,pOutputStr);
		cout<<pOutputStr<<endl;
	}
	
	return 0;
}