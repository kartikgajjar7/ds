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
Node* Reversedll(Node* head){
    Node* temp = head;
    Node* lastelement = NULL;
    while(temp != nullptr){
        lastelement = temp;
        Node* aagewala = temp->back;
        Node* pichewala = temp->next;
        temp->next = aagewala;
        temp->back = pichewala;
        temp=temp->next;
    }
    return lastelement;
    
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
}
void traversell(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp= temp->next;
    }
}
int main(){
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = convertarr2ll(arr);
    Node* travers = Reversedll(head);
    traversell(travers);
 
}