#include <stdio.h>
#include <string.h>
int N=0;
void LU_factorization(int **a, int **l, int **u, int **p){
/***************************************************
Student fill in this space with their own code.
***************************************************/
}
void Solve(int **a, int **l, int **u, int *pb, int *x){
/***************************************************
Student fill in this space with their own code.
***************************************************/
}
int main(){
int **A,**L,**U, **P, *pb, *b, *x;
int i, j, c, count=1;
FILE * in, *out;
/* Open the files. */
in = fopen("input.txt","rt");
out = fopen("output.txt", "at");
fscanf(in, "%d", &c);
while(count <= c){
fscanf(in, "%d", &N);
/* Generate and initialize the matrices A, L, U, P, x, b, pb */
/***************************************************
Student fill in this space with their own code.
***************************************************/
/* Read the input */
for(i=0;i<N;i++)
for(j=0;j<N;j++)
fscanf(in,"%d",&A[i][j]);
for(i=0;i<N;i++)
fscanf(in, "%d",&b[i]);
/* LU factorization of PA */
LU_factorization(A,L,U,P);
for(i=0; i<N; i++){
pb[i] = 0;
for(j=0; j<N; j++)
pb[i] += P[i][j]*b[j];
}
/* Solve PAx=Pb */
Solve(A, L, U, pb, x);
/* Output the results */
fprintf(out,"Case %d:\n", count);
fprintf(out, "L\n");
for(i=0;i<N;i++){
for(j=0;j<N;j++){
fprintf(out ,"%d\t",L[i][j]);
}
fprintf(out ,"\n");
}
/* Do the same for U, P, and x */
/***************************************************
Student fill in this space with their own code.
***************************************************/
count++;
}
fclose(in); fclose(out);
return 0;
}
