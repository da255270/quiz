/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"
#define Debug  1
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

ListNode *detectCycle(ListNode *list)
{
   ListNode *fast=list;
   while(1) {
     if(!(fast->next)) return NULL;
     if(!(fast=fast->next->next)) return NULL;
     list=list->next;
     if(fast==list) return fast;
   }
   return NULL;

}

ListNode *detectCycleNode(ListNode *head){
   ListNode *meetNode = detectCycle(head);
   if(!meetNode)return NULL;
   while(meetNode && head) { 
  #ifdef Debug
     printf("head = %d\n",head->value);
     printf("meetNode = %d\n",meetNode->value);
     for(int i=0;i<100000000;i++); 
  #endif
     if(meetNode==head) return head;
     meetNode = meetNode->next;
     head = head->next;
   }
   return NULL;
}

int main()
{
    ListNode *Head = NULL;
    ListNode *cycleNode;
    struct timespec start, end;

    Head = createlist(Head, 100, 10);

    clock_gettime(CLOCK_REALTIME, &start);
    cycleNode = detectCycleNode(Head);
    clock_gettime(CLOCK_REALTIME, &end);

    if (cycleNode)
        printf("There is a cycle at %d. Run time: %lf msec\n",cycleNode->value, diff_in_second(start, end));
    else
        printf("There is no cycle. Run time: %lf msec\n",diff_in_second(start, end));

    release(Head, cycleNode);

    return 0;
}
