#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int num;
	int temp1, temp2;
	int Max = 0;
	cin>>num;
	char Tree[num][num];
	int Power[num];
	int sum[num];
	memset(Tree, 1, num * num * sizeof(char));
	memset(sum, 0, num * sizeof(int));
	for (int i = 0; i < num; ++i)
		cin>>Power[i];
	for (int i = 0; i < num-1; ++i) {
		cin>>temp1>>temp2;
		Tree[temp1-1][temp2-1] = 0;
		Tree[temp2-1][temp1-1] = 0;	
	}
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			if(Tree[i][j])
				sum[i] += Power[j];
			cout<<Tree[i][j]+0<<" ";
		}
		if(sum[i] > Max)
			Max = sum[i];
		cout<<" "<<sum[i]<<endl;
	}
	cout<<Max;
	return 0;
}