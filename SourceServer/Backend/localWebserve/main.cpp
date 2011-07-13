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
      cout << data << endl;
      ifstream f;
      f.open(string("../../Frontend"+getGET(data)).c_str());
      string file = "";
      int total = 0;
      while (f.good()) {
        file = "";
        
        for (int i = 0; i < 4024; i++) {
          if (!f.good()) {
            file = file.substr(0,file.size()-1);
            break;
          }
          file += f.get();
          total++;
        }
	      while (!sendData (clientSockFD, file)){
          //perror("send");
	        //cout << "send ERROR!" << getGET (data)<< "! " << total << "bytes" << endl; 
	      }
	      {
	        //cout << getGET (data) << " SENT " << total << "bytes" << endl;
	      }
	    }
	    close(clientSockFD);
	    return 0;
	  }
	  close(clientSockFD);
	}
}

