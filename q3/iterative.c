/* FIXME: Implement! */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#inclide "iterative.h"
typedef struct TREE_NODE {
    int value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
} TreeNode;
TreeNode *node_initialize(TreeNode *root,int num[],int index,int size)
{
    if(index <size) {
        if(num[index]==0)
            return NULL;
        else {
            root = malloc(sizeof(TreeNode));
            root ->value = num[index];
            root->left  = node_initialize(root ->left, num,index*2+1,size);
            root->right = node_initialize(root ->right, num,index*2+2,size);
            return root;
        }
    } else
        return NULL;
}

void print_btree(TreeNode *root)
{

    if(root) {
        printf("%d\n",root->value);
        //print_btree(root->left);
        print_btree(root->right);
    }
}
void flatten(struct TreeNode* root)
{
    struct TreeNode* leftt;
    while(root!=NULL) {
        if(root->left!=NULL) {
            leftt=root->left;
            while(leftt->right!=NULL) leftt=leftt->right;
            leftt->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        root=root->right;
    }
}
static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

int main()
{
    int num[][]= {{1,2,5,3,4,0,6},{5,4,7,3,NULL,2,NULL,-1,NULL,9},{1,2,NULL,3,NULL,4,NULL,5,NULL},{1,NULL,2,NULL,3,NULL,4,NULL,5}};
    TreeNode *root=NULL;
    int size=(int)(sizeof(num)/sizeof(num[0]));
    struct timespec start, end;
    double cpu_time1;
    for(int i=0;i<4,i++){
      root=node_initialize(root,num[i],0,size);

      printf("before flatten:\n");
      print_btree(root);

      clock_gettime(CLOCK_REALTIME, &start);
      flatten(root);
      clock_gettime(CLOCK_REALTIME, &end);

      printf("after flatten :\n");
      print_btree(root);

      cpu_time1 = diff_in_second(start, end);
      printf("execution time of flatten() : %lf ms\n", cpu_time1);
    }
    return 0;
}
