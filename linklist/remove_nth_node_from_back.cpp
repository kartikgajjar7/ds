class Solution
{
    public:
        ListNode* removeNthFromEnd(ListNode *head, int n)
        {
            ListNode *temp = head;
            std::vector<ListNode*> v;
            while (temp)
            {
                v.push_back(temp);
                temp = temp->next;
            }

            if (n == 1 && v.size() > 1)
            {
                ListNode *lastbefore = v[v.size() - 2];
                lastbefore->next = nullptr;
                return head;
            }
            if (v.size() - n == 0)
            {
                head = head->next;
                return head;
            }
            ListNode *crr = v[v.size() - n];
            ListNode *crrbf = v[v.size() - (n+1)];
             ListNode *crraf = v[v.size() - (n-1)];
             crrbf->next=crraf;
            return head;
        }