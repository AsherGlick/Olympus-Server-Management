#ifndef _ASHAJAX_PP_H_
#define _ASHAJAX_PP_H_
#include <string>
#include "ashsockPP.h"


class HTMLReq {
  public:
    HTMLReq(std::string);
    void set (std::string);
    std::string metaHost();
    std::string reqType();
    std::string htmlbody();
    
    void setRequest (std::string);
    void setHTML (std::string);
    void setreqType(std::string);
  private:
    std::string request;
    std::string htmlbody;
    std::
};



std::string getGET(std::string input) {
  int start;
  int length;
  for (unsigned int i = 0; i < input.size()-3; i++) {
    if (input[i] == 'G') {
      if (input[i+1] == 'E' && input[i+2] == 'T') {
        start = i+3;
        break;
      }
    }
  }
  for (unsigned int i = start; i < input.size(); i ++) {
    if (input[i] == '\r') { // newline characters consist of /r/n assumidly
    
      length=i-start;
      return input.substr(start,length);
    }
  }
  return input;
}
#endif
