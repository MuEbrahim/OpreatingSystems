#include<iostream>
#include<stdio.h>
#include <fstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <string>

using namespace std;


int main(int argc, char** argv)
{

 pid_t pid;

 pid = fork();
 	
 if(pid<0){
  cout<<"Fork failed"<<endl;
  return 1;

 }else if(pid == 0){

  cout<<"Child "<<getpid()<<endl;
  sleep(10); 
 }else{
  
  cout<<"Parent "<<getpid()<<endl;
  //kill(getpid(),9);
  sleep(20);
 }

return 0;
}
