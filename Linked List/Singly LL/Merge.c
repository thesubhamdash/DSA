#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

void traverse(struct node*head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next; 
    }
    printf("\n");
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

struct node*Merge(struct node*head1, struct node*head2){
    if (head1==NULL){
        return head2;
    }
    if (head2==NULL){
        return head1;
    }
    struct node*temp=head1;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next=head2;
    return head1;
}


int main(){
    struct node *first1 = (struct node*)malloc(sizeof(struct node));
    struct node *second1 = (struct node*) malloc(sizeof(struct node));
    struct node *third1 = (struct node*)malloc(sizeof(struct node));

    struct node *head1 = first1;

    first1->data=10;
    first1->next=second1;

    second1->data=20;
    second1->next=third1;

    third1->data=30;
    third1->next=NULL;

    struct node *first2 = (struct node*)malloc(sizeof(struct node));
    struct node *second2 = (struct node*) malloc(sizeof(struct node));
    struct node *third2 = (struct node*)malloc(sizeof(struct node));

     struct node *head2 = first2;

    first2->data=40;
    first2->next=second2;

    second2->data=50;
    second2->next=third2;

    third2->data=60;
    third2->next=NULL;

    printf("Original List\n");
    traverse(head1);
    traverse(head2);

    // head1 = insertAnywhere(head1,15,3);
    // head2 = insertAnywhere(head2,15,3);
    // printf("After Insertion at any position\n");
    // traverse(head2);
    // traverse(head2);

    Merge(head1, head2);
    printf("List after merging\n");
    traverse(head1);

    //This is to free every node created in the list
    struct node *temp1;
    while(head1 != NULL){
        temp1 = head1;
        head1 = head1->next;
        free(temp1);
    }
    struct node *temp2;
    while(head1 != NULL){
        temp2 = head2;
        head2 = head2->next;
        free(temp2);
    }
    return 0;
}
