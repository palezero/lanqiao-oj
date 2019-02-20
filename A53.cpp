#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main()
{
    int time;
    int num;
    cin>>time;
    vector<int> Answer(time);
    for (int i = 0; i < time; ++i) {
        cin>>num;
        vector<int> a(num), b(num);
        for (int j = 0; j < num; ++j)
            cin>>a[j];
        for (int j = 0; j < num; ++j)
            cin>>b[j];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), cmp);
        for (int j = 0; j < num; ++j)
        	Answer[i] += a[j] * b[j];
    }
    for (int i = 0; i < time; ++i)
        cout<<Answer[i]<<endl;
    return 0;
}