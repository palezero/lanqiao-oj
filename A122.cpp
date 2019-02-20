#include<iostream>
#define HUAN true
#define JIE false
using namespace std;
struct TreeNode;
typedef struct TreeNode* Tree;
struct TreeNode
{
    Tree left;
    Tree right;
};
int idea = 0;
int huan, jie;//还书和借书的人数
void MakeTree(Tree BST, int Now_Huan, int Now_Jie, int count)//建bst
{
	if(count < 0) return;
    if(Now_Huan > huan || Now_Jie > jie) return;
	if(Now_Huan == huan && Now_Jie == jie) {
		idea++;return;
	}	
    if(Now_Huan < huan) {
    	BST->left = new struct TreeNode;
    	MakeTree(BST->left, Now_Huan+1, Now_Jie, count+1);	
    }
    if(Now_Jie < jie) {
    	BST->right = new struct TreeNode;
   	 	MakeTree(BST->right, Now_Huan, Now_Jie+1, count-1);
    }
}
int main()
{
    cin>>huan>>jie;
    Tree BST = new struct TreeNode;
    MakeTree(BST, 0, 0, 0);
    cout<<idea;
    return 0;
}