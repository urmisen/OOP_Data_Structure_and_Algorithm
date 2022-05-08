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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode *temp, *prev;
        struct ListNode *tmp;

        tmp=head;
        int count=0;
        while(tmp!=NULL){
           tmp=tmp->next;
           count++;
        }


        if(count==n){
            temp=head;
            head=head->next;
            delete(temp);
        }
        else{
            int new_index=count-n;
            temp=head;
            int i=0 ;
            while(i<new_index){
                prev=temp;
                temp=temp->next;
                i++;
            }

            prev->next=temp->next;
            delete(temp);
        }
        return head;
    }
};

//time complexity ==> O(n)+O(n) == O(2n)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode *dummy = new ListNode();
        dummy->next=head;
        struct ListNode *fast=dummy;
        struct ListNode *slow=dummy;

        for(int i=1;i<=n;i++){
            fast=fast->next;
        }
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return dummy->next;
    }
};

//time complexity ==> O(n)
//space complexity ==> O(1)
