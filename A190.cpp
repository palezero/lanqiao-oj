#include<iostream>
#include<cmath>
#include<set>
using namespace std;
int main() {
	unsigned long long int n;
	unsigned long long int total = 1;
	set<unsigned long long int> a;
	bool flag = 1;
	cin>>n;
	while(flag) {
		flag = 0;
		for (unsigned long long int i = 2; i <= ceil(sqrt(n)); ++i) {
			if(n % i == 0) {
				a.insert(i);
				n /= i;
				flag = 1;
				break;
			}
		}
		if(!flag)
			a.insert(n);
	}
	for (set<unsigned long long int>::iterator it = a.begin(); it != a.end(); it++) 
		total *= *it;
	cout<<total;
	return 0;
}