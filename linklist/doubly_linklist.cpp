#include<iostream>
#include <vector>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1 ,Node* back1 ,Node* next1){
        data = data1;
        next = next1;
        back = back1;
    }
    public:
    Node(int data1 ){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node* removetail(Node* head){
    if(head->next==nullptr) delete head;
  Node* temp = head;
  while (temp)
  {
    Node* nextoftemp = temp->next;
    if(nextoftemp->next==nullptr){
        nextoftemp->back=nullptr;
      temp->next = nullptr;
      delete temp;
    }
    temp=temp->next;
  }
  return head;
}
Node* removek(Node* head , int k ){
    Node* temp = head;
    int current = 0;
   while ( temp != nullptr ){
       if(current==k){
           break;
            
       }
       temp = temp->next ;
       current ++;
   }
   if(temp==nullptr) return NULL;
   Node* before = temp->back;
   Node* after = temp->next;
    if(before==nullptr && after==nullptr){
       cout<<"In";
   delete temp;
   return NULL;
   }
   if(before==nullptr){
       after->back = nullptr;
       temp->next =nullptr;
       delete temp;
       return after;
   }
     if(after==nullptr){
       before->next = nullptr;
       temp->back =nullptr;
       delete temp;
       return head;
   }
  
   before->next = after;
   after -> back = before;
   delete temp;
   return head;
   
  
}
void traverseDoublyList(Node* head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* convertarr2ll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for ( int i = 1 ; i < arr.size();i++){
        Node* temp = new Node(arr[i] , mover ,nullptr);
    mover->next=temp;
        mover= temp;

    }
    return head;
}int main(){
    
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = convertarr2ll(arr);
    Node* headreal = removek(head , 7);
    traverseDoublyList(headreal);
 
}