import sys

if (len(sys.argv) < 2):
  sys.exit("No Compile Target Given")
print "you wanted to check the file", sys.argv[1]



def getNumArgs(inString):
  parenCount = 0
  quote = 0
  argCount = 0
  for i in range(len(inString)):
    if inString[i] == '"':
      quote = 1-quote # quote equals 1 or 0
    elif quote == 0: 
      if inString[i] == '(':
        parenCount += 1
      elif inString[i] == ')':
        parenCount -= 1
      elif inString[i] == '\\':
        i += 1
        continue
      elif ((inString[i] == ',') and (parenCount == 1)):
        argCount += 1;
    else:
      continue
    if parenCount == 0:
      break
  return argCount





# go through the entire file and look for all of the instances of sendOut()

f = open(sys.argv[1],'r').read()
sites = f.split("sendOut")
for site in sites:
  print getNumArgs(site)
  
  

