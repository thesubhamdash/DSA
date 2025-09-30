#include<stdio.h>

int main(){
    int A[10][10], B[10][10], S[10][10], i,j,m,n,p,q;

    printf("Enter order of matrix A[10][10]: m and n: ");
    scanf("%d %d", &m, &n);

    printf("Enter order of matrix B[10][10]: p and q: ");
    scanf("%d %d", &p, &q);
    
    if(n!=p || m!=q){
        printf("\nMatrix order mismatch\n");
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
    printf("Addition of Matrices A and B: \n");

    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            S[i][j] = A[i][j] + B[i][j];
        }
    }

    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ", S[i][j]);
        }
    }
    return 0;
}