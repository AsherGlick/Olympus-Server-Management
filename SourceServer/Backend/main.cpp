/*
This code is part of the Olympus Server Management Program
Copyright (C) 2011  Asher Glick

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

/* this is the Unix build of the program */
// compile with g++ main.cpp -pthread

#include <iostream>
#include <list>
#include <pthread.h>


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include "socketdata.h"

#define PORT "9574"     // the port users will be connecting to
#define BACKLOG 10      // how many pending connections queue will hol
#define MAXDATASIZE 100 // max number of bytes we can get at once

using namespace std;

socketList sockets; // the list of connected sockets, shared between the processes


void * waitForInput(void * socketList);
void sigchld_handler(int s);
void *get_in_addr(struct sockaddr *sa);
void connect (int & sockfd);
void itoa (char buffer [10], int number, int * size);

int main(void)
{
  socklen_t sin_size;
  struct sockaddr_storage their_addr; // connector's address information
  int sockfd;
  int new_fd;
  char s[INET6_ADDRSTRLEN];
  
  // Open a waiting connection on the selected port
  connect(sockfd);
  
  // wait for connections
  printf("server: waiting for connections...\n");
  while(1) {
      sin_size = sizeof their_addr;
      new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
      if (new_fd == -1) {
          perror("accept");
          continue;
      }
      inet_ntop(their_addr.ss_family,
          get_in_addr((struct sockaddr *)&their_addr),
          s, sizeof s);
      printf("server: got connection from %s\n", s);
      
      //add a new socket to the list
      socketNode * newNode = sockets.addSocket(new_fd,s);

      //create a thread for the new socket
      pthread_t thread_data_test;
      int rc;
      rc = pthread_create(&thread_data_test,NULL,waitForInput,(void *)newNode);
       if(rc){
         printf("ERROR: from pthread_create()\n");
         exit(1);
      }
  }
  printf ("Ending program");
  return 0;
}



void sigchld_handler(int s)
{
    while(waitpid(-1, NULL, WNOHANG) > 0);
}
// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

/******************************* Wait For Input *******************************\
| This function waits for each open connection's user input
\******************************************************************************/
void * waitForInput(void * threadData) {
  char buf[MAXDATASIZE];
  socketNode* sockInfo=(socketNode *)threadData;
  int numbytes; // number of bytes received
  while (1) {
    if ((numbytes = recv(sockInfo->_fd, buf, MAXDATASIZE-1, 0)) == -1) {
      perror("recv");
      printf("Closing socket %s\n",sockInfo->_ipaddr);
      close(sockInfo->_fd);
      sockets.removeSocket(sockInfo);
      printf("Socket Closed");
      //exit the thread
      pthread_exit(NULL);
    }
    if (numbytes == 0){
      //if a null byte is transfered the socket is closed
      printf ("Socket Closed %s\n",sockInfo->_ipaddr);
      //remove socket from list
      close(sockInfo->_fd);
      sockets.removeSocket (sockInfo);
      //exit the thread
      pthread_exit(NULL);
    }
    // ALL HAS GONE WELL, what to do with the information here
  }
}

/********************************** connect **********************************\
| This function sets up the server so that it waits on a specified port, for  |
| any connections to it. It handles all the important configurations and      |
| returns a file descriptor pointing to where the socket has been opened.     |
\*****************************************************************************/
void connect (int & sockfd) {
    struct addrinfo hints, *servinfo, *p;
    struct sigaction sa;
    int yes=1;
    int rv;
    
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; // use my IP
    if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }
    // loop through all the results and bind to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("server: socket");
            continue;
        }
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
                sizeof(int)) == -1) {
            perror("setsockopt");
            exit(1);
        }
        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("server: bind");
            continue;
        }
        break;
    }
    if (p == NULL) {
        fprintf(stderr, "server: failed to bind\n");
        exit(2);
  }
  freeaddrinfo(servinfo); // all done with this structure
  if (listen(sockfd, BACKLOG) == -1) {
      perror("listen");
      exit(1);
  }
  sa.sa_handler = sigchld_handler; // reap all dead processes
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_RESTART;
  if (sigaction(SIGCHLD, &sa, NULL) == -1) {
      perror("sigaction");
      exit(1);
  }
}


