#define MAXDATASIZE 100
#include "ashsockPP.h"   // Basic Socet Functionality
#include "ashHTMLPP.h"
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
      html newPack = html(data);
      cout << "--RAW--" << endl;
      cout << newPack.raw << endl;
      cout << "--: TYPE:" << newPack.type << endl;
      cout << "--: REQUEST:" << newPack.request << endl;
      cout << "--: HOST:" << newPack.host << endl;
      cout << "--: POST:" << newPack.post << endl;
      if (newPack.type == HTML_GET) {
        ifstream f;
        f.open(string("../Frontend"+newPack.request).c_str());
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
	          cout << "\rsend ERROR!!" << newPack.request; 
	        }
	        {
	          //cout << getGET (data) << " SENT " << total << "bytes" << endl;
	        }
	      }
	    }
	    else if (newPack.type == HTML_POST) {
	      if (newPack.post[0] == 's') {
	        cout << "SERVER LIST" << endl;
	        while (!sendData (clientSockFD, "server1name,ip,num&server2name,ip,num&server3name,ip,num"));
	        cout << "SENT DATA" << endl;
	      }
	      else if (newPack.post[0] == 'p') {
	        cout << "PLUGIN LIST REQUEST" << endl;
	      }
	      else if (newPack.post[0] == 'l') {
	        cout << "LOAD PLUGIN REQUEST" << endl; 
	      }
	      else if (newPack.post[0] == 'd') {
	        cout << "DATA REQUEST" << endl;
	      }
	    }
	    else {
	      cout << "NOT POST OR GET!!!" << endl;
	    }
	    close(clientSockFD);
	    return 0;
	  }
	  close(clientSockFD);
	}
}

