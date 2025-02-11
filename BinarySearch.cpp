#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
typedef int BTElemType;

typedef struct BTnode{
    BTElemType data;
    struct BTnode *lchild;
    struct BTnode *rchild;
}BTnode,*BTree;

//��α���
void Initial_BinarySearch(BTree &T,BTElemType data){
    BTree p=(BTree)malloc(sizeof(BTnode));
    p->data=data;
    p->lchild=NULL;
    p->rchild=NULL;
    if (T==NULL)
    {
        T=p;
        return;
    }
    BTree parent=NULL,q=T;//parentָ��q�ĸ��ڵ�,T����ֱ��ʹ��
    while (q)
    {
        parent=q;
        if (q->data>data)
        {
            q=q->lchild;
        }else if (q->data<data)
        {
            q=q->rchild;
        }else{
            return;
        }
        
    }
    if (parent->data>data)
    {
        parent->lchild=p;
    }else if (parent->data<data)
    {
        parent->rchild=p;
    }
    
    return;
    
}

//����������ݹ飩
// void Print_Inorder(BTree T){
//     if (T)
//     {
//         Print_Inorder(T->lchild);
//         printf("%3d",T->data);
//         Print_Inorder(T->rchild);
//     }
//     return;
    
// }


//����������ǵݹ飩
void Inorder_Traverse(BTree root){
    BTree p=root;
    BTree *stack;
    int top=-1;
    stack=(BTree *)malloc(sizeof(BTree)*50);
    while (p||top!=-1)
    {
        if (p)
        {
            stack[++top]=p;
            p=p->lchild;
        }else{
            p=stack[top--];
            printf("%3d",p->data);
            p=p->rchild;
        }
    }
    
    free(stack);  
}

//ǰ��������ǵݹ飩
void Preorder_Traverse(BTree root){
    BTree p;
    BTree *s;
    int top=-1;
    s=(BTree *)malloc(sizeof(BTree)*20);
    s[++top]=root;
    while (top!=-1)
    {
        p=s[top--];
        printf("%3d",p->data);
        if (p->rchild)
        {
            s[++top]=p->rchild;
        }
        if (p->lchild)
        {
            s[++top]=p->lchild;
        }
        
        
    }
    free(s);
    
}

//����������ǵݹ飩
void PostOrder(BTree root){
    BTree p=root;
    BTree flag=NULL;
    BTree *stack;
    int top=-1;
    stack=(BTree *)malloc(sizeof(BTree)*20);
    while (p)
    {
        stack[++top]=p;
        p=p->lchild;
    }

    while (top!=-1)
    {
        p=stack[top];
        if (p->rchild  && (p->rchild!=flag))
        {
        p=p->rchild;
        while (p)
        {
            stack[++top]=p;
            p=p->lchild;
        }
        
        }else{
        p=stack[top--];
        printf("%3d",p->data);
        flag=p;
    }
    }
    free(stack);

}

//ͳ�ƶ������ĵĸ߶�
int TreeHeight(BTree r){
    int LL,LR;
    if (!r)
    {
        return 0;
    }else{
        LL=TreeHeight(r->lchild);
        LR=TreeHeight(r->rchild);
        return LL>LR?LL+1:LR+1;
    }
    
}

int cs(){
    
}

//ͳ�ƶ������ķ��ն˽��ĸ���
int NumberLeaves(BTree r){
    int LL,LR;
    if (!r)
    {
        return 0;
    }else{
        LL=NumberLeaves(r->lchild);
        LR=NumberLeaves(r->rchild);
        if (!r->lchild&&!r->rchild)
        {
            return LL+LR+1;
        }
        return LL+LR;
        
    }
    
}

//�ҽ��ĵ�ַ



void Creat(BTree &T,BTElemType *data,int length){
    for(int i=0;i<length;i++){
        Initial_BinarySearch(T,data[i]);
    }
    return;
}

int main(){
    BTree T=NULL;
  
    BTElemType arr[7]={54,20,66,40,28,79,58};
    // while(scanf("%d",&data)!=0)
    // {
       
    //     scanf("%d",&data);
    // }
    Creat(T,arr,7);
    
    // Print_Inorder(T);
    cout<<"�������(�ǵݹ�)"<<endl;
    Inorder_Traverse(T);

    cout<<"ǰ�����(�ǵݹ�)"<<endl;
    Preorder_Traverse(T);

    
    cout<<"�������(�ǵݹ�)"<<endl;
    PostOrder(T);

    cout<<"�������ĸ߶�Ϊ:"<<TreeHeight(T)<<endl;
    cout<<"���ն˽��ĸ���Ϊ:"<<NumberLeaves(T)<<endl;

    return 0;
}