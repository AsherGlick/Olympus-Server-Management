/*
| This program was written by asher glick and is not open for anyone to use
| without express premission by the author aglick@tetrakai.com
*/
#include <stdio.h> // input out put
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h> // non blocking socket


//#ifndef MAXDATASIZE
//  #define MAXDATASIZE 8000
//#endif

#ifndef BACKLOG
  #define BACKLOG 10
#endif


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

/********************************** Wait Data *********************************\
| wait for data from a client socket file descriptor                           |
\******************************************************************************/
void waitData (char data[MAXDATASIZE], int & clientSockFD){
  char buf[MAXDATASIZE];
  int numbytes; // number of bytes received
  while (1) {
    if ((numbytes = recv(clientSockFD, buf, MAXDATASIZE-1, 0)) == -1) {
      // no data waiting
      continue;
    }
    if (numbytes == 0){
      //if a null byte is transfered the socket is closed
      printf ("Socket Closed, zero byte\n");
      //remove socket from list
      close(clientSockFD);
      break;
    }
    // ALL HAS GONE WELL, what to do with the information here
    data = buf;
    data[numbytes] = '\0';
    printf(":%s:",data);
  }
}


/********************************* Wait Client ********************************\
| Wait client waits for a client to connect to the server and returns a sockFD |
| that connects to the client. This file descripter can be used in waitData    |
\******************************************************************************/
void waitClient(int & clientSockFD, int & sockFD){
  socklen_t sin_size;
  struct sockaddr_storage their_addr;
  char s[INET6_ADDRSTRLEN];
  
  while(1) {
    sin_size = sizeof their_addr;
    clientSockFD = accept(sockFD, (struct sockaddr *)&their_addr, &sin_size);
    if (clientSockFD == -1) {
      perror("accept");
      continue;
    }
    inet_ntop(their_addr.ss_family,get_in_addr((struct sockaddr *)&their_addr),s, sizeof s);
    printf("server: got connection from %s\n", s);
    
    fcntl(clientSockFD,F_SETFL,O_NONBLOCK);
    
    break;
  }
}




/********************************** Bind port *********************************\
| the bind port function binds itself to a specified port on the computer and  |
| returns the file descriptor of the socket (UNIX-like os)                     |
\******************************************************************************/
void bindPort (int & sockfd, char * port) {
    struct addrinfo hints, *servinfo, *p;
    struct sigaction sa;
    int yes=1;
    int rv;
    
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; // use my IP
    if ((rv = getaddrinfo(NULL, port, &hints, &servinfo)) != 0) {
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
