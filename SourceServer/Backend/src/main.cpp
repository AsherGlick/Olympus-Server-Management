#define MAXDATASIZE 100
#include "ashsockPP.h"   // Basic Socet Functionality
#include "ashHTMLPP.h"
#include <fstream>
#include <iostream>
#include <stdio.h>

#include "charprint.h"

using namespace std;


string expand(string data, int size) {
  return data+string(size-data.size(),' ');
}


int main () {
  string data = "";
  int sockfd;
  int clientSockFD;
  string port = "80";
  //bind socket
  bindPort (sockfd, port);
  cout << "bound port" << endl;
  //load webpath
  ifstream webPathF;
  string webPath;
  webPathF.open("webPath");
  getline(webPathF,webPath);
  cout << "Web Path Set as " << webPath << endl;
 
  while (true) {
    if (waitSelf(clientSockFD, sockfd) == -1) continue;
    if (!fork()) {
      close(sockfd);
      data = "";
      while (data == "") {
        data = waitData (clientSockFD);
      }
      html newPack = html(data);
      //cout << "---- RAW ----" << endl;
      //charprint(newPack.raw);
      //cout << "-- END RAW --" << endl;
      cout << "--: TYPE:" << newPack.type << '\t';
      cout << "--: REQUEST:" << expand(newPack.request,50) << '\t';
      cout << "--: HOST:" << newPack.host << '\t';
      cout << "--: POST:" << newPack.post << endl;
      
      
      if (newPack.type == HTML_GET) {
        ifstream f;
        
        f.open(string(webPath+newPack.request).c_str());
        string file = "";
        string part = "";
        while (getline(f,part)) {
          file += part +'\n';
        }
        int size = sendData (clientSockFD, file);
        if (!size) {
          perror("send");
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
