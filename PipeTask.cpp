#include<iostream>
#include<stdio.h>
#include <fstream>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<cmath>
using namespace std;

int main(int argc, char** argv)
{
string x;
float val = 0;
int fd[2];
pid_t pid;
pipe(fd);
pid = fork();
 	
 if(pid < 0){

  cout<<"Fork failed"<<endl;
  return 1;
 }else if(pid == 0){
close(fd[0]);
 struct timeval current;
	gettimeofday(&current,NULL);
val = current.tv_sec;	 
  	write(fd[1],&val,sizeof(val));
	close(fd[1]);

cout<<"enter your command"<<endl;
cin>>x;
	execlp(("/bin/"+x).c_str(),x.c_str(),NULL);
 }else{
wait(NULL);
struct timeval current2;
	gettimeofday(&current2,NULL);

close(fd[1]);
read(fd[0],&val,sizeof(val));
cout<<"time taken to execute in Seconds:"<<val-current2.tv_sec<<endl;
close(fd[0]);
 }
return 0;
}
