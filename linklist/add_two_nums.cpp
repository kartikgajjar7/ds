class Solution
{
    public:
        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            ListNode *dummy = new ListNode(-1);
            ListNode *temp = dummy;
            int carry = 0;
            while (l1 || l2)
            {
                int vall1;
                int vall2;
                if (l1)
                {
                    vall1 = l1->val;
                }
                else
                {
                    vall1 = 0;
                }
                if (l2)
                {
                    vall2 = l2->val;
                }
                else
                {
                    vall2 = 0;
                }

                int sum = carry + vall1 + vall2;
                carry = sum / 10;
                ListNode *newnode = new ListNode(sum % 10);
                temp->next = newnode;
                temp = newnode;
                if (l1) l1 = l1->next;
                if (l2) l2 = l2->next;
            }
            if(carry){
                  ListNode *newnode = new ListNode(carry);
                temp->next = newnode;
            }
            return dummy->next;
        }