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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         int cnt1= 0 ,cnt2=0;
         ListNode * curr1 = l1 , *curr2 = l2 ;
         while(curr1!=NULL){
             cnt1++;
             curr1 = curr1->next;
        }
         while(curr2!=NULL){
             cnt2++;
             curr2 = curr2->next;
        }
        if(cnt1>=cnt2){
            ListNode * temp = l2;
            l2 = l1;
            l1 = temp;
        }
        curr1 = l1 ;
        curr2 = l2 ;
        ListNode * newHead = l2;
        int cnt =0;
        while(curr1 != NULL){
            int Val = curr1->val + curr2->val+ cnt;
            curr2->val = Val % 10;
            cnt = Val / 10;
            if(curr2->next==NULL && cnt){
                 ListNode * newNode = new ListNode(1);
                curr2 -> next = newNode;
                curr2 = NULL;
                break;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr2 != NULL){
            int Val = curr2->val+ cnt;
            //cout << Val << endl;
            curr2->val = Val % 10;
            cnt = Val / 10;
            if(curr2->next==NULL && cnt){
                 ListNode * newNode = new ListNode(1);
                curr2 -> next = newNode;
                break;
            }
            curr2 = curr2->next;
        }
        
        return newHead;
    }
};