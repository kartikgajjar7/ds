//USING ARRAY
{
    public:
        ListNode* reverseList(ListNode *head)
        {
            if (!head) return nullptr;
            ListNode* temp = head;
            std::vector<ListNode*> v;
            while (temp)
            {
                v.push_back(temp);
                temp = temp->next;
            }
   
            for(int i = v.size()-1 ; i >0 ;  i--){
               v[i]->next = v[i-1];

            }
            v[0]->next = nullptr;
          
            return v.back();
        }
};
//Iterative Approch
class Solution
{
    public:
        ListNode* reverseList(ListNode *head)
        {
            ListNode *temp = head;
            ListNode *Prv = nullptr;
            while (temp)
            {
                ListNode *Front = temp->next;
                if (Prv == nullptr)
                {
                    Prv=temp;
                    temp->next = nullptr;
                    temp= Front;
                }
                else if(temp->next==nullptr){
                    temp->next=Prv;
                
                    head=temp;
                    temp= Front;
                }
                else
                {
                    temp->next = Prv;
                    Prv=temp;
                    
                    temp = Front;
                }
            }
            return head;
        }
};