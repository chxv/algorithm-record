#include<iostream>
using namespace std;
//将整数n划分为多个子式，每个子式不大于m
int split(int n ,int m)
{
    if(n==1||m==1) return 1;
    else if (n<m) return split(n,n);
    else if (n==m) return 1+split(n,n-1);
    else return split(n,m-1)+split(n-m,m);
}

int main()
{
    int n,m;
    cout<<"please input n:";
    cin>>n;
    cout<<"please input m:";
    cin>>m;
    cout<<"result:"<<split(n,m)<<endl;
    return 0;
}
