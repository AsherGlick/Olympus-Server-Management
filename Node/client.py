# Echo client program
import socket
import sys
import time

HOST = '127.0.0.1'    # The remote host
PORT = 50007          # The same port as used by the server
s = None
while 1:
    for res in socket.getaddrinfo(HOST, PORT, socket.AF_UNSPEC, socket.SOCK_STREAM):
        af, socktype, proto, canonname, sa = res
        try:
            s = socket.socket(af, socktype, proto)
        except socket.error, msg:
            s = None
            continue
        try:
            s.connect(sa)
        except socket.error, msg:
            s.close()
            s = None
            continue
        break
    if s is None:
        print 'Could not connect to root server\nRetrying in 10 seconds'
        print 'delaying'
        time.sleep(10)
        continue
    else:
        break
    
# Now the socket is configured
print 'Connection to root server'

#data transfer goes through here
s.send('Hello, world')
data = s.recv(1024)

# Done sending data close the socket
s.close()
print 'Received', repr(data)

