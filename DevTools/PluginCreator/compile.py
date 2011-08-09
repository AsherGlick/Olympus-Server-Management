import sys

if (len(sys.argv) < 2):
	sys.exit("No Compile Target Given")
print "you wanted to check the file", sys.argv[1]

# go through the entire file and look for all of the
