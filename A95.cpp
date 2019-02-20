#include <iostream>
#include <vector>
using namespace std;
void bin(int a, int count, vector<int> &temp) {
	if(a) {
		bin(a/2, count+1, temp);
		if(a % 2) {
			temp.push_back(count);
		}
	}
}
void print(int num) {
	vector<int> temp;
	bin(num, 0, temp);
	for(int i = 0; i < temp.size(); ++i) {
		if(temp[i]==1)
			cout<<2;
		else {
			if(temp[i] <= 2)
				cout<<"2("<<temp[i]<<")";
			else {
				cout<<"2(";
				print(temp[i]);
				cout<<")";
			}
		}
		if(i < temp.size()-1)
			cout<<"+";
	}
}
int main()
{
	int a;
	cin>>a;
	print(a);
	return 0;
}