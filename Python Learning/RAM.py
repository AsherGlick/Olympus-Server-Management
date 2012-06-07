#This program runs a memory test for windows or unix based operating systems
import subprocess
import ctypes
import os, platform	
def check_system ():
	print os.name
	platform.system()
	platform.release()
def winmem():
	class MEMORYSTATUSEX(ctypes.Structure):
		_fields_ = [
			('dwLength', ctypes.c_uint),
			('dwMemoryLoad', ctypes.c_uint),
			('dwTotalPhys', ctypes.c_ulonglong),
			('dwAvailPhys', ctypes.c_ulonglong),
			('dwTotalPageFile', ctypes.c_ulonglong),
			('dwAvailPageFile', ctypes.c_ulonglong),
			('dwTotalVirtual', ctypes.c_ulonglong),
			('dwAvailVirtual', ctypes.c_ulonglong),
			]
		def __init__ (self):
			self.dwLength = 2*4 + 7*8
			return super (MEMORYSTATUSEX, self).__init__()
	x = MEMORYSTATUSEX() 
	ctypes.windll.kernel32.GlobalMemoryStatusEx(ctypes.byref(x))
	print x.dwLength
	print x.dwMemoryLoad
	print x.dwTotalPhys
	print x.dwAvailPhys
	print x.dwTotalPageFile
	print x.dwAvailPageFile
	print x.dwTotalVirtual
	print x.dwAvailVirtual
	return x
	

check_system() 	
system = platform.system() #defines os as the general operating system type determined above
print system
if system ==  "Windows":#if windows...
	#import pythoncom
	#import pywintypes
	#import datetime
	
	
	
	
	winmem()	
	

# The following runs for Linux (unix based) operating Systems	
if platform.name() == 'Linux':

	class MemoryMonitor(object):

		def __init__(self, username):
			"""Create new MemoryMonitor instance."""
			self.username = username

		def usage(self):
			"""Return int containing memory used by user's processes."""
			self.process = subprocess.Popen("ps -u %s -o rss | awk '{sum+=$1} END {print sum}'" % self.username,
				shell=True,
				stdout=subprocess.PIPE,
				)
			self.stdout_list = self.process.communicate()[0].split('\n')
			return int(self.stdout_list[0])
