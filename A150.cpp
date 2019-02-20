#include<iostream>
using namespace std;
int fun(int k, int n) {
	if(k == 0 || k == n) return 1;
	return(fun(k, n-1) + fun(k-1, n-1));
}
int main()
{
	int k, n;
	cin>>k>>n;
	cout<<fun(k, n);
	return 0;
}