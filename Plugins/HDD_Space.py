import os, platform, ctypes
print os.name
system = platform.system()
#print system

def get_free_space_Windows(folder):
    #Return drive free space in bytes on windows
    
    if platform.system() == 'Windows':
        free_bytes = ctypes.c_ulonglong(0)
        ctypes.windll.kernel32.GetDiskFreeSpaceExW(ctypes.c_wchar_p(folder), None, None, ctypes.pointer(free_bytes))
	return free_bytes.value
    else:
        return os.statvfs(folder).f_bfree
		
def get_free_space_Linux(folder):
	#Return drive free space in bytes on linux
	st = os.statvfs(folder)
	free = (st.f_bavail * st.f_frsize)
	total = (st.f_blocks * st.f_frsize)
	used = (st.f_blocks - st.f_bfree) * st.f_frsize
	try:
		percent = ret = (float(used) / total) * 100
	except ZeroDivisionError:
		percent = 0
	return data(total, used, free, round(percent, 1))
	
if platform.system() == 'Windows':
	get_free_space_Windows()
	print free_bytes.value

if patform.system() == 'Linux':
	get_free_space_Linux()
	print data

