/*
	Ѱ��S�з���������sample���ִ���
	S:	ƫ��
	str�� �����Ӵ�
*/

#include <iostream>
#include<string>

using namespace std;

//int count_ = 0;

int count_of_substr_in_S(string sub_str, string S)
{
	/*
		example: 010 01010
		result: 2
	*/
	int count = 0;
	for (int i = 0; i < S.length(); ++i)
	{
		if (S[i] == sub_str[0])
		{
			int j = 1;
			while (i + j <= S.length())
			{
				if (j == sub_str.length())
				{
					//��������--�ҵ�һ���Ӵ�
					++count;
					break;
				}
				else if (i+j<S.length() && S[i + j] == sub_str[j])
				{
					//cout << "i+j = " << i + j << endl;
					++j;
				}
				else
					break;
			}
		}
	}
	return count;
}

//deepth �ݹ����  status  ��ǰ�ַ����Ƿ����Ҫ��
void DFS(int S_length,const string &sub_str,string current_str,int deepth,int status,int &times)
{
	//����ǰ��֧��Ч
	if (status >= 0 && deepth < S_length)
	{
		DFS(S_length, sub_str, current_str + '0', deepth + 1, status - 1,times);

		DFS(S_length, sub_str, current_str + '1', deepth + 1, status + 1,times);
	}
	else if (deepth == S_length && status == 0)
	{
		times += count_of_substr_in_S(sub_str, current_str);
		//cout << "current str:" << current_str << " times:" << times << endl;
	}
}

//S_length����ƫ���У�substr���ֵĴ���
int calculate_times(int S_lenth, string sub_str)
{
	int times = 0;
	DFS(S_lenth, sub_str, string("1"), 1, 1,times);//��ʼ�ڵ�Ϊ1���ݹ����Ϊ1��״̬Ϊ1
	return times;
}

//http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=774&pid=1005

int main() {
	int test_times = 0;  //���Դ���
	int *sample_length;  //ÿ�β��Ե�S����
	string *sample;		 //ÿ�β��Ե�������string
	
	//��ȡ��Ҫ��Ϣ,��������������Ϸ�
	cin >> test_times;
	sample_length = new int[test_times];
	sample = new string[test_times];
	for (int i = 0; i < test_times; ++i)
		cin >> sample_length[i] >> sample[i];

	for (int i = 0; i < test_times; ++i)
	{
		cout << calculate_times(sample_length[i], sample[i]) << endl;
	}
	//cout << count_of_substr_in_S("123", "123");
	system("pause");
	return 0;
}
