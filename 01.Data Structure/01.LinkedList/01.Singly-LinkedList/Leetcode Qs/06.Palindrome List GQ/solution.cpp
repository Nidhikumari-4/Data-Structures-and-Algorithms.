/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       if(head==NULL||head->next==NULL)
            return true;
        ListNode* ptr=head;
        ListNode* temp=head;
        
        //find midddle of linkedlist
        while(temp->next!=NULL&&temp->next->next!=NULL){
            ptr=ptr->next;
            temp=temp->next->next;
        }
        
        //reverse the right half
        ptr->next=reverseList(ptr->next);
        
        //move ptr  to one more step
        ptr=ptr->next;
        
        //check for left half right half equal or not
        while(ptr!=NULL){
            if(head->val!=ptr->val)
                return false;
            head=head->next;
            ptr=ptr->next;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }

};