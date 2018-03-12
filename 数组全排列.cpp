#include<iostream>
using namespace std;

void poem(int list[], int l, int h,int &count)
{
	//end
	if (l == h) {
		for (int i = 0; i < h; ++i)
			cout << list[i];
		cout << endl;
		++count;
	}
	else {
		for (int i = l; i < h; ++i)
		{
			swap(list[i], list[l]);
			poem(list, l + 1, h, count);
			swap(list[i], list[l]);
		}
	}
}

int main()
{
	int count = 0;
	int x;
	cout << "please input length of list:";
	cin >> x;
	int *list=new int [x];
	cout << "please input number:" << endl;
	for (int i = 0; i < x; ++i)
		cin >> list[i];
		
	poem(list, 0, x, count);
	cout << "总共" << count << endl;
	return 0;
}
