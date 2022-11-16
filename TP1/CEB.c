#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int v1, v2;
    int i1, i2;
} Couple ;

void printf_tirages(int *tirage, int taille, int profondeur) {
    //taille = taille du tab tirage
    printf("\t====== TIRAGE ======\n");
    for(int i = 0; i < profondeur; i++) {
        printf("\t");
    }

    for(int i = 0; i < taille; i++) {
        printf("%d\t", tirage[i]);
    }
    printf("\n");
}

void printf_erreur(char *erreur, int profondeur) {
    for(int i = 0; i < profondeur; i++) {
        printf("\t");
    }
    printf("%s\n", erreur);
}

void tirage_aleatoire(int t_out[6]) {
    /*  — 20 plaques numérotées de 1 à 10 (2 par nombre)
        — 2 plaques de 25
        — 2 plaques de 50
        — 2 plaques de 75
        — 2 plaques de 100*/
    
    int t[28] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10,
                 25, 25, 50, 50, 75, 75, 100, 100};
    for(int i = 0; i < 6; i++) {
        int tir;
        do { tir = rand() % 28; } while (t[tir] == -1); 
        t_out[i] = t[tir];
        t[tir] = -1;
    }
}

int resultat_aleatoire() {
    return (rand() % 899)+100;
}

// cree tout les couples a partir d'un tableau de nombre
void creation_couple(int *nombres, int n, Couple *tab_out) {
//n = taille de du tableau nombres

    int cpt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            tab_out[cpt].v1 = nombres[i];
            tab_out[cpt].v2 = nombres[j];
            tab_out[cpt].i1 = i;
            tab_out[cpt].i2 = j;
            cpt++;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            tab_out[cpt].v1 = nombres[j];
            tab_out[cpt].v2 = nombres[i];
            tab_out[cpt].i1 = j;
            tab_out[cpt].i2 = i;
            cpt++;
        }
    }    
}

int pn_precedent(Couple c, int *tirage, int taille, char *operation, int R_final) {
    
    int t_add[taille];
    int t_sous[taille];
    int t_mult[taille];
    int t_div[taille];

    int cpt;

// addition
    //affectation de t_add[]
    cpt = 1;
    t_add[0] = tirage[c.i1] + tirage[c.i2];
    for(int i = 0; i < taille; i++) {
        if(i != c.i1 && i != c.i2) {
            t_add[cpt] = tirage[i];
            cpt++;
        }
    }
    // construction du char* contenant l'operation
    int n = taille - 1;
    char ope_tmp[256]; 
    if(taille == 6) {
        sprintf(ope_tmp, "%d + %d", tirage[c.i1], tirage[c.i2]);  
    } 
    else {
        sprintf(ope_tmp, "%s + %d", operation, tirage[c.i2]);
    }
    //progression
    //printf("%s\n", ope_tmp);
    
    if(t_add[0] == R_final) { 
        sprintf(operation, "%s", ope_tmp);
        return 1; 
    }

    //recurtivite    
    if(taille-1 >= 2) {
        //creation des couples
        int nb_couple = (taille-1)*(taille-1-1);
        Couple tab_couples[nb_couple];   
        creation_couple(t_add, taille-1, tab_couples);   
        //creation_couple_2(t_add, taille-1, tab_couples);

// impression des couples [DEBUG]
/*      
        for(int i = 0; i < taille-2; i++) {
            printf("(%d;%d)\t(%d;%d)\n", tab_couples[i].v1, tab_couples[i].v2, tab_couples[i].i1, tab_couples[i].i2);
        }
*/
        
        for(int i = 0; i < taille-2; i++) {
            if(pn_precedent(tab_couples[i], t_add, taille-1, ope_tmp, R_final) == 1) { 
                //printf_tirages(t_add, n, taille);
                //printf("%s\n", ope_tmp);
                sprintf(operation, "%s", ope_tmp);
                return 1;
            }
        }
    }


// soustraction
    //affectation de t_sous[]
    cpt = 1;

    t_sous[0] = tirage[c.i1] - tirage[c.i2];
    if(t_sous[0] < 0) { 
        //printf_erreur("ERREUR : resultat sous < 0", 1);
        return 0;
    }
    for(int i = 0; i < taille+1; i++) {
        if(i != c.i1 && i != c.i2) {
            t_sous[cpt] = tirage[i];
            cpt++;
        }
    }

    // construction du char* contenant l'operation
    if(taille == 6) {
        sprintf(ope_tmp, "%d - %d", tirage[c.i1], tirage[c.i2]);  
    } 
    else {
        sprintf(ope_tmp, "%s - %d", operation, tirage[c.i2]);
    }
    //progression
    //printf("%s\n", ope_tmp);
    
    if(t_sous[0] == R_final) { 
        sprintf(operation, "%s", ope_tmp);
        return 1; 
    }

    //recurtivite    
    if(taille-1 >= 2) {
        //creation des couples
        int nb_couple = (taille-1)*(taille-1-1);
        Couple tab_couples[nb_couple];   
        creation_couple(t_sous, taille-1, tab_couples);   
        //creation_couple_2(t_add, taille-1, tab_couples);

// impression des couples [DEBUG]
/*      
        for(int i = 0; i < taille-2; i++) {
            printf("(%d;%d)\t(%d;%d)\n", tab_couples[i].v1, tab_couples[i].v2, tab_couples[i].i1, tab_couples[i].i2);
        }
*/
        
        for(int i = 0; i < taille-2; i++) {
            if(pn_precedent(tab_couples[i], t_sous, taille-1, ope_tmp, R_final) == 1) { 
                //printf_tirages(t_add, n, taille);
                //printf("%s\n", ope_tmp);
                sprintf(operation, "%s", ope_tmp);
                return 1;
            }
        }
    }


    
    // multiplication
        //affectation de t_add[]
    cpt = 1;
    t_mult[0] = tirage[c.i1] * tirage[c.i2];
    for(int i = 0; i < taille; i++) {
        if(i != c.i1 && i != c.i2) {
            t_mult[cpt] = tirage[i];
            cpt++;
        }
    }
    // construction du char* contenant l'operation
    if(taille == 6) {
        sprintf(ope_tmp, "%d * %d", tirage[c.i1], tirage[c.i2]);  
    } 
    else {
        sprintf(ope_tmp, "%s * %d", operation, tirage[c.i2]);
    }
    //progression
    //printf("%s\n", ope_tmp);
    
    if(t_mult[0] == R_final) { 
        sprintf(operation, "%s", ope_tmp);
        return 1; 
    }

    //recurtivite    
    if(taille-1 >= 2) {
        //creation des couples
        int nb_couple = (taille-1)*(taille-1-1);
        Couple tab_couples[nb_couple];   
        creation_couple(t_mult, taille-1, tab_couples);   
        //creation_couple_2(t_mult, taille-1, tab_couples);

// impression des couples [DEBUG]
/*      
        for(int i = 0; i < taille-2; i++) {
            printf("(%d;%d)\t(%d;%d)\n", tab_couples[i].v1, tab_couples[i].v2, tab_couples[i].i1, tab_couples[i].i2);
        }
*/
        
        for(int i = 0; i < taille-2; i++) {
            if(pn_precedent(tab_couples[i], t_mult, taille-1, ope_tmp, R_final) == 1) { 
                //printf_tirages(t_mult, n, taille);
                //printf("%s\n", ope_tmp);
                sprintf(operation, "%s", ope_tmp);
                return 1;
            }
        }
    }

    // division
    cpt = 1;
    if(tirage[c.i2] == 0) {
        //printf_erreur("ERREUR : division par 0", 1); 
        return 0;
    }
    else {
        if(tirage[c.i1] % tirage[c.i2] != 0) { 
            //printf_erreur("ERREUR : resultat div pas int", 1); 
            return 0;    
        }
        else {
            t_div[0] = tirage[c.i1] / tirage[c.i2];
            for(int i = 0; i < taille+1; i++) {
                if(i != c.i1 && i != c.i2) {
                    t_div[cpt] = tirage[i];
                    cpt++;
                }
            }
        }
    }

    // construction du char* contenant l'operation

    if(taille == 6) {
        sprintf(ope_tmp, "%d / %d", tirage[c.i1], tirage[c.i2]);  
    } 
    else {
        sprintf(ope_tmp, "%s / %d", operation, tirage[c.i2]);
    }
    //progression
    //printf("%s\n", ope_tmp);
    
    if(t_div[0] == R_final) { 
        sprintf(operation, "%s", ope_tmp);
        return 1; 
    }

    //recurtivite    
    if(taille-1 >= 2) {
        //creation des couples
        int nb_couple = (taille-1)*(taille-1-1);
        Couple tab_couples[nb_couple];   
        creation_couple(t_div, taille-1, tab_couples);   
        //creation_couple_2(t_div, taille-1, tab_couples);

// impression des couples [DEBUG]
/*      
        for(int i = 0; i < taille-2; i++) {
            printf("(%d;%d)\t(%d;%d)\n", tab_couples[i].v1, tab_couples[i].v2, tab_couples[i].i1, tab_couples[i].i2);
        }
*/
        
        for(int i = 0; i < taille-2; i++) {
            if(pn_precedent(tab_couples[i], t_div, taille-1, ope_tmp, R_final) == 1) { 
                //printf_tirages(t_div, n, taille);
                //printf("%s\n", ope_tmp);
                sprintf(operation, "%s", ope_tmp);
                return 1;
            }
        }
    }

   return 0;
}

int main() {

    srand((unsigned int)time(NULL));
    int sz = 6;
    int R = resultat_aleatoire();
    
    char str_R[256] = "";
    int nb_couple = sz*(sz-1);
    Couple tab_couples[nb_couple];

    int tirage[6];
    tirage_aleatoire(tirage);
    printf_tirages(tirage, 6, 0);
    
    creation_couple(tirage, sz, tab_couples);
        // impression des couples [DEBUG]

    // for(int i = 0; i < nb_couple; i++) {
    //     printf("couple %d :\t(%d;%d)\t(%d;%d)\n", i, tab_couples[i].v1, tab_couples[i].v2, tab_couples[i].i1, tab_couples[i].i2);
    // }  


    for(int i = 0; i < nb_couple; i++) {
        if(pn_precedent(tab_couples[i], tirage, sz, str_R, R) == 1) {
            printf("\t====== RESULTAT ======\n");
            printf("%s = %d\n", str_R, R);
            return 0;
        }
    }
    printf("AUCUN RESULTAT TROUVE POUR %d\n", R);

}