#include<stdio.h>

void display(int arr[], int n){
    printf("Traversing\n");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int n, int pos, int element, int capacity){
    printf("Insertion of %d at index %d\n",element, pos);
    if(n<=capacity){
        for(int i=n; i>=pos; i--){
            arr[i+1] = arr[i];
        }
        n += 1;
        arr[pos] = element;
    }
}

int main(){ 
    int arr[100]={1,2,6,78};
    display(arr,4);
    insert(arr,4,0,30,100);
    display(arr,5);
    return 0;
}