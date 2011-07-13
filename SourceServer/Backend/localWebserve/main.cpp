#define MAXDATASIZE 100
#include "ashsockPP.h"   // Basic Socet Functionality
#include "ashAjaxPP.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;


int main () {
  string data = "";
  int sockfd;
  int clientSockFD;
  string port = "80";
  
  bindPort (sockfd, port);
  cout << "bound port" << endl;
 
  while (true) {
    if (waitSelf(clientSockFD, sockfd) == -1) continue;
    if (!fork()) {
      close(sockfd);
      data = "";
      while (data == "") {
        data = waitData (clientSockFD);
      }
      cout << getGET(data) << endl;
      ifstream f;
      f.open(string("../../Frontend"+getGET(data)).c_str());
      string file = "";
      while (f.good()) {
        file = "";
        for (int i = 0; i < 4024; i++) {
          if (!f.good()) {
            break;
          }
          file += f.get();
        }
	      if (!sendData (clientSockFD, file)){
	        //fprintf(perror,"WTF");
	        cout << "send ERROR!" << getGET (data)<< "!!! OMG WTF BBQHAXORS!!11!!!1" << endl; 
	      }
	    }
	    close(clientSockFD);
	    return 0;
	  }
	  close(clientSockFD);
	}
}

