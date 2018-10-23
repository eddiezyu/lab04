#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"

int main(int argc, char *argv[])
{
  int i;
  
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  if (digitalRead(0) == 1){printf("hey\n");}
  while(1) {
    printf("Waiting for reset\n");
    if (digitalRead(0)==1){printf("hey2\n");}
    while(digitalRead(0) == 1);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    printf("Waiting for event\n");
    while(digitalRead(0) == 0);
ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/123","m1","m2","m3");
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    printf("Alarm\n");
  }
  /*NOTREACHED*/
  return 0 ;
}
