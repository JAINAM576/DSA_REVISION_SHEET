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
    bool hasCycle(ListNode *head) {
ListNode*temp=head;
if(head==NULL || head->next==NULL || head->next->next==NULL)return false;
ListNode*temp1=head->next->next;

        while(temp!=temp1){
            if(temp==NULL || temp1==NULL ||  temp1->next==NULL)return false;
            temp=temp->next;
            temp1=temp1->next->next;

        }
        return true;
    }
};