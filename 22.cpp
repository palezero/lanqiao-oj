#include <iostream>
#include <vector>
using namespace std;
vector<int> v;	
struct Node;
typedef struct Node XD;
struct Node
{
	int Left;
	int Right;
	int Sum;
	int Max;
};
int sum(vector<int> power, int left, int right)
{
	int return_sum = 0;
	for (int i = left-1; i < right; i++)
		return_sum += power[i];
	return return_sum;
}                  
int max(vector<int> power, int left, int right)
{
	int max = -99999999;
	for (int i = left-1; i < right; i++)
		if(power[i] > max)
			max = power[i];
	return max;
}
void Operate(vector<int> &power, int p, int x, int y)
{
	switch(p){
		case 1: power[x-1] = y;break;
		case 2: v.push_back(sum(power, x, y));break;
		case 3: v.push_back(max(power, x, y));break;
	}
}
int main()
{
	int n, m;
	int p, x, y;
	cin>>n>>m;
	vector<int> power(n);
	for (int i = 0; i < n; i++)
		cin>>power[i];
	for (int i = 0; i < m; i++)
	{
		cin>>p>>x>>y;
		Operate(power, p, x, y);
	}
	for (int i = 0; i < v.size(); i++)
		cout<<v[i]<<endl;
    return 0;
}