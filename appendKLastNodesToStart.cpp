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

node* appendKToStart(node* &head, int k){

    node* temp = head;
    int l = 1;
    while(temp -> next != NULL){
        temp = temp -> next;
        l++;
    }
    
    int count = 1;

    temp = head;

    node* newTail;
    node* newHead;
    node* tail;
    while(temp != NULL){
        temp = temp -> next;
        count++;
        if(count == (l-k)){
            newTail = temp;
        }
        if(count == (l-k + 1)){
            newHead = temp;
        }
        if(count == l){
            tail = temp;
        }
    }

    tail -> next = head;
    head = newHead;
    newTail -> next = NULL;

    return newHead;
}


int main(){

    node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    appendKToStart(head, 3);
    display(head);

    return 0;
}