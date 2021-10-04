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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)
            return l1;
        else
        {
            if(l1==NULL) return l2;
            else if(l2==NULL) return l1;
        }
        
        if(l1->val > l2->val)
        {
            ListNode* l3=l1; 
            l1=l2; 
            l2=l3; 
        }
        
        ListNode* list=l1;
                
        while(l2)
        {
            while(l1->next!=NULL && l1->val < l2->val && l1->next->val < l2->val )
           {
            l1=l1->next;           
           }
            ListNode* temp1=l2->next;              
            l2->next=l1->next; 
            l1->next=l2; 
            l2=temp1;             
        }
        return list; 
        
    }
};
