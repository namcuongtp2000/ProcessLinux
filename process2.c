#include <signal.h>

#include <stdio.h>

#include <string.h>

#include <sys/types.h>

#include <unistd.h>

#include <stdlib.h>

int count=0;

void handler (int signal_number)

{

            FILE *fid=fopen("/home/thuan/output.txt","a"); 

            fprintf(fid,"\nNhan duoc tin hieu SIGUSR1 lan thu %   d", count++);

            fclose(fid);   

}

int main ()

{

  struct sigaction sa;

  printf ("The process ID is %d\n", (int) getpid ());

  printf ("The parent process ID is %d\n", (int) getppid ());

  //Thiet lap signal handler

  memset (&sa, 0, sizeof (sa));

  sa.sa_handler = &handler;

  sigaction (SIGUSR1, &sa, NULL);  

  while(1)

            {

                        printf("A");  

                        usleep(50);   

            }

  return 0;

}
