/*
	寻找S中符合条件的sample出现次数
	S:	偏串
	str： 任意子串
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
					//满足条件--找到一个子串
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

//deepth 递归深度  status  当前字符串是否符合要求
void DFS(int S_length,const string &sub_str,string current_str,int deepth,int status,int &times)
{
	//若当前分支有效
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

//S_length长的偏串中，substr出现的次数
int calculate_times(int S_lenth, string sub_str)
{
	int times = 0;
	DFS(S_lenth, sub_str, string("1"), 1, 1,times);//初始节点为1，递归深度为1，状态为1
	return times;
}

//http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=774&pid=1005

int main() {
	int test_times = 0;  //测试次数
	int *sample_length;  //每次测试的S长度
	string *sample;		 //每次测试的样例的string
	
	//获取必要信息,并假设所有输入合法
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
