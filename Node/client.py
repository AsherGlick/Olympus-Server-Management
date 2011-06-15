# This code is part of the Olympus Server Management Program
#Copyright (C) 2011  Asher Glick
#
#This program is free software; you can redistribute it and/or
#modify it under the terms of the GNU General Public License
#as published by the Free Software Foundation; either version 2
#of the License, or (at your option) any later version.
#
#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with this program; if not, write to the Free Software
#Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.



# Echo client program
import socket
import sys
import os
from stat import *
import time
from multiprocessing import Process
import os

################
# load plugins #
################
fileList = os.listdir('./plugins');

fileList[:] = [f for f in fileList if (f[len(f)-3:len(f)] == ".py")]

def run_prog(name):
  execfile(name)
   
##################################
# Create threads for each plugin #
##################################
for f in fileList:
  # Here is where a new process would be created for each plugin
  program = os.path.join('./plugins',f)
   # if the loaded program has a bug then the entire program crashes (this needs to be fixed)
  if __name__ == '__main__':
    p = Process(target=run_prog, args=(program,))
    p.start()
print "REMOTE: running", len(fileList), "plugins", fileList

##########################################
# connect to remote computer via sockets #
##########################################
HOST = '127.0.0.1'    # The remote host (this value will be loaded dynamicly from a config file)
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
    print 'REMOTE: Could not connect to root server, Retrying in 30 seconds'
    time.sleep(30)
    continue
  else:
    break
    
# Now the socket is configured
print 'REMOTE: Connection to root server complete'

#data transfer goes through here
s.send('Hello, world')
data = s.recv(1024)

# Done sending data close the socket
s.close()
print 'REMOTE: Received', repr(data)

