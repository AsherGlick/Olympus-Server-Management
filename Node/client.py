# Echo client program
import socket
import sys
import os
from stat import *
import time

# load plugins
print '\n--- plugin list ---'
for f in os.listdir('./plugins'):
  if (f is " PLUGINS "):
    print "hello world"
  print '|', f, '|'
print '--- end plugin list ---\n'
    

# connect to remote computer
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
    print 'Could not connect to root server, Retrying in 10 seconds'
    time.sleep(30)
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

