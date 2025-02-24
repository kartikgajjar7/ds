class Solution
{
    ListNode* reverseList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *Prv = nullptr;
        while (temp)
        {
            ListNode *Front = temp->next;
            if (Prv == nullptr)
            {
                Prv = temp;
                temp->next = nullptr;
                temp = Front;
            }
            else if (temp->next == nullptr)
            {
                temp->next = Prv;

                head = temp;
                temp = Front;
            }
            else
            {
                temp->next = Prv;
                Prv = temp;

                temp = Front;
            }
        }
        return head;
    }
    public:
        ListNode* removeNodes(ListNode *head)
        {
            head = reverseList(head);
            ListNode *dummy = new ListNode(-1);
            ListNode *mover = dummy;
            ListNode *temp = head;
            int max = head->val;

            while (temp)
            {
                if (temp->val >= max)
                {
       
                    max = temp->val;
                    ListNode *newa = new ListNode(temp->val);
                    mover->next = newa;
                    mover = mover->next;
                }
             temp=temp->next;
            }
            
          
            return reverseList(dummy->next);;
        }
};