#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void traverse(struct node*head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next; 
    }
    printf("\n");
}

struct node *insertAtBeginning(struct node*head, int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    return newnode;
}

struct node *insertAtEnd(struct node *head, int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(head == NULL){
        head = newnode;
        return head;
    }
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

struct node *insertAnywhere(struct node *head, int value, int pos){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if (pos == 1){
        newnode->next = head;
        head = newnode;
        return head;
    }
    struct node *temp=head;
    int count =1;
    while(count<pos-1 && temp != NULL){
        temp = temp->next;
        count += 1;
    }
    if(temp == NULL){
        printf("\nPosition out of range\n");
        return head;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

struct node *deleteAtBeginning(struct node*head){
    if(head==NULL){
        printf("List is empty\n");
        return head;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node *deleteAtEnd(struct node*head){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    if(head->next == NULL){
        free(head);
        head=NULL;
        return head;
    }
    struct node*temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    struct node*toDel = temp->next;
    temp->next=NULL;
    free(toDel);
    return head;
}

struct node *deleteAnywhere(struct node*head, int pos){
    if(head==NULL){
        printf("List is empty\n");
        return head;
    }
    if(pos==1){
        head = deleteAtBeginning(head);
        return head;
    }
    struct node*temp = head;
    int count = 1;
    while(count<pos-1 && temp!=NULL){
        temp = temp->next;
        count += 1;
    }
    if(temp==NULL || temp->next==NULL){
        printf("Position is out of range\n");
        return head;
    }
    struct node*toDel=temp->next;
    temp->next=toDel->next;
    free(toDel);
    return head;
}

struct node *reversal(struct node*head){
    struct node *prev=NULL;
    struct node *current = head;
    while(current != NULL){
        struct node*nextnode = current->next;
        current->next = prev;
        prev = current;
        current=nextnode;
    }
    head = prev;
    return head;
}

int main(){
    struct node *first = (struct node*)malloc(sizeof(struct node));
    struct node *second = (struct node*) malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));

    struct node *head = first;

    first->data=10;
    first->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;

    printf("Original List\n");
    traverse(head);

    head = insertAtBeginning(head,5);
    printf("After Insertion at beginning\n");
    traverse(head);

    head = insertAtEnd(head,40);
    printf("After Insertion at end\n");
    traverse(head);

    head = insertAnywhere(head,15,3);
    printf("After Insertion at any position\n");
    traverse(head);
   
    head = deleteAtBeginning(head);
    printf("After Deletion of head\n");
    traverse(head);

    head = deleteAtEnd(head);
    printf("After Deletion at end\n");
    traverse(head);

    head = deleteAnywhere(head,3);
    printf("After deletion at any position\n");
    traverse(head);

    head = reversal(head);
    printf("After Reversal of the list\n");
    traverse(head);

    //This is to free every node created in the list
    struct node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}