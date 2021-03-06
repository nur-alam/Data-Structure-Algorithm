#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

Node* create_node(int data,Node* next){
    Node *newnode = (Node* )malloc(sizeof(Node));
    if(newnode==NULL){
        printf("Error! Could Not Create A New Node\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = next;
    return  newnode;
}


void print_linkedlist(Node* head){
    while (head!=NULL){
        cout << head->data << " " << endl;
        head = head->next;
    }
}

void print_reverse(Node* head){
    if(head==NULL)
        return;
//    cout << head->data << endl;
    print_reverse(head->next);
    cout << head->data << endl;
}

void prepend(int data,Node** head){
    Node* newnode = create_node(data,*head);
    *head = newnode;
}


void append(int data, Node** head_ref, Node** tail_ref){
    Node* newnode = create_node(data,NULL);
    if(*head_ref==NULL){
        *head_ref = newnode;
    }else{
        (*tail_ref)->next = newnode;
    }
    (*tail_ref) = newnode;
}

Node* delete_node(Node* head,int position){
    if(position  == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
    }else{
        Node* temp = head;
        for (int i = 1; i <= position - 2; i++) {
            temp = temp->next;
        }
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
    return head;
}

void sorted_insert(int data , Node** head_ref, Node** tail_ref){
    Node* newnode = create_node(data,NULL);
    if(*head_ref == NULL || (*head_ref)->data > newnode->data){
        newnode->next = (*head_ref);
        (*head_ref) = newnode;
    }else{
        Node *temp = (*head_ref);
        Node *temp2 = temp->next;
        while (temp2 != NULL && newnode->data > temp2->data){
            temp = temp2;
            temp2 = temp2->next;
        }
        temp->next = newnode;
        newnode->next = temp2;
    }

}

int main() {

    Node *head = NULL,*tail=NULL;
    sorted_insert(22,&head,&tail);
    sorted_insert(14,&head,&tail);
    sorted_insert(16,&head,&tail);
    sorted_insert(1,&head,&tail);
    //head = delete_node(head,4);
    print_linkedlist(head);
    //print_reverse(head);

    return 0;
}
