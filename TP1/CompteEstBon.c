#include <stdio.h>
#include <stdlib.h>

#define MAX 28

typedef struct {
    int x,y;
} Couple;

//construit tout les couples (pi;pj) de pn
void *creation_couple(int pn[MAX],Couple *t_couples,int n){
    Couple c;
    int cpt = 0; 
    //t_couples = (Couple *)malloc(((n*(n-1))/2)*sizeof(Couple)); // n*(n-1))/2 = 15 car on a exactement 6 nombres
    
    for (int i=0; i<n; i++){
        if(pn[i]!=-1){ // Pour la question 2
            c.x=pn[i];
            for (int j=i+1; j<n; j++){
                if(pn[j]!=-1){ // Pour la question 2
                    c.y=pn[j];
                    t_couples[cpt]=c;
                    cpt++;
                }
            }
        }
    }
}

//fonction permettant de construire les quatre ensembles possibles Pn−1 a partir de Pn
void Pn_precedent(Couple *t_couples,Couple *t1,Couple *t2,Couple *t3,Couple *t4,int *p_precedant, int pn[MAX],int n) {
         //n condition d'arret pour la recursivite
        int ix=-1,iy=-1;
        int cpt=0;
        
        if(n==0){
            return;
        }
        //addition
        p_precedant[0] = t_couples->x + t_couples->y;

        //soustraction
        if(t_couples->x - t_couples->y < 0) {p_precedant[1] = -1; }
        else { p_precedant[1] = t_couples->x - t_couples->y; }

        //multiplication
        p_precedant[2] = t_couples->x * t_couples->y;

        //division
        if((t_couples->x % t_couples->y) != 0) { p_precedant[3] = -1; }
        else { p_precedant[3] = t_couples->x / t_couples->y; }

        for(int i=0; i<5; i++) {
            if(pn[i] == t_couples->x && ix==-1 ){
                ix=i;
                pn[i]=-1;
            }
            if( pn[i] == t_couples->y && iy==-1) {
                iy=i;
                pn[i]=-1;  
            }
        }
        for(int i=0; i<6; i++){
            if(pn[i]!=-1){cpt++;}
        }
        n--;
        pn[ix]=p_precedant[0];
        creation_couple(pn,t1,6);
        Pn_precedent(t1,t1,t2,t3,t4,p_precedant,pn,n);
        if(p_precedant[1]!=-1){
            pn[ix]=p_precedant[1];
            creation_couple(pn,t2,6);
            Pn_precedent(t2,t1,t2,t3,t4,p_precedant,pn,n);
        }
        pn[ix]=p_precedant[2];
        creation_couple(pn,t3,6);
        Pn_precedent(t3,t1,t2,t3,t4,p_precedant,pn,n);
        if(p_precedant[3]!=-1){
            pn[ix]=p_precedant[3];
            creation_couple(pn,t4,6);
            Pn_precedent(t4,t1,t2,t3,t4,p_precedant,pn,n);
        }
        (t_couples++);
}

//fonction d exploration verifiant si un resultat R est atteignable ou non a partir de Pn.
int est_atteignable(int *p_precedant, int taille_t_couple ,int R) {

    int cpt; // compteur nous permettant de savoir si on depasse le nombre d etape max (n-1)

    for(int i = 0; i < taille_t_couple; i++) {
        for(int j = 0; i*j < 4; i++) { //Pour chaque operation..
            if(p_precedant[j] == R) { return 1; }
        }
    }     

    return 0;
}
    
/*

//retourne la ligne de calcul permettant d atteindre le resultat R
int est_atteignable(int *p_precedant,int n, int R) {
    for(int i = 0; i < 4; i++) {
        if(p_precedant[i] == R) { }
    }
    return 0;
}*/



int main() {
    Couple *t_couples=NULL;
    t_couples = (Couple *)malloc(((6*(6-1))/2)*sizeof(Couple));
    Couple *t1=NULL, *t2=NULL, *t3=NULL, *t4=NULL;
    t1 = (Couple *)malloc(15*sizeof(Couple));
    t2 = (Couple *)malloc(15*sizeof(Couple));
    t3 = (Couple *)malloc(15*sizeof(Couple));
    t4 = (Couple *)malloc(15*sizeof(Couple));
    int pn[5];
    int n=5;
    int *p_precedant;
    p_precedant=(int *)malloc(4*sizeof(int));
    int total_precedent[(n*(n-1))/2][4];
    int *t_R;
    

    pn[0]=2;
    pn[1]=10;
    pn[2]=100;
    pn[3]=1;
    pn[4]=1;
    pn[5]=1;

    
    creation_couple(pn, t_couples, 3);
    for (int i=0; i<6; i++){
    }
    /*for (size_t i = 0; i < 10; i++)
    {
        printf("%d %d\n",t[i].x,t[i].y);
    }*/
    Pn_precedent(t_couples, t1, t2, t3, t4, p_precedant,pn,6);

    
    for (size_t i = 0; i < 3; i++) {
        printf("%d %d\n",t1[i].x,t2[i].y);
    }


   /* for(int i = 0; i < 4; i++) {
        printf("%d\t", p_precedant[i]);
    }*/
    //printf("%d", est_atteignable(p_precedant, 30));
    
    
}