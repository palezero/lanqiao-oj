#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define NONE -1
typedef struct{
	char cmd;
	int value;
} Element;
void scan(string s, vector<Element> &v)	{
	//将原始字符串读成运算符或者数的形式
	vector<int> fifo;
	int temp = 0;
	int count = 1;
	for (int i = 0; i < s.size(); ++i)
		if(s[i] > '9' || s[i] < '0')
			v.push_back((Element){s[i], NONE});
		else{
			fifo.push_back(s[i]-0x30);
			if(i == s.size()-1 || (s[i+1] > '9' || s[i+1] < '0')){
				for (int i = fifo.size()-1; i >=0 ; i--,count*=10)
					temp += fifo[i] * count;
				v.push_back((Element){NONE,temp});
				fifo.clear();
				temp = 0;count =1;
			}
		}
}
// void find_kuohao(vector<Element> &v, int left, int right, int* Re_left, int* Re_right)	{
// 	//寻找括号的位置，如果没找到就返回-1
// 	*Re_left = *Re_right = NONE;
// 	for (int i = left; i <= right; ++i)
// 		if(v[i].cmd == '('){
// 			*Re_left = i;	
// 			break;
// 		}
// 	for (int i = right; i >= left; --i)
// 		if(v[i].cmd == ')'){
// 			*Re_right = i;
// 			break;
// 		}
// 	if(*Re_left != NONE && *Re_right != NONE) {
// 		v.erase(v.begin() + *Re_left);
// 		v.erase(v.begin() + *Re_right-1);
// 		process(v, v.begin() + *Re_left, v.begin() + *Re_left-2);
// 	}
// }
void find_md(vector<Element> &v, int left, int right, int* Re_left, int* Re_right)
{
	*Re_left = *Re_right = NONE;
	int temp;
	for (vector<Element> *it = v.nbegin(); it != v.end() ; ++it) {	
		if((*it).cmd == '*') {
			temp = (*(it-1)).value * (*(it+1)).value;
			v.insert(it, (Element){NONE,temp});
			// v.erase(it,it+1);	
		}
	}
}
// void process(vector<Element> &v, int left , int right)	{
// 	//处理函数
// 	int kh_l, kh_r;
// 	find_kuohao(v, left, right, &kh_l, &kh_r);
// 	if(kh_l == NONE || kh_r == NONE) {
// 		//在这个区间内无括号存在	
// 		while(v.size() > 1) {
// 			//不断运算，最后只剩下一个数
// 			while(v.cmd == )//先判断有没有乘除号
// 		}
// 	}
// 	else
// 	{
		
// 		process(v, kh_l , kh_r-2);
// 	}
// }
int main()
{	
	int left, right;
	vector<Element> v;
	string s;
	cin>>s;
	scan(s, v);	
	// find_kuohao(v, 0, v.size()-1, &left, &right);
	find_md(v, 0, v.size()-1 , &left, &right);
	for (int i = 0; i < v.size(); ++i)
	{
		if(v[i].cmd == NONE)
			cout << v[i].value<<" ";
		else
			cout << v[i].cmd<<" ";
	}
	// cout<<endl<<left<<" "<<right-2<<endl;
	// process(v, 0, s.size()-1);
	return 0;
}