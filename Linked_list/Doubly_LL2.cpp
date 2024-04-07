#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(){
        this->data=0;
        this->next=NULL;
        this->prev=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
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
    if(head==NULL){
        return;
    }
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
}
void deleteTail(Node* &head,int &count){
    if(head==NULL){
        return;
    }
    if(head->next == NULL){
        deleteHead(head);
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    Node* del = temp->prev;
    temp->prev = NULL;
    del->next = NULL;
    delete temp;

        
}
void deleteAtPosition(Node* &head,int pos,int &count){
    if(pos==1){
        deleteHead(head);
    }
    if(pos>=count){
        deleteTail(head,count);
    }
    else{
        Node* left = head;
        int i=1;
        while(i<pos-1 ){
            left=left->next;
        }
        Node* curr=left->next;
        Node* rght=curr->next;
        left->next=rght;
        rght->prev=left;
        curr->next=NULL;
        curr->prev=NULL;
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
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    cout<<"Printing LL:"<<endl;
    print(first);

    Node* head = first;
    cout<<endl;

    int count=0;
    // cout<<"Length of LL:"<<length_ll(head,count)<<endl;
    // cout<<count<<endl;

    // cout<<"Deleting Head"<<endl;
    // deleteHead(head);
    // print(head);

    // cout<<endl;
    // cout<<"Deleting Tail"<<endl;
    // deleteTail(head,count);
    // print(head);

    cout<<endl<<"Length of LL:"<<length_ll(head,count)<<endl;

    cout<<endl;
    cout<<"Deletion at Position"<<endl;
    deleteAtPosition(head,2,count);
    print(head);



}