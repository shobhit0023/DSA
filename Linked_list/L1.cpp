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
    newNode->next =head;
    head=newNode;
    
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
    temp->next=newNode;
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
        prev->next=newNode;
        newNode->next=curr;


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

    cout<<"\n Inserting at Head "<<endl;

    Node* head = first;

    insertHead(head,50);
    insertHead(head,60);
    print(head);

    cout<<"\nInserting at Tail"<<endl;

    insertTail(head,70);
    insertTail(head,80);
    print(head);

    cout<<endl;
    int count=0;
    cout<<"Length of LL:"<<length_ll(head,count)<<endl;
    cout<<count<<endl;

    cout<<"Inserting at Position"<<endl;  

    insertPosition(head,3,100,count);

    print(head);



    
}
