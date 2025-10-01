#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    
    // Creating nodes
    struct node *first=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));

    // Assigning data & connecting nodes
    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = NULL;        // Last node

    // Traversal
    struct node *temp = first;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;      // Moves to next node
    }

    free(first);
    free(second);
    return 0;
}