#include<iostream>
#include<climits>
using namespace std;
int dis_max = -INT_MAX;
int Cal(int Now_Row, int Now_Line) {
	return (1+Now_Line)*Now_Line/2 + Now_Row;
}
void Search(int sj[], int Now_Line) {
//自底而上查找
	if(Now_Line == 0) {
		cout<<sj[0];
		return;
	}
	for (int i = 0; i <= Now_Line-1; ++i) {
		sj[Cal(i, Now_Line-1)] += max(sj[Cal(i, Now_Line)], sj[Cal(i+1, Now_Line)]);
	}
	Search(sj, Now_Line-1);
}
int main() {
	int n;
	cin>>n;
	int length = (1+n)*n/2;
	int sj[length];
	for (int i = 0; i < length; ++i)
		cin>>sj[i];
	Search(sj, n-1);
}