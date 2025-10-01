#include<stdio.h>

int main(){
    int A[10][10], B[10][10], M[10][10], i,j,k,m,n,p,q;

    printf("Enter order of matrix A[10][10]: m and n: ");
    scanf("%d %d", &m, &n);

    printf("Enter order of matrix B[10][10]: p and q: ");
    scanf("%d %d", &p, &q);
    
    if(n!=p){
        printf("\nMatrix multiplication not possible\n");
        return -1;
    }

    printf("Enter the elements of matrix A:");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of matrix B:");
    for(i=0; i<p; i++){
        for(j=0; j<q; j++){
            scanf("%d", &B[i][j]);
        }
    }

    printf("Elements of matrix A:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ", A[i][j]);
        }
    }
    printf("\n");
    printf("Elements of matrix B:\n");
    for(i=0; i<p; i++){
        for(j=0; j<q; j++){
            printf("%d ", B[i][j]);
        }
    }

    printf("\n");
    printf("Multiplication of Matrices A and B: \n");

    for(i=0; i<m; i++){                 // m,n & p,q then resultant matrix -> m,q
        for(j=0; j<q; j++){
            int sum = 0;
            for(k=0; k<m; k++){         // k from 0 to m coz m(1st matrix's row) is responsible for multiplication
                sum += A[i][k] + B[k][j]; 
            }
            M[i][j] = sum;
        }
    }

    for(i=0; i<m; i++){
        for(j=0; j<q; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}