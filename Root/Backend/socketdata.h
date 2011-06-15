/* Socketdata.h
|
\*

/*************************************************************************\
| socketNode                                                              |
|   socketNodes are used to save the current sockets, without overloading |
|   the memory when many sockets have been connected and disconnected.    |
|   socketNodes contain 3 pieces of information that can be accesses      |
|     _fd       - the file discriptior of the socket                      |
|     _ipaddr   - the address of the connected socket                     |
|     _threadId - the id of the thread that is running the listener       |
\*************************************************************************/
struct socketNode {
    socketNode       * _previous;
    socketNode       * _next;
    int                _fd;
    char             * _ipaddr;//   [INET6_ADDRSTRLEN];
};

/*****************************************************************************\
| socketList                                                                  |
|   the socket list is made up of a list of socketNodes that are in a linked  |
|   list style format. They contain all the information that is needed to     |
|   manage and use sockets. Whenever a new node is created the pointer to the |
|   node is returned as a socketNode*. In order to delete a socketNode you    |
|   need to use the socketNode pointer. As well there are two functions to    |
|   send information to all the sockets that are connected. sendToAll and     |
|   sendToAllExcept. sendToAll will send a message to every socket that is    |
|   in the socketList, this is used for things like system messages when the  |
|   server needs to send data to the clients. sendToAllExcept takes in a      |
|   message and a socketNode pointer and will send a message to all the       |
|   sockets except for one, this is used for when client sends a message to   |
|   the server and the server wants to send it back to everyone else without  |
|   sending it to the orignal sender. sendToSocket sends a message to a       |
|   specific socket denoted byt a socketNode pointer.                         |
\*****************************************************************************/
class socketList {
  private:
    socketNode * root;
    socketNode * last;
    unsigned int _size;
  public:
    socketList();
    ~socketList();
    
    socketNode * addSocket(int fd, char ipaddr[INET6_ADDRSTRLEN]);
    void removeSocket (socketNode * node);
    
    bool sendToAll (const char * message, int size);
    bool sendToAllExcept (const char * message, int size, socketNode * except);
    bool sendToSocket (const char * message, int size, socketNode * target);
    
    int size(){return (_size);}
};
socketList::socketList() {
  //create the first and last nodes
  root = new socketNode();
  last = new socketNode();
  //patch the nodes to each other
  root->_previous = NULL;
  root->_next = last;
  last->_previous = root;
  last->_next = NULL;
}

socketList::~socketList() {
  //set current node to the first node
  socketNode * current = root->_next;
  socketNode * nextNode;
  //delete all the element inside the list
  while (current != last) {
    nextNode = current->_next;
    delete current;
    current = nextNode;
  }
  //delete the first and last nodes
  delete root;
  delete last;
}
/********************************* Add Socket *********************************\
|
\******************************************************************************/
socketNode * socketList::addSocket(int fd, char ipaddr[INET6_ADDRSTRLEN]){
  socketNode * newNode = new socketNode();
  _size++;
  // stitch in new node
  newNode -> _previous = last -> _previous;
  newNode -> _next = last;
  last -> _previous -> _next = newNode;
  last -> _previous = newNode;
  // set variables
  newNode -> _fd = fd;
  newNode -> _ipaddr = ipaddr;
  // return the node pointer
  return newNode;
}
/******************************* Remove Socket *******************************\
| This function removes a socket from the list of sockets                     |
\*****************************************************************************/
void socketList::removeSocket (socketNode * node) {
  // patch surrounding nodes
  node -> _previous -> _next = node -> _next;
  node -> _next -> _previous = node -> _previous;
  // delete node
  delete node;
  _size--;
}
/******************************** Send To All ********************************\
| The send to all function sends a message to every connected socket          |
\*****************************************************************************/
bool socketList::sendToAll (const char * message, int size) {
  socketNode * current = root->_next;
  while (current != last) {
    if (send(current->_fd, message, size, 0) == -1){
      perror("send");
      return false;
    }
    current = current->_next;
  }
  return true;
}
/***************************** Send To All Except *****************************\
| This function sends a message to every connected socket except a specific    |
| socket, this is used in echoing the messages. If socket A sends a message to |
| the server, you dont want the server to send a message back to socket A, you |
| want it to send that message to all the other sockets B C D E etc.           |
\******************************************************************************/
bool socketList::sendToAllExcept (const char * message, int size, socketNode * except) {
  socketNode * current = root->_next;
  while (current != last) {
    if (current != except){
      if (send(current->_fd, message, size, 0) == -1) {
        perror("send");
        return false;
      }
    }
    current = current->_next;
  }
  return true;
}

/******************************* Send To Socket *******************************\
| this function sends a message to a specific socket, denoted by a socket node |
\******************************************************************************/
bool socketList::sendToSocket (const char * message, int size, socketNode * target) {
  if (send(target->_fd, message, size, 0) == -1) {
    perror("send");
    return false;
  }
  return true;
}











