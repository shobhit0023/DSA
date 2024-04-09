// // ***** FInd the middle element of the linked list**********

// #include <iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(){
//         this->data=0;
//         this->next=NULL;

//     }
//     Node(int data){
//         this->data=data;
//         this->next=NULL;
//     }
// };
// Node* mid(Node* head){
//     if(head == NULL || head->next == NULL){
//         return head;
//     }
//     Node* slow = head;
//     Node* fast = head;
//     while(slow != NULL && fast != NULL )
//     {
//         fast=fast->next;
//         if(fast!=NULL){
//             slow=slow->next;
//             fast=fast->next;
//         }
//     }
//     return slow;
// }
// void print(Node* &head){
//     Node* temp=head;
//     while(temp != NULL){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
// }
// int main(){
//     Node* head = new Node(10);
//     Node* second = new Node(20);
//     Node* third = new Node(30);
//     Node* fourth = new Node(40);
//     Node* fifth = new Node(50);

//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = NULL;  

//     cout<<"Printing LL:"<<endl;
//     print(head);    

//     cout<<endl;
//     cout<<"Middle element of LL:"<<mid(head) ->data<<endl;
    
// }

#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data=0;
        this->next=NULL;

    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void print(Node* &head){
     Node* temp=head;
    while(temp != NULL){
     cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node* k_rever(Node* &head,int k){
    Node* prev = NULL;
    Node* curr= head;
    Node* frwrd = NULL;
    int count=0;
    while(count < k && curr!=NULL){
        frwrd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=frwrd;
        count++;
    }
    if(frwrd!=NULL){
        head->next=k_rever(frwrd,k);
      }
    
      return prev;  
}
int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // fifth->next = NULL;  

    cout<<"Printing LL:"<<endl;
    print(head);    

    cout<<endl;
   
    cout<<"Reversing LL:"<<endl;
    head=k_rever(head,2);
    print(head);
}