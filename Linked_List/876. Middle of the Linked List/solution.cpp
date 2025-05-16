
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        count=count/2;
        while(count){
            head=head->next;
            count--;
        }        
        return head;
    }
};