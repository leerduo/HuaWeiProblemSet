#include<iostream>
#include<cstdlib>

using namespace std;

/*
ͨ����������һ��Сд��ĸ(a~z)��ɵ��ַ��������дһ���ַ���ѹ�����򣬽��ַ�����������ϯ���ظ���ĸ����ѹ���������ѹ������ַ�����
ѹ������
1����ѹ�������ظ����ֵ��ַ��������ַ���"abcbc"�����������ظ��ַ���ѹ������ַ�������"abcbc"��
2��ѹ���ֶεĸ�ʽΪ"�ַ��ظ��Ĵ���+�ַ�"�����磺�ַ���"xxxyyyyyyz"ѹ����ͳ�Ϊ"3x6yz"��

Ҫ��ʵ�ֺ�����
void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr);

�����롿 pInputStr��  �����ַ���
            lInputLen��  �����ַ�������
������� pOutputStr�� ����ַ������ռ��Ѿ����ٺã��������ַ����ȳ���

��ע�⡿ֻ��Ҫ��ɸú��������㷨���м䲻��Ҫ���κ�IO���������

ʾ��
���룺��cccddecc��   �������3c2de2c��
���룺��adef��     �������adef��
���룺��pppppppp�� �������8p��
*/

void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	int i = 0;
	int j = 0;
	int count = 1;
	for(;i<lInputLen;i++)
	{
		if(i + 1 < lInputLen && pInputStr[i] == pInputStr[i+1])
		{
			count++;
		}
		else
		{
			if(count != 1)
			{
				char temp[100];
				itoa(count,temp,10);
				int ii = 0;
				while(temp[ii])
				{
					pOutputStr[j++] = temp[ii++];
				}
			}
			pOutputStr[j++] = pInputStr[i];
			count = 1;
		}

	}
	pOutputStr[j] = '\0';
}

int main()
{
	char pInputStr[1000];
	char pOutputStr[1000];

	int len;

	while(scanf("%s",pInputStr) != EOF)
	{
		len = strlen(pInputStr);
		stringZip(pInputStr, len, pOutputStr);
		cout<<pOutputStr<<endl;
	}

	return 0;

}