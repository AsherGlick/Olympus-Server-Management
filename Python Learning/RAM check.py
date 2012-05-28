#This program runs a memory test for windows or unix based operating systems

import Popen()

def check_system (OS_Type, OS_Platform, Platform_Release):
	import os, platform	
		print os.name
		platform.system()
		platform.release()
		
	os = platform.system() #defines os as the general operating system type determined above
	
		os [:] = [f for f in os if (f[len(f):len(f)] == "Windows")] #if windows...
		
		
			import win32com.client
			from ctypes import *
			from ctypes.wintypes import *
			import pythoncom
			import pywintypes
			import datetime


			class MEMORYSTATUS(Structure):
				fields = [
					('dwLength', DWORD),
					('dwMemoryLoad', DWORD),
					('dwTotalPhys', DWORD),
					('dwAvailPhys', DWORD),
					('dwTotalPageFile', DWORD),
					('dwAvailPageFile', DWORD),
					('dwTotalVirtual', DWORD),
					('dwAvailVirtual', DWORD),
					]


			def winmem():
				x = MEMORYSTATUS() 
				windll.kernel32.GlobalMemoryStatus(byref(x)) #FUNCTIONS FOR 32 BIT OPERATING SYSTEMS?
				return x    

# The following runs for Linux (unix based) operating Systems	
		os [:] = [f for f in os if (f[len(f):len(f)] == "Linux")] 
			import subprocess

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