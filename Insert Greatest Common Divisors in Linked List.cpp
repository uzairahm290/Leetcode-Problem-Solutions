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
    int GCD(int a,int b){
        int minimum = min(a,b);
        for(int i = minimum ; i>=1 ; i-- ){
            if(a % i == 0 && b % i ==0)
             return i;
        }
        return 1;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == nullptr){
            return head;
        }
        ListNode* ans = head;
        while(head->next){
            int x  = GCD (head->val, head->next->val);
            ListNode* temp = new ListNode(x);
            temp->next = head->next;
            head->next = temp;
            head = temp -> next;
        }
        return ans;
    }
};
