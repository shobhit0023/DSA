#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node() {
        this->data = 0;
        this->next = 0;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }

};
int length_ll(Node* &head,int &count){
    // int count=0;
    Node* temp = head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
void deleteHead(Node* &head){
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;

    
}
void deleteTail(Node* &head,int &count){
    Node* temp=head;
    int i=1;
    while(i<count-1){
        temp=temp->next;
        i++;
    }
    Node* del = temp->next;
    temp->next = del->next;
    del->next = NULL;
    delete del;
}
void deletePosition(Node* &head,int pos,int &count){
    if(pos==1){
        deleteHead(head);
    }
    if(pos>=count){
        deleteTail(head,count);
    }
    else{
        Node* prev = head;
        int i=0;
        while(i<pos-1){
            prev=prev->next;
            i++;
        }
        Node* curr = prev->next;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        
    }
}
 void print(Node* &head){
         Node* temp = head;  
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        
    }
int main(){

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    first->next = second;
    second->next = third;
    third->next = fourth;

    cout<<"Printing LL:"<<endl;
    print(first);

    Node* head = first;

    cout<<endl;
    int count=0;
    cout<<"Length of LL:"<<length_ll(head,count)<<endl;
    cout<<count<<endl;

    cout<<"Deletion at Head"<<endl;

    // deleteHead(head);

    // print(head);

    // cout<<"\nDeletion at Tail"<<endl;

    // deleteTail(head,count);
    // print(head);

    cout<<"\nDeletion at Position"<<endl;
    deletePosition(head,2,count);
    print(head);

    
}
