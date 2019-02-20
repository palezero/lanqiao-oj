#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct ListNode;
typedef struct ListNode* List;
typedef struct ListNode
{
	int Element;
	List Next;
}Node;
typedef struct {
	int from;
	int to;
	int power;
}Edge;
typedef struct {
	int d;
	int time;
	int Known;
	int size;
	List Edge;//邻接表
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
		for (List j = V[k].Edge; j != NULL; j = j->Next) {
			int E_temp = j->Element;
			int another = E[E_temp].from + E[E_temp].to - k;
			if(!V[another].Known)
				if(V[another].d > E[E_temp].power)
					V[another].d = E[E_temp].power;
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
		V[i].Edge = NULL;
		V[i].size = 0;
	}
	for (int i = 0; i < Edge_Num; ++i) {
		List Temp;
		cin>>E[i].from>>E[i].to>>E[i].power;
		E[i].power = E[i].power * 2 + V[--E[i].to].time + V[--E[i].from].time;
		Temp = new struct ListNode;
		Temp->Element = i;
		Temp->Next = V[ E[i].to ].Edge;
		V[ E[i].to ].Edge = Temp;
		V[ E[i].to ].size++;
		Temp = new struct ListNode;
		Temp->Element = i;
		Temp->Next = V[ E[i].from ].Edge;
		V[ E[i].from ].Edge = Temp;
		V[ E[i].from ].size++;
	}
	int min = INT_MAX;
	for (int i = 0; i < Vertex_Num; ++i)
		if(V[i].time < min) 
			min = V[i].time;
	Costtime = prim(V, E, sizeof(V) / sizeof(Vertex));
	cout<<Costtime + min<<endl;
	return 0;
}
