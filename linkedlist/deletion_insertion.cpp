#include<iostream>
#include <vector>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    public:
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1 ){
        data = data1;
        next = nullptr;
    }
};
void traversell(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp= temp->next;
    }
}
Node* convertarr2ll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for ( int i = 1 ; i < arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
mover=mover->next;
    }
    return head;
}
Node* removeHead(Node* head){
    if (head==NULL) return head;
    Node* temp = head;
    head=head->next;
    delete temp;
    return head;
}
Node* removeelement(Node* head , int k){
    if(head->data==k){
      Node*  temp = head;
      head = temp->next;
      delete temp;
      return head;
    }
    if (head==NULL) return head;
    Node* temp = head;
    Node* beforetemp ;
    int current = 1;
    while(temp != NULL){

       if(temp->data==k){
        beforetemp->next=temp->next;
        delete temp;
        return head;
       }
        beforetemp = temp;
        temp= temp->next;
current++;
    }
    return head;
}
Node* removekthelement(Node* head , int k){
    if(k==1){
      Node*  temp = head;
      head = temp->next;
      delete temp;
      return head;
    }
    if (head==NULL) return head;
    Node* temp = head;
    Node* beforetemp ;
    int current = 1;
    while(current<=k && temp != NULL){

       if(k==current){
        beforetemp->next=temp->next;
        delete temp;
        
       }
        beforetemp = temp;
        temp= temp->next;
current++;
    }
    return head;
}
Node* addkthelement(Node* head , int k , int data){
    if(k==1){
      Node*  temp = head;
      Node* newnode = new Node(data);
      head=newnode;
      newnode->next=temp;
      return head;
    }
    if (head==NULL) return head;
    Node* temp = head;
    Node* beforetemp ;
    int current = 1;
    while(current <=k && temp != NULL){
       
       if(k==current){
        Node* newnode = new Node(data);
       beforetemp->next = newnode;
    
       newnode->next=temp;
       
      return head;
       }
        beforetemp = temp;
        temp= temp->next;
current++;
    }
    return head;
}
Node* removetail(Node* head){
    if(head->next==nullptr) delete head;
  Node* temp = head;
  while (temp)
  {
    Node* nextoftemp = temp->next;
    if(nextoftemp->next==nullptr){
        temp->next=nullptr;
        delete nextoftemp;
        break;
    }
    temp=temp->next;
  }
  return head;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = convertarr2ll(arr);
    head =removeelement(head ,3 );
    traversell(head);
 
}