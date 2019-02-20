#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
typedef struct EdgeNode {
	int Front;//出节点
	int Back;//入节点
	int Power;//权值
	int Next;//同一个出节点的下一条边，如果没有就是-1
}Edge;
typedef struct VertexNode {
	int dis;//该节点和源节点的距离
	int Head;//该节点为出节点的第一条边
	int temp;//该节点为出节点的当前边
	bool Visited;//当前是否在队列中
}Vertex;

int main() {
    int Edge_Num, Vertex_Num;
    int Source = 0;
    queue<int> Q;
    scanf("%d %d", &Vertex_Num, &Edge_Num);
    Vertex V[Vertex_Num];
    Edge E[Edge_Num];

    for (int i = 0; i < Vertex_Num; ++i) {
	    V[i].dis = INT_MAX;//以节点遍历初始化
	    V[i].Visited = false;
	    V[i].temp = -1;
	    V[i].Head = -1;
    }

    for (int i = 0; i < Edge_Num; ++i) {
    	E[i].Next = -1;
    	scanf("%d%d%d", &E[i].Front, &E[i].Back, &E[i].Power);
        E[i].Front--;
        E[i].Back--;
        int j = E[i].Front;
        if(V[j].Head != -1) 
        	E[V[j].temp].Next = i;//链式存储
        else 
        	V[j].Head = i;
        V[j].temp = i;
    }

    V[Source].Visited = true;//源点初始化
    V[Source].dis = 0;
    Q.push(Source);

    while(!Q.empty()) {
        int temp = Q.front();
        Q.pop();
        V[temp].Visited = false; 
        int Now_E = V[temp].Head;
        while(Now_E != -1) {
    		int v = E[Now_E].Back;
    		if(V[temp].dis + E[Now_E].Power < V[v].dis) {
    			V[v].dis = V[temp].dis + E[Now_E].Power;
    			if(!V[v].Visited) {
    				Q.push(v);
    				V[v].Visited= true;
    			}
    		}
        	Now_E = E[Now_E].Next;
        }
    }

    for (int i = 0; i < Vertex_Num; ++i) {
        if(i != Source)
            cout<<V[i].dis<<endl;
    }
    return 0;
}