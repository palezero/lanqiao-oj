#include<iostream>
#define HUAN true
#define JIE false
using namespace std;
struct TreeNode;
typedef struct TreeNode* Tree;
struct TreeNode
{
    bool value;
    Tree left;
    Tree right;
};
int idea = 0;
int huan, jie;//还书和借书的人数
void MakeTree(Tree BST, int n)//建bst
{
    if(!n) {BST->left = NULL; BST->right = NULL;return;}
    BST->left = new struct TreeNode;
    BST->right = new struct TreeNode;
    BST->left->value = HUAN;
    BST->right->value = JIE;
    MakeTree(BST->left, n-1);
    MakeTree(BST->right, n-1);
}
void PrintTree(Tree BST)
{
    cout<<"\t";
    cout<<BST->value<<endl;
    if(BST->left != NULL)
        PrintTree(BST->left);
    if(BST->right != NULL)
        PrintTree(BST->right);
}
void Search(Tree BST, int Now_Huan, int Now_Jie, int count)
{
    if(BST != NULL) {
        if(count < 0) return;
        if(Now_Huan == huan && Now_Jie == jie)
        {
            idea++;
            return;
        }
        if(Now_Huan < huan)
            Search(BST->left, Now_Huan+1, Now_Jie, count+1);
        if(Now_Jie < jie)
            Search(BST->right, Now_Huan, Now_Jie+1, count-1);
    }
}
int main()
{
    int count = 0;
    cin>>huan>>jie;
    Tree BST = new struct TreeNode;
    MakeTree(BST, huan+jie);
    Search(BST, 0, 0, count);
    cout<<idea;
    return 0;
}