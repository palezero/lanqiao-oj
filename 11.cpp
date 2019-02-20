#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
string int2str(int num)
{
	char s[3];
	sprintf(s, "%d", num);
	string temp(s);
	return temp;
}
string An(int num)
{
	string temp;
	for (int i = 1; i <= num; i++)
	{
		temp += "sin(";
		temp += int2str(i);
		if(i!= num)
		{
			if(i%2)
				temp += "-";
			else
				temp += "+";
		}
	}
	temp.append(num,')');
	return temp;
}
string Sn(int n)
{
	string output;
	output.append(n-1,'(');
	for (int i = 1; i <= n ; i++)
	{
		output += An(i);
		output += "+";
		output += int2str(n-i+1);
		if(i!=n)
			output += ")";
	}
	return output;
}
int main()
{
	int num;
	string s;
	cin>>num;
	s = Sn(num);
	cout<<s<<endl;
	return 0;
}