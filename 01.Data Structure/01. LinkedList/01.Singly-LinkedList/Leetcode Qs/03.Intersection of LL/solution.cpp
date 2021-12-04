/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode* head1, ListNode* head2) {
        
        int l1=getLength(head1);
        int l2=getLength(head2);
        
    //difference of lengths
        int d=0;
        
        ListNode* ptr1=NULL;
        ListNode* ptr2=NULL;
        
        if(l1>l2)
        {
            d=l1-l2;
            ptr1=head1;
            ptr2=head2;  
        }
        
        else{
            d=l2-l1;
            ptr1=head2;
            ptr2=head1;
        }
        
        while(d!=NULL){
            ptr1=ptr1->next;
            d--;
        }
        
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1==ptr2) 
                return ptr1;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            
        }
        return NULL;
    }
     int getLength(ListNode* head){
        ListNode* t=head;
        int size=NULL;
        while(t!=NULL){
            size++;
            t=t->next;
        }
        return size;
    }
  };