#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val){

    node* n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }
    
    node* temp = head;
    while(temp -> next != NULL){
        temp = temp ->next;
    }
    temp -> next = n;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp -> data <<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

node* mergeLists(node* &head1, node* &head2){

    node* dummyNode = new node(-1);
    node* ptr3 = dummyNode;
    
    node* ptr1 = head1;
    node* ptr2 = head2;

    while(ptr1!= NULL && ptr2!=NULL){
        if(ptr1->data < ptr2 -> data){
            ptr3 -> next = ptr1;
            ptr1 = ptr1 -> next;
            ptr3 = ptr3 -> next;
        }
        else{
            ptr3 -> next = ptr2;
            ptr2 = ptr2 -> next;
            ptr3 = ptr3 -> next; 
        }
    }

    while(ptr1 != NULL){
        ptr3 -> next = ptr1;
        ptr3 = ptr3 -> next;
        ptr1 = ptr1 -> next;
    }
    while(ptr2 != NULL){
        ptr3 -> next = ptr2;
        ptr3 = ptr3 -> next;
        ptr2 = ptr2 -> next;
    }

    ptr3 -> next = NULL;

    return dummyNode -> next;
}

int main(){

    node* head1 = NULL;
    node* head2 = NULL;

    insertAtTail(head1,1);
    insertAtTail(head2,2);
    insertAtTail(head1,3);
    insertAtTail(head2,4);
    insertAtTail(head1,5);
    insertAtTail(head2,6);
    insertAtTail(head1,7);
    insertAtTail(head1,8);
    insertAtTail(head2,9);
    insertAtTail(head2,10);
    insertAtTail(head1,11);

    display(head1);
    display(head2);

    node* newNode = mergeLists(head1, head2);

    display(newNode);

    return 0;
}