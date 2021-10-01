class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new  ListNode();
         ListNode* output=head;
        int c=0; //carry
        while(l1 != 0 || l2 != 0)
        {
            int sum=(l1 != 0 ? l1 ->val :0)+(l2 !=0? l2 ->val :0)+c;
            output ->next = new  ListNode(sum %10);
            output=output ->next;
            c=sum/10;
            l1=(l1 !=NULL ? l1 ->next : NULL);
            l2=(l2 !=NULL ? l2 ->next : NULL);
        }
        if(c==1)
        {
            output ->next = new  ListNode(1);
        }
        return head ->next;
        
    }
};
