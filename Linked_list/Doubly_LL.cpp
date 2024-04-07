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
void insertHead(Node* &head,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertTail(Node* &head,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        
    }
    else{
        Node* temp = head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void insertPosition(Node* &head,int pos,int data,int &count){
    if(pos==1){
        insertHead(head,data);
    }
    if(pos>=count){
        insertTail(head,data);
    }
    else{
        Node* prev = head;
        int i=1;
        while(i<pos){
            prev=prev->next;
            i++;
        }
        Node* curr = prev->next;
        Node* newNode = new Node(data);
        newNode->prev = prev;
        prev->next = newNode;
        newNode->next = curr;
        curr->prev = newNode;
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
    cout<<"Length of LL:"<<length_ll(head,count)<<endl;
    cout<<count<<endl;

    cout<<"Inserting at Head"<<endl;
    insertHead(head,50);
    print(head);
    
    cout<<endl;
    cout<<"Inserting at Tail"<<endl;
    insertTail(head,60);
    print(head);

    cout<<endl;
    cout<<"Inserting at Position"<<endl;
    insertPosition(head,3,100,count);
    print(head);

}