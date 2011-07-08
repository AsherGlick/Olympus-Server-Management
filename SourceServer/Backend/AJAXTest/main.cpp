#define MAXDATASIZE 100
#include "ashsock.h"   // Basic Socet Functionality
#include "ashAjaxPP.h" // Ajax / HTTP protocol functions
#include <iostream>
using namespace std;


int main () {
  char * data = 0;
  int datasize;
  int sockfd;
  int clientSockFD;
  char * port;
  stringtoStr(port, "7331");
  
  bindPort (sockfd, port);
  cout << "bound port" << endl;
  waitClient(clientSockFD, sockfd);
  cout << "Got Client" << endl;
  datasize = waitData (data,clientSockFD);
  string strdata = strtoString(data);
  cout << strdata << endl;
  cout << "JUST GET :" << getGET(strdata) << ":" << endl;
  
  //cout << string(data) << endl;
}

