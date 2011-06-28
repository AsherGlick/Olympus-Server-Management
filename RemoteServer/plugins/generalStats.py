import time
import os
sendOut(("hello world, i am a plugin","seven"))

# Linux HDD Size / Used
s = os.statvfs('/')
bytesAvailable = (s.f_bavail * s.f_frsize) / 1024;
bytesTotal = (s.f_blocks * s.f_frsize) / 1024
bytesUsed = bytesTotal - bytesAvailable;
percentFree = (bytesAvailable*100)/(bytesTotal)
percentUsed = 100-percentFree
sendOut(("bytesFree",str(bytesAvailable),"\nbytesTotal",str(bytesTotal),"\npercentUsed",str(percentUsed),"\npercentFree",str(percentFree),))
time.sleep(220)
