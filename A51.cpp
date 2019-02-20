#include<iostream>
#include<climits>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
	vector<int > v;
	int num;
	int sum = 1;
	int count = 0;
	bool flag;
	cin>>num;
	v.push_back(2);
	for (int i = 2; i <= INT_MAX; ++i) {
		flag = 1;
		for (int j = 2; j <= ceil(sqrt(i)); ++j){
			if(i % j == 0) {
				flag = 0;
				break;
			}
		}
		if(flag) {
			v.push_back(i);
			count ++;
		}
		if(count >= num-1)
			break;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		sum *= (*it % 50000);
		sum %= 50000;
	}
	cout<<sum;
	return 0;
}