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

   cout<<"Enter Postive Number: "<<endl;
   int x;  
   cin>>x;

   if(x<0){

    cout<<"ERORR,This Number is negative!"<<endl;

   }else{
    cout<<x<<",";
    while(x>1){

     if(x%2==0){
	x=x/2;

     }else{
	x=3*x+1;
     }
      cout<<x<<",";
    }
      cout<<endl;
   }

 }else{
  wait(NULL);
 }
return 0;
}
