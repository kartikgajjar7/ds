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
    for ( int i = 0 ; i < arr.size();i++){
        Node* temp = new Node(arr[0]);
        mover->next = temp;
mover=mover->next;
    }
    return head;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = convertarr2ll(arr);
    traversell(head);
 
}
