#include <stdio.h>


void fusion(int tab[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1];
    int R[n2+1];
    int i,j,k;
    for (i=0;i<n1;i++){
        L[i]=tab[p+i-1];
    }
    for (j=0;j<n2;j++){
        R[j]=tab[q+j];
    }
    L[n1]=1000000;
    R[n2]=1000000;
    i=0;
    j=0;
    for (k=p;k<r;k++){
        if (L[i]<=R[j]){
            tab[k]=L[i];
            i=i+1;
        }
        else{
            tab[k]=R[j];
            j=j+1;
        }
    }
}
// tri fusion
void tri_fusion(int tab[],int p,int r){

    if (p<r){
        int q=(p+r)/2;
        tri_fusion(tab,p,q);
        tri_fusion(tab,q+1,r);
        fusion(tab,p,q,r);
    }
}



int main(){
    int tab[10]={5,2,4,7,1,3,2,6,8,9};
    tri_fusion(tab,1,10);
    int i;
    for (i=0;i<10;i++){
        printf("%d ",tab[i]);
    }
    return 0;
}