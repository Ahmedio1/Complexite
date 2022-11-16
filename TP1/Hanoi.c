#include <stdio.h>
#include <time.h>
     
     /*
        Fonction Hanoi :
        repond Les tours de Hanoï au jeu de réflexion imaginé par le mathématicien français 
        Édouard Lucas, et consistant à déplacer des disques de diamètres différents d'une 
        tour de « départ » à une tour d'« arrivée » en passant par une tour « intermédiaire »,
        et ceci en un minimum de coups.
        @n : nombre de dique int 
        @A : char disque début
        @B : char disque intermediaire
        @C : disque finale 
        return void
     */

void hanoi(int n,char A,char B,char C){
    if (n==1){
        //printf("Deplacement %c a %c\n",A,C);
    }
    else {
        hanoi(n-1,A,C,B);
        //printf("Deplacement %c a %c\n",A,C);
        hanoi(n-1,B,A,C);
    }
}

int main(){
    //MAIN

    clock_t start, end;
    double cpu_time_used;
     
    // HANOI POUR N = 1 
    start = clock();
    hanoi(1,'A','B','C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Essai avec n = 1 : %f\n",cpu_time_used);

    // HANOI POUR N = 2
    start = clock();
    hanoi(2,'A','B','C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Essai avec n = 2 : %f\n",cpu_time_used);

    // HANOI POUR N = 5     
    start = clock();
    hanoi(5,'A','B','C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Essai avec n = 5 : %f\n",cpu_time_used);
    
    // HANOI POUR N = 10 
    start = clock();
    hanoi(10,'A','B','C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Essai avec n = 10 : %f\n",cpu_time_used);
    
    // HANOI POUR N = 15 
    start = clock();
    hanoi(15,'A','B','C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Essai avec n = 15 : %f\n",cpu_time_used);
    
    // HANOI POUR N = 20 
    start = clock();
    hanoi(20,'A','B','C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Essai avec n = 20 : %f\n",cpu_time_used);
    
    // HANOI POUR N = 25 
    start = clock();
    hanoi(25,'A','B','C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Essai avec n = 25 : %f\n",cpu_time_used);

    // HANOI POUR N = 26 
    start = clock();
    hanoi(26,'A','B','C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Essai avec n = 26 : %f\n",cpu_time_used);

    // HANOI POUR N = 27 
    start = clock();
    hanoi(27,'A','B','C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Essai avec n = 27 : %f\n",cpu_time_used);

    // HANOI POUR N = 29
    start = clock();
    hanoi(29,'A','B','C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Essai avec n = 29 : %f\n",cpu_time_used);
    
    // HANOI POUR N = 30 
    start = clock();
    hanoi(30,'A','B','C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Essai avec n = 30 : %f\n",cpu_time_used);
    
    // HANOI POUR N = 31
    start = clock();
    hanoi(31,'A','B','C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Essai avec n = 31 : %f\n",cpu_time_used);
    
    // HANOI POUR N = 33
    start = clock();
    hanoi(33,'A','B','C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Essai avec n = 33 : %f\n",cpu_time_used);    // HANOI POUR N = 35
    
    // HANOI POUR N = 34
    start = clock();
    hanoi(34,'A','B','C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Essai avec n = 34 : %f\n",cpu_time_used);
    
    // HANOI POUR N = 35
    start = clock();
    hanoi(35,'A','B','C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Essai avec n = 35 : %f\n",cpu_time_used);


    return 0;
}