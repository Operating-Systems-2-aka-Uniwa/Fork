#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main (int argc, char *argv[])
{
/************************************************** P0 **************************************************/
    int pid1, pid2, pid3, pid4, pid5, pid6;                                                                // Variable declarations
    int status, status1, status2;
    char *matrix[] = { "cat", "fork.c" , NULL };
    int fd[2];                                                                                             // fd[0]--> read, fd[1]--> write
    char msg1[30];
    char msg2[30];
    int length;
    int chpid1, chpid2;
    
    strcpy (msg1, "hello from your child\n");                                                              // Copying the characters 'hello from your child\n' byte by byte along with the null-terminator '\0' into the static array 'msg1' of 30 positions.
   
    if (pipe (fd) < 0)                                                                                     /* Calling pipe which achieves inter-process communication, and if the return value is negative */
    {
        perror ("Error! Pipe failed to execute");                                                          // Print to stderr the error message that occurred during the pipe execution at line 22
        exit (1);                                                                                          // The main process P0 terminates with exit status 1
    }

    pid1 = fork ();                                                                                        // Calling fork, creating child process P1 from P0 
    if (pid1 < 0)                                                                                          /* The value stored in the variable pid1, i.e., the value returned by fork at line 28, is negative */
    {
        perror ("Error! Fork failed to create P0's child process P1");                                     // Print to stderr the error message that occurred during the fork execution at line 28
        exit (1);                                                                                          // The main process P0 terminates with exit status 1
    }
    else                                                                                                   /* The value stored in the variable pid1, i.e., the value returned by fork at line 28, is not negative */
    {
/************************************************** P1 **************************************************/
        if (pid1 == 0)                                                                                     /* The value stored in the variable pid1, i.e., the value returned by fork at line 28, is equal to 0 */
        {                                                                                                  // Fork returns 0 to child process P1 of P0, so the code for P1 is executed
            printf ("Hello from P0's child process P1, PID : %d, PPID : %d\n", getpid (), getppid ());     // Print to stdout the PID of the child process P1 and the PID of its parent P0
            pid3 = fork ();                                                                                // Calling fork to create child process P3 from P1
            if (pid3 < 0)                                                                                  /* The value stored in the variable pid3, i.e., the value returned by fork at line 40, is negative */ 
            {
                perror ("Error! Fork failed to create P1's child process P3");                             // Print to stderr the error message that occurred during the fork execution at line 40
                exit (1);                                                                                  // Process P1 terminates with exit status 1
            }
            else                                                                                           /* The value stored in the variable pid3, i.e., the value returned by fork at line 40, is not negative */
            {
/************************************************** P3 **************************************************/
                if (pid3 == 0)                                                                             /* The value stored in the variable pid1, i.e., the value returned by fork at line 40, is equal to 0 */
                {                                                                                          // Fork returns 0 to child process P3 of P1, so the code for P3 is executed
                    printf ("Hello from P1's child process P3, PID : %d, PPID : %d\n", getpid (), getppid ()); // Print to stdout the PID of the child process P3 and the PID of its parent P1
                    close (fd[0]);                                                                         // Calling close to close the read channel via fd[0], as the purpose of the child process P3 is to send a message to the parent process P1
                    write (fd[1], msg1, 30);                                                               // Calling write to send the message from P3 to P1 through the write channel via fd[1], writing 30 bytes from 'msg1'
                    close (fd[1]);                                                                         // Calling close to close the write channel via fd[1] to avoid conflicts if used by another process
                    exit (30);                                                                             // Process P3 terminates with exit status 30
                }
/************************************************** P1 **************************************************/
                else                                                                                       /* The value stored in the variable pid3, i.e., the value returned by fork at line 40, is positive */
                {                                                                                          // Fork returns the PID of the child process P3 to the parent process P1, so the code for P1 is executed
                    close (fd[1]);                                                                         // Calling close to close the write channel via fd[1], as the parent process P1 receives a message from the child process P3
                    read (fd[0], msg2, 30);                                                                // Calling read to read the message sent from P3 through the read channel via fd[0], reading 30 bytes into 'msg2'
                    close (fd[0]);                                                                         // Calling close to close the read channel via fd[0] to avoid conflicts if used by another process
                    printf ("%s", msg2);                                                                   // Print to stdout the message received by P1 from P3, stored in the static array 'msg2'
                    exit (10);                                                                             // Process P1 terminates with exit status 10
                }
            }
        }
/************************************************** P0 **************************************************/
        else                                                                                               /* The value stored in the variable pid1, i.e., the value returned by fork at line 28, is positive */
        {                                                                                                  // Fork returns the PID of the child process P1 to the parent process P0, so the code for P0 is executed
            printf ("Hello from process P0, PID : %d, PPID : %d\n", getpid (), getppid ());                // Print to stdout the PID of process P0 and the PID of its parent
            if (waitpid (pid1, &status, 0) < 0)                                                            /* Calling waitpid to block the process P0 until its child process P1 terminates, and if the return value is negative */
            {
                perror ("Error! Waitpid failed to execute");                                               // Print to stderr the error message that occurred during the waitpid execution at line 72
                exit (1);                                                                                  // Process P0 terminates with exit status 1
            }
            else                                                                                           /* The return value of waitpid is not negative */
            {
                printf ("Exit value of P0's child process P1 is %d\n", WEXITSTATUS (status));              // Print to stdout the exit status of P1
            }
            pid2 = fork ();                                                                                // Calling fork to create child process P2 from P0
            if (pid2 < 0)                                                                                  /* The value stored in the variable pid2, i.e., the value returned by fork at line 81, is negative */
            {
                perror ("Error! Fork failed to create P0's child process P2");                             // Print to stderr the error message that occurred during the fork execution at line 84
                exit (1);                                                                                  // Process P0 terminates with exit status 1
            }
            else                                                                                           /* The value stored in the variable pid2, i.e., the value returned by fork at line 81, is not negative */
            {    
/************************************************** P2 **************************************************/
                if (pid2 == 0)                                                                             /* The value stored in the variable pid2, i.e., the value returned by fork at line 81, is equal to 0 */
                {                                                                                          // Fork returns 0 to child process P2 of P0, so the code for P2 is executed
                    printf ("Hello from P0's child process P2, PID : %d, PPID : %d\n", getpid (), getppid ()); // Print to stdout the PID of the child process P2 and the PID of its parent
                    pid4 = fork ();                                                                        // Calling fork to create child process P4 from P2
                    if (pid4 < 0)                                                                          /* The value stored in the variable pid4, i.e., the value returned by fork at line 93, is negative */
                    {
                        perror ("Error! Fork failed to create P2's child process P4");                     // Print to stderr the error message that occurred during the fork execution at line 93
                        exit (1);                                                                          // Process P2 terminates with exit status 1
                    }
                    else                                                                                   /* The value stored in the variable pid4, i.e., the value returned by fork at line 93, is not negative */
                    {
/************************************************** P4 **************************************************/
                        if (pid4 == 0)                                                                     /* The value stored in the variable pid4, i.e., the value returned by fork at line 93, is equal to 0 */
                        {                                                                                  // Fork returns 0 to the child process P4 of P2, so the code for P4 is executed
                            printf ("Hello from P2's child process P4, PID : %d, PPID : %d\n", getpid (), getppid ()); // Print to stdout the PID of child process P4 and the PID of its parent
                            exit (40);                                                                     // Process P4 terminates with exit status 40
                        }
/************************************************** P2 **************************************************/
                        else                                                                               /* The value stored in the variable pid4, i.e., the value returned by fork at line 93, is positive */
                        {                                                                                  // Fork returns the PID of the child process P4 to the parent process P2, so the code for P2 is executed
                            pid5 = fork ();                                                                // Fork is called to create the child process P5 from P2
                            if (pid5 < 0)                                                                  /* The value stored in the variable pid5, i.e., the value returned by fork at line 110, is negative */
                            {
                                perror ("Error! Fork failed to create P2's child process P5");             // Print to stderr the error message that occurred during the fork execution at line 110
                                exit (1);                                                                  // Process P2 terminates with exit status 1
                            }
                            else                                                                           /* The value stored in the variable pid5, i.e., the value returned by fork at line 110, is not negative */
                            {
/************************************************** P5 **************************************************/
                                if (pid5 == 0)                                                             /* The value stored in the variable pid5, i.e., the value returned by fork at line 110, is equal to 0 */
                                {                                                                          // Fork returns 0 to the child process P5 of P2, so the code for P5 is executed
                                    printf ("Hello from P2's child process P5, PID : %d, PPID : %d\n", getpid (), getppid ()); // Print to stdout the PID of child process P5 and the PID of its parent P2
                                    exit (50);                                                             // Process P5 terminates with exit status 50
                                }
/************************************************** P2 **************************************************/
                                else                                                                       /* The value stored in the variable pid5, i.e., the value returned by fork at line 110, is positive */
                                {                                                                          // Fork returns the PID of child process P5 to the parent process P2, so the code for P2 is executed
                                    pid6 = fork ();                                                        // Fork is called to create the child process P6 from P2
                                    if (pid6 < 0)                                                          /* The value stored in the variable pid6, i.e., the value returned by fork at line 127, is negative */
                                    {
                                        perror ("Error! Fork failed to create P2's child process P6");     // Print to stderr the error message that occurred during the fork execution at line 127
                                        exit (1);                                                          // Process P2 terminates with exit status 1
                                    }
                                    else                                                                   /* The value stored in the variable pid6, i.e., the value returned by fork at line 127, is not negative */
                                    {
/************************************************** P6 **************************************************/
                                        if (pid6 == 0)                                                     /* The value stored in the variable pid6, i.e., the value returned by fork at line 127, is equal to 0 */
                                        {                                                                  // Fork returns 0 to the child process P6 of P2, so the code for P6 is executed
                                            printf ("Hello from P2's child process P6, PID : %d, PPID : %d\n", getpid (), getppid ()); // Print to stdout the PID of child process P6 and the PID of its parent P2
                                            exit (60);                                                     // Process P6 terminates with exit status 60
                                        }
                                    }
                                }
                            }
                        }
                    }
/************************************************** P2 **************************************************/
                    chpid1 = wait (&status1);                                                              // Wait is called to block the process P2 until one of its direct child processes terminates
                    if (chpid1 < 0)                                                                        /* The value stored in the variable chpid1, i.e., the value returned by wait at line 147, is negative */
                    {
                        perror ("Error! Wait failed to execute");                                          // Print to stderr the error message that occurred during the wait execution at line 147
                        exit (1);                                                                          // Process P2 terminates with exit status 1
                    }
                    chpid2 = wait (&status2);                                                              // Wait is called to block the process P2 until one of its direct child processes terminates
                    if (chpid2 < 0)                                                                        /* The value stored in the variable chpid2, i.e., the value returned by wait at line 153, is negative */
                    {
                        perror ("Error! Wait failed to execute");                                          // Print to stderr the error message that occurred during the wait execution at line 153
                        exit (1);                                                                          // Process P2 terminates with exit status 1
                    }
                    printf ("P2's child process with PID %d terminated\n", chpid1);                        // Print to stdout the PID of the child process of P2 that terminated first
                    printf ("P2's child process with PID %d terminated\n", chpid2);                        // Print to stdout the PID of the next child process of P2 that terminated
                    exit (20);                                                                             // Process P2 terminates with exit status 20
                }
/************************************************** P0 **************************************************/
                else                                                                                       /* The value stored in the variable pid2, i.e., the value returned by fork at line 81, is not negative */
                {                                                                                          // Fork returns the PID of child process P2 to the parent process P0, so the code for P0 is executed
                    if (execv ("/bin/cat", matrix) < 0)                                                    /* Execv is called to replace the main process P0 with the command 'cat LS2-19390005-Δ4-Β-1-2.c', but the return value is negative */
                    {
                        perror ("Error occurred with execv");                                              // Print to stderr the error message that occurred during the execv execution at line 166
                        exit (1);                                                                          // Process P0 terminates with exit status 1
                    }
                    exit (0);                                                                              // Process P0 terminates with exit status 0
                }
            }
        }
    }

    return 0;
}


/*  Is it possible for orphan or zombie processes to be created during the execution of your program? 
    And which ones might they be? Please comment / justify your answer.

    Answer: During the execution of the program, 2 orphan processes were created and no zombie processes.
    This is because the parent processes (P0, P1, P2) finished before their respective child processes
    (P1, P2, P3, P4, P5, P6) finished. Every child process that terminates becomes a zombie until its parent 
    process collects its exit status, so it no longer occupies memory. More specifically, the processes
    terminated in the following order: P3 --> P1 --> P0 --> P6 --> P5 --> P2 --> P4. According to the process tree 
    represented in "Figure 1", the process P2 is the child of the main process P0, and P0 completes before P2. 
    As observed in the "Sample Runs", in line 219, the PID of the main process P0 is 5522. The PPID, that is, 
    the PID of the parent process of P2 (line 225), is expected to be the PID of P0 according to "Figure 1", 
    but it is not because P0 has finished its execution and is no longer in memory. Similarly, this occurs 
    with the child process P4 of P2, as due to the `wait` commands on lines 147 and 153 of the source code, 
    P2 waits for two of its direct child processes (P5 and P6) to terminate before it finishes execution. 
    In line 225, the PID of P2 is 5738, which does not match the PPID in line 230, which is the PID of the 
    parent process of P4 (PPID: 1069). Therefore, processes P2 and P4 are considered orphan processes.
    
    
                            (P0)
                            / \
                           /   \
                          /     \
                         /       \ 
                        /         \
                     (P1)        (P2)
                      /           /|\
                     /           / | \
                    /           /  |  \
                   /           /   |   \
                (P3)         (P4) (P5) (P6)
                   
                        - Figure 1 -
    
    Sample Runs:
    
    gcc -o fork fork.c
    ./fork
    
    Hello from process P0, PID : 5522, PPID : 2452
    Hello from P0's child process P1, PID : 5523, PPID : 5522
    Hello from P1's child process P3, PID : 5524, PPID : 5523
    hello from your child
    Exit value of P0's child process P1 is 10
    ................cat fork.c..............
    Hello from P0's child process P2, PID : 5738, PPID : 1069
    Hello from P2's child process P6, PID : 5741, PPID : 5738
    Hello from P2's child process P5, PID : 5740, PPID : 5738
    P2's child process with PID 5741 terminated
    P2's child process with PID 5740 terminated
    Hello from P2's child process P4, PID : 5739, PPID : 1069
*/

    
