#include <iostream>
#include <map>
using namespace std;
int main() {
	int count = 0;
	int stu, paint, sum, temp;
	map<int, int> ans;
	cin>>stu>>paint;
	int m;
	for (int i = 0; i < stu; ++i) {
		sum = 0;
		for (int j = 0; j < paint; ++j) {
			cin>>temp;
			temp<<=1;
			sum|=temp;
		}
		ans[sum]++;
	}
	m = 0;
	for (int i = 0; i < paint; ++i) {
		m <<= 1;
		m |= 1;
	}
	for (map<int, int >::iterator it = ans.begin(); it != ans.end(); ++it) {
		map<int, int >::iterator it_r;
		it_r = ans.find(it->first);
		if(it_r != ans.end()) {
			cout<<it->second<<" "<<it_r->second<<endl;
			count += it_r->second * it->second;
		}
	}
	cout<<count<<endl;
	return 0;
}