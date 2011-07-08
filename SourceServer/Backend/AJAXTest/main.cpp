#define MAXDATASIZE 100
#include "ashsockPP.h"   // Basic Socet Functionality
#include "ashAjaxPP.h" // Ajax / HTTP protocol functions
#include <iostream>
using namespace std;


int main () {
  string data;
  int sockfd;
  int clientSockFD;
  string port = "7331";
  
  bindPort (sockfd, port);
  cout << "bound port" << endl;
  waitClient(clientSockFD, sockfd);
  cout << "Got Client" << endl;
  data = waitData (clientSockFD);
  cout << "JUST GET :" << getGET(data) << ":" << endl;
  
  //cout << string(data) << endl;
}

