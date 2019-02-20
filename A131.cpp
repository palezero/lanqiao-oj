#include<iostream>
using namespace std;
typedef struct {
	int Q_Num;
	int* Cost;
	int x;
	int y;
	int m;
}Sci;

int main() {
	int Num_Scist;
	cin>>Num_Scist;
	Sci S[Num_Scist];
	for (int i = 0; i < Num_Scist; ++i) {
		cin>>S[i].Q_Num;
		S[i].Cost = new int [S[i].Q_Num];
		cin>>S[i].Cost[0]>>S[i].x>>S[i].y>>S[i].m;
		for (int j = 1; j < S[i].Q_Num; ++j) 
			S[i].Cost[j] = (S[i].Cost[j-1] * S[i].x + S[i].y) % S[i].m;
	}
	for (int i = 0; i < Num_Scist; ++i) {
		cout<<"Scientist "<<i<<":"<<endl;
		for (int j = 0; j < S[i].Q_Num; ++j) 
			cout<<"    "<<S[i].Cost[j]<<endl;	
	}
	return 0;
}
