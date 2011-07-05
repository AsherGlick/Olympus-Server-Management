#define MAXDATASIZE 100
#include "ashsock.h"
#include <iostream>
using namespace std;


int main () {
  char data[MAXDATASIZE];
  int sockfd;
  int clientSockFD;
  char * port = "7331";
  
  bindPort (sockfd, port);
  cout << "bound port" << endl;
  waitClient(clientSockFD, sockfd);
  cout << "Got Client" << endl;
  waitData (data,clientSockFD);
  cout << data << endl;
}

