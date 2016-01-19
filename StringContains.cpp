#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//解法一
bool StringContains1(string &A, string &B)
{
	if (A == "" || B=="")
	{
		return false;
	}
	int lenA = A.length();
	int lenB = B.length();
	for (int i = 0; i < lenB;i++)
	{
		for (int j = 0; (j < lenA) && (A[j] != B[i] );j++)
		{
			if (j >= lenA)
			{
				return false;
			}
		}
	}
	return true;
}
//解法2
bool StringContains2(string &A, string &B)
{

}

int main()
{
	string A = "ABCD";
	string B = "BB";
	bool result_ = StringContains2(A, B);
	cout << result_ << endl;
	system("pause");
	return 0;
}
