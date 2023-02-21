/* 14.1
 * Description
    读取字符串abcdefghij，然后层次建树建立一颗二叉树，然后前序遍历输出abdhiejcfg，注意不要打印前序遍历几个汉字
   Input
    abcdefghij
   Output
    abdhiejcfg
    课时14作业2
    Description
            读取字符串abcdefghij，然后层次建树建立一颗二叉树，
            然后中序遍历输出 hdibjeafcg，后序遍历输出 hidjebfgca，
            层序遍历输出abcdefghij，注意不要输出汉字
    Input
        abcdefghij
    Output
        中序遍历输出hdibjeafcg，后序遍历输出 hidjebfgca，
        层序遍历输出abcdefghij，每个一行
 * */
#include "function.h"
//先序遍历
void PreOrder(BiTree p){
    if(p!=NULL){
//        putchar(p->c);
        printf("%c",p->c);
        PreOrder(p->lchild);//打印左子树
        PreOrder(p->rchild);//打印右子树
    }
}
//中序遍历
void InOrder(BiTree p){
    if(p!=NULL){
        InOrder(p->lchild);//打印左子树
        printf("%c",p->c);
        InOrder(p->rchild);//打印右子树
    }
}
//后序遍历
void PostOrder(BiTree p){
    if(p!=NULL){
        PostOrder(p->lchild);//打印左子树
        PostOrder(p->rchild);//打印右子树
        printf("%c",p->c);
    }
}
//层序遍历
void LevelOrder(BiTree T){
    LinkQueue Q;//辅助队列
    InitQueue(Q);//初始化队列
    BiTree  p;//存储新的树结点
    EnQueue(Q,T);//入队树根
    while(!IsEmpty(Q)){
        DeQueue(Q,p);
        printf("%c",p->c);
        if(p->lchild!=NULL){
            EnQueue(Q,p->lchild);
        }
        if(p->rchild!=NULL){
            EnQueue(Q,p->rchild);
        }
    }
}
int main(){
    BiTree pnew;//用于存储新的树结点
    BiTree tree=NULL;//树根
    ptag_t phead=NULL,ptail=NULL,list_pnew=NULL,pcur;//phead就是队列头，ptail就是队列尾，pcur始终指向要插入的结点的位置
    char c;
    while(scanf("%c",&c)){//输入abcdefghij
        if(c=='\n'){
            break;
        }
        //calloc申请空间并对空间进行初始化，赋值为0
        pnew=(BiTree) calloc(1,sizeof(BiTNode));
        pnew->c=c;//数据放进去
        list_pnew=(ptag_t) calloc(1,sizeof(ptag_t));//给队列结点申请空间
        list_pnew->p=pnew;
        if(NULL==tree){
            tree=pnew;//树根
            phead=list_pnew;//队列头
            ptail=list_pnew;//队列尾
            pcur=list_pnew;
        }else{
            //让元素入队
            ptail->next=list_pnew;//新结点放入链表，通过尾插法
            ptail=list_pnew;//ptail指向队列尾部
            if(pcur->p->lchild==NULL){//如何把新结点放入树
                pcur->p->lchild=pnew;//把新结点放到要插入结点的左边
            }else if(pcur->p->rchild==NULL){
                pcur->p->rchild=pnew;//把新结点放到要插入结点的右边
                pcur=pcur->next;//左右都放了结点后，pcur指向队列的下一个
            }
        }
    }
//    PreOrder(tree);
    InOrder(tree);
    printf("\n");
    PostOrder(tree);
    printf("\n");
    LevelOrder(tree);
    printf("\n");
    return 0;
}
