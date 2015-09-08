#include<iostream>
#include<cstdlib>

using namespace std;

/*
ͨ����������һ��Сд��ĸ(a~z)��ɵ��ַ��������дһ���ַ������˳������ַ����г��ֶ����ͬ���ַ��������״γ��ֵ��ַ����˵���
�����ַ�����abacacde�����˽��Ϊ��abcde����

Ҫ��ʵ�ֺ�����void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr);

�����롿 pInputStr��  �����ַ���
            lInputLen��  �����ַ�������        
������� pOutputStr�� ����ַ������ռ��Ѿ����ٺã��������ַ����ȳ��� 

��ע�⡿ֻ��Ҫ��ɸú��������㷨���м䲻��Ҫ���κ�IO���������

ʾ��
���룺��deefd��        �������def��
���룺��afafafaf��     �������af��
���룺��pppppppp��     �������p��

main�����Ѿ����أ����ﱣ�����û��Ĳ�����ڣ�������������ʵ�ֺ��������Ե���printf��ӡ���
��ǰ�����ʹ�������������ԣ�ֻҪ��֤���ճ�������ȷִ�м��ɣ��ú���ʵ�ֿ��������޸ģ����ǲ�Ҫ�ı亯��ԭ�͡�һ��Ҫ��֤�������в���Ӱ�졣
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
	//һ������������һ��
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