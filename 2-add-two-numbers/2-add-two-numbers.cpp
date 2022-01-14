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
        int l1size = 0 ;
        int l2size = 0;
        string totstring ;
       // cout << " l1  = " << l1->val <<endl;
        ListNode *l1temp = l1;
        ListNode *l2temp = l2;
        while( l1 != nullptr ){
            l1size++;
            l1 = l1->next;
        }
        while( l2 != nullptr ){
            l2size++;
            l2 = l2->next;
        }
        int rem = 0;
        
        l1= l1temp;
        l2=l2temp;
        //cout << " l1 size " << l1size << "  l2size = " << l2size <<endl;
        if ( l2size > l1size ){
            ListNode* temp = l1;
            l1 = l2;
            l2 = temp;
        }
        int temptot = 0;
        while (l1 != nullptr ){
          //  cout << " l1 not null " <<endl;
                   temptot = 0;
                   if ( l2!= nullptr )
                     temptot = rem + l2->val + l1->val;
                   else
                        temptot = rem + l1->val;
                   
                   if ( temptot < 10){
                       rem = 0 ;
                       totstring.push_back('0' + temptot);
                   }
                   else if ( temptot >=10 ){
                       int temprem = temptot % 10 ;
                       totstring.push_back('0'+temprem );
                       
                       rem = temptot/10;
                       
                   }
                    l1 = l1->next;
                    if ( l2 != nullptr )
                        l2 = l2->next;
                    
        }
             //   cout <<" testing" << totstring << "value" <<endl;
        if ( temptot >=10 )
            totstring.push_back('0'+rem);
        cout << totstring  <<endl;
        
        int ssize = totstring.size();
        ListNode *head  = nullptr;
        
        head = new ListNode ( (totstring.at(0) - '0' ) );
        auto temp  = head;
        int i = 1;
        while( i < ssize) {
            temp->next = new ListNode(  totstring.at(i) - '0' );
            i++;
            temp = temp->next;
        }
        
        return head;
    }
};