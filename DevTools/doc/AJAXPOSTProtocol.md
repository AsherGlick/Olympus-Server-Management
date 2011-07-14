### The web-browser post commands to receive data

POST REQUESTS

`[s]`            -serverlist  
`[p###]`         -plugin list (server)  
`[l###-###]`     -load plugin (server, plugin)  
`[d###-###]`     -plugin data (server, plugin)  



[s]

```
server1name,ip,num
server1name,ip,num&server2name,ip,num&server3name,ip,num
```

[p###]

```
&pluginname,numberofarguments,pluginID
pluginname,numberofarguments,pluginID&pluginname,numberofarguments,pluginID
```

[l###-###]

```
UIELEMENT,width,height,args*,*s
&UIELEMENT,width,height,args*,*s&UIELEMENT,width,height,args*,*s
```

[d###-###]

```
arg1,arg2,arg3,arg4,arg5
```
