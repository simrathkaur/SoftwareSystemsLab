/*
============================================================================
Name : Handson List 1- ques 18
Author : Simrath Kaur
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
        int i,fd;
        struct {
                int train_num;
                int ticket_count;
        } db[3];
        for(i=0; i<3; i++){
                db[i].train_num=i+1;
                db[i].ticket_count=0;
        }
        fd=open("record18.txt", O_RDWR);
        write(fd,db,sizeof(db));
        close(fd);
}
