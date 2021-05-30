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

void insertAtHead(node* &head, int val){
    node* n = head;
    n -> next = head;
    head = n;
}

bool search(node* head, int key){
    node* temp = head;
    while(temp != NULL){
        if(temp -> data == key){
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

void deleteAtHead(node* &head){

    node* todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(node* &head, int val){

    if(head == NULL){
        return;
    }

    if(head -> next == NULL){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    while(temp -> next -> data != val){
        temp = temp -> next;
    }
    node* todelete = temp -> next;
    temp -> next = temp -> next -> next;
    delete todelete;
}

node* reverse(node* &head){

    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr != NULL){
        nextptr = currptr -> next;
        currptr -> next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

int main(){

    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    node* newhead = reverse(head);
    display(newhead);
    return 0;
}