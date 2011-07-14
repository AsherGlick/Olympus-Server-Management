#ifndef _ASHAJAX_PP_H_
#define _ASHAJAX_PP_H_
#include <string>
#include "ashsockPP.h"

#define HTML_GET "GET"
#define HTML_POST "POST"

class html {
  public:
    std::string type; // GET POST PUT
    std::string host; // hostname
    std::string request;
    std::string post;
    std::string raw;
  public:
    html(std::string);
  private:
    void setPOST();
    void setHost();
};
/******************************************************************************\
| The main constructor for the variables
\******************************************************************************/
html::html(std::string input) {
  raw = input;
  post = "NULL";
  setHost();
  int start = -1;
  int length;
  for (unsigned int i = 0; i < input.size()-3; i++) {
    if (input[i] == 'G') {
      if (input[i+1] == 'E' && input[i+2] == 'T') {
        start = i+4;
        type = "GET";
        break;
      }
    }
  }
  if (start == -1) {// no GET, look for PUSH
    for (unsigned int i = 0; i < input.size()-4; i++) {
      if (input[i] == 'P') {
        if (input[i+1] == 'O' && input[i+2] == 'S' && input[i+3] == 'T') {
          start = i+5;
          type = "POST";
          setPOST();
        }
      }
    }
  }
  for (unsigned int i = start; i < input.size(); i ++) {
    if (input[i] == '\r' || input[i] == '\n' || input[i] == ' ') { // newline characters consist of /r/n assumidly
    
      length=i-start;
      request = input.substr(start,length);
      break;
    }
  }
}

/******************************************************************************\
| Internal function to set the POST data (if any) based off of the raw data    |
\******************************************************************************/
void html::setPOST () {
  int postStart = 0;
  int postStop = raw.size();
  for (unsigned int j = 0; j < raw.size()-3;j++) {
    if (raw[j] == '\r' && raw[j+1] == '\n' && raw[j+2] == '\r' && raw[j+3] == '\n') {
      postStart = j+4;
      break;
    }
  }
  for (unsigned int j = postStart; j < raw.size()-1;j++) {
    if (raw[j] == '\r') {
      postStop = j;
      break;
    }
  }
  post = raw.substr(postStart,postStop-postStart);
}
/******************************************************************************\
| Internal function to set the host value based off of the raw data            |
\******************************************************************************/
void html::setHost() {
  int start = -1;
  for (unsigned int i = 0; i < raw.size()-4; i++) {
    if (raw[i] == 'H') {
      if (raw[i+1] == 'o' && raw[i+2] == 's' && raw[i+3] == 't' && raw[i+4] == ':') {
        start = i+5;
        break;
      }
    }
  }
  for (unsigned int i = start; i < raw.size(); i++) {
    if (raw[i] == '\r') {
      host = raw.substr(start, i-start);
      return;
    }
  }
}
#endif
