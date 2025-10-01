#include<stdio.h>

int main(){
    int A[10][10],i,j,m,n;

    printf("Enter order of matrix A[10][10]: m and n: ");
    scanf("%d %d", &m, &n);

    printf("Enter the elements of matrix A:");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("Elements of matrix A:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ", A[i][j]);
        }
    }
    printf("\n");
    printf("Transpose:\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d ", A[j][i]);
        }
    }

  
    return 0;
}