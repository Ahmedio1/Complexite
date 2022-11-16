#include <stdio.h>

void erastothene(int n){
    int tab[n];
    int m;
    for(int i=1;i<=n;++i){
        tab[i-1]=0;
    }
    tab[0]=1;
    for (int i=1;i<n;++i){
            if(tab[i]!=1){
                m= (i+1)*2;
                while (m<n){
                    tab[m]=1;
                    m+=i;
                }     
            }
    }

    for (int i=0;i<n;i++){
        printf("%d=tab[%d]\n",tab[i],(i+1));
    }
}

int main(){
    erastothene(20);
    return 0;
}