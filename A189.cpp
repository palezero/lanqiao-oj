#include<iostream>
using namespace std;
int main() {
	int num;
	int total = 1;
	cin>>num;
	if(num == 0){cout<<0;return 0;}
	for (int i = 1; i <= num; ++i){
		total *= i;
		while(!(total % 10) && total != 0)
			total /= 10;
		total %= 10000;
	}
	cout<<total%10;
	return 0;
}