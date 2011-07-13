#define MAXDATASIZE 100
#include "ashsockPP.h"   // Basic Socet Functionality
#include "ashAjaxPP.h" // Ajax / HTTP protocol functions
#include <iostream>
using namespace std;


int main () {
  string data = "";
  int sockfd;
  int clientSockFD;
  string port = "7331";
  
  bindPort (sockfd, port);
  cout << "bound port" << endl;
  waitClient(clientSockFD, sockfd);
  cout << "Got Client" << endl;
  //while (true) {
    data = "";
    while (data == "") {
      data = waitData (clientSockFD);
    }
    cout << data << endl;
  //}
  //cout << "JUST GET :" << getGET(data) << ":" << endl;
  cin >> port;
	if (sendData (clientSockFD,"<html><body><li><a href=\"#\" id=\"server_1234\" onclick=\"show_plugins(1234)\">Server</a> - <span class=\"italics\">128.67.224.101</span></li>\n<li><a href=\"#\" id=\"server_1000\" onclick=\"show_plugins(1000)\">Server</a> - <span class=\"italics\">128.67.224.101</span></li>\n<li><a href=\"#\" id=\"server_1200\" onclick=\"show_plugins(1200)\">Server</a> - <span class=\"italics\">128.67.224.101</span></li>\n<li><a href=\"#\" id=\"server_1300\" onclick=\"show_plugins(1300)\">Server</a> - <span class=\"italics\">128.67.224.101</span></li>\n<li><a href=\"#\" id=\"server_1400\" onclick=\"show_plugins(1400)\">Server</a> - <span class=\"italics\">128.67.224.101</span></li></body></html>")) {
	  cout << "sent data" << endl;
	}
	while (true);
  //cout << string(data) << endl;
}

