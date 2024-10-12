#include <stdio.h>
#include <unistd.h>

int main ()
{
   
    int pid1, pid2, pid3, pid4;
    pid1=fork();
    printf ("pid1 = %d\n", pid1);
   // printf ("MAIN %d %d\n", getpid (), getppid ());
    if (pid1==0) 
    { 
        pid2=fork();
        printf ("pid2 = %d\n", pid2);
     //   printf ("IF %d %d\n", getpid (), getppid ());
    }
    else 
    { 
        pid3=fork();
        printf ("pid3 = %d\n", pid3);
       // printf ("ELSE 1 %d %d\n", getpid (), getppid ());
        pid4=fork();
        printf ("pid4 = %d\n", pid4);
       // printf ("ELSE 2 %d %d\n", getpid (), getppid ());
    }
    
    return 0;
}
