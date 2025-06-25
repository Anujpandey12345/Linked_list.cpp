
#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    //CunstructorN
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void InsertAtBegining(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void InsertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}
void InsertAtPosition(Node* &tail, Node* &head, int position , int d){
    if(position == 1){
        InsertAtBegining(head, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }
    //Inserting at tail
    if(temp -> next == NULL){
        InsertAtTail(tail, d);
        return;
    }
    //Creating node For D
    Node* NodetoInsert = new Node(d);
    NodetoInsert -> next = temp -> next;
    temp -> next = NodetoInsert;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data<< " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){

    Node* node1 = new Node(10);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;

    Node* head = node1;
    Node* tail = node1;
    print(head);
    InsertAtTail(tail, 12);
    print(head);
    InsertAtTail(tail, 13);
    print(head);
    InsertAtPosition(tail, head, 4, 11);
    print(head);
    cout<<"This is head ::"<< head -> data<<" "<<endl;
    cout<<"This is tail ::"<< tail -> data<<" "<<endl;
}
