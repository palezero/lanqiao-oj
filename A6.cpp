#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef struct {
	int from;
	int to;
	int power;
}Edge;
typedef struct {
	int d;
	int time;
	int Known;
	vector<int> Edge;//邻接表
}Vertex;
int prim(Vertex V[], Edge E[], int size) {
	V[0].d = 0;
	for (int i = 1; i < size; ++i) {
		int min = INT_MAX, k = 0;
		for (int j = 1; j < size; ++j)
			if(!V[j].Known) {
				if(V[j].d < min) {
					min = V[j].d;
					k = j;
				}
			}
		V[k].Known = true;
		for (int j = 0; j < V[k].Edge.size(); ++j) {
			int another = E[V[k].Edge[j]].from + E[V[k].Edge[j]].to - k;
			if(!V[another].Known)
				if(V[another].d > E[V[k].Edge[j]].power)
					V[another].d = E[V[k].Edge[j]].power;
		}
	}
	int count = 0; 
	for (int i = 0; i < size; ++i)
		count += V[i].d;
	return count;
}
int main() {
	int Vertex_Num;
	int Edge_Num;
	int Costtime;
	cin>>Vertex_Num>>Edge_Num;
	Edge E[Edge_Num];
	Vertex V[Vertex_Num];
	for (int i = 0; i < Vertex_Num; ++i) {
		cin>>V[i].time;
		V[i].d = INT_MAX;
		V[i].Known = false;
	}
	for (int i = 0; i < Edge_Num; ++i) {
		cin>>E[i].from>>E[i].to>>E[i].power;
		E[i].power = E[i].power * 2 + V[--E[i].to].time + V[--E[i].from].time;
		V[ E[i].to ].Edge.push_back(i);
		V[ E[i].from ].Edge.push_back(i);
	}
	int min = INT_MAX;
	for (int i = 0; i < Vertex_Num; ++i)
		if(V[i].time < min) 
			min = V[i].time;
	Costtime = prim(V, E, sizeof(V) / sizeof(Vertex));
	cout<<Costtime + min<<endl;
	return 0;
}
