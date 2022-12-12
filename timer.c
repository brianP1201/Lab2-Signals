/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int alarm_count = 0;
int alarmsTriggered = 0;
time_t start, stop;

void handleralarm(int signum)
{ //signal handler
  alarm_count++;
  alarm(1);
  //exit(1); //exit after printing
}

void handlertime(int signum)
{
  int time_elapsed;
  stop = time(NULL);
  time_elapsed = stop - start;
  printf("\nNumber of Alarms: %d, Execution Time (in seconds): %d\n", alarm_count, time_elapsed);
  exit(0);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handleralarm); //register handler to handle SIGALRM
  signal(SIGINT, handlertime); // handler to handle SIGINT
  start = time(NULL);
  alarm(1);
 
  while(1){
    alarmsTriggered = 0;
    while(!alarmsTriggered);
    // printf("Turing was right!\n");
  } //busy wait for signal to be delivered
  
  return 0; //never reached
}