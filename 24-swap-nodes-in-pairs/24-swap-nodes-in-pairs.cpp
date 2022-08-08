/**
 * Definition for .singly-linked list.
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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode * curr = head;
        ListNode * prev = NULL;
        if ( head == NULL || head->next == NULL) return head;
        ListNode * orignext;
        if ( curr !=NULL && curr->next != NULL ){
            orignext = curr->next;
            curr->next = orignext->next;
            orignext->next = curr;
            prev=curr;
            curr = curr->next;
            head = orignext;
            
        }
        while ( curr != NULL && curr->next != NULL){
            cout << curr->val <<endl;
            orignext = curr->next;
            curr->next = orignext->next;
            
            orignext->next = curr;
            prev->next = orignext;
                        prev= curr;

            curr = curr->next;
        }
        return head;
    }
};