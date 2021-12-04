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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
         // Empty list
        if (head == NULL) {
            return head;
        }

        ListNode* cur = head;
        ListNode* prev = NULL;
        while (m > 1) {
            prev = cur;
            cur = cur->next;
            m--;
            n--;
        }


        ListNode* ptr = prev;
        ListNode* tail = cur;

        //  reverse the nodes until n becomes 0.
        ListNode* third = NULL;
        while (n > 0) {
            third = cur->next;
            cur->next = prev;
             prev = cur;
            cur = third;
            n--;
        }


        if (ptr != NULL) {
            ptr->next = prev;
        } else {
            head = prev;
        }

        tail->next = cur;
        return head;
    }
};