#include<stdio.h>

void display(int arr[], int size){
    printf("Traversing\n");
    for (int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int size, int pos, int element){
    printf("Insertion of %d at position %d\n", element, (pos+1));
    for(int i=size; i>=pos; i--){
        arr[i+1] = arr[i];
    }
    arr[pos] = element;
    size += 1;
}

void search(int arr[], int size, int element){
    printf("Searching\n");
    for(int i=0; i<size; i++){
        if (arr[i] == element){
            printf("%d", i);
            return;
        }
    }
    printf("Element not found!\n");
}

void delete(int arr[], int size, int pos){
    for(int i=pos; i<=size; i++){
        arr[i] = arr[i+1];
    }
    size -= 1;
}

void getElement(int arr[], int size, int pos){
    printf("Accessing an element\n");
    for(int i=0; i<=size; i++){
        if (arr[i] == arr[pos]){
            printf ("%d\n", arr[i]);
        }
    }
}

void bubbleSort(int arr[], int size){
    printf("Sorting\n");
    for(int i=0; i<size; i++){
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){ 
    int arr[100]={1,2,6,78};
    display(arr,4);
    insert(arr,4,0,30);
    display(arr,5);
    search(arr,5,20);
    delete(arr,5,2);
    display(arr,4);
    getElement(arr,4,3);
    bubbleSort(arr,4);
    display(arr,4);
    return 0;
}