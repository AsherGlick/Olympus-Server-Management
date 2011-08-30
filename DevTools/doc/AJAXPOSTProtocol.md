### The web-browser post commands to receive data

POST REQUESTS

`[s]`            -serverlist  
`[p###]`         -plugin list (server)  
`[l###-###]`     -load plugin (server, plugin)  
`[d###-###]`     -plugin data (server, plugin)  



Server List [s]  
---------------
    server1name,ip,num
    server1name,ip,num&server2name,ip,num&server3name,ip,num
Example  
`Chronos,192.168.1.100,23fa80ad&Demeter,10.0.0.50,8fj30xz&Local,127.0.0.1,0`

Server  | IP Address    | Public Key Fingerprint
--------|---------------|-----------------------
Chronos | 192.168.1.100 | 23fa80ad
Demeter | 10.0.0.50     | 8fj30xz
Local   | 127.0.0.1     | 0
There are no arguments for this request and when sent the POST request should simply be `s`
Plugin List [p###]
------------------
    pluginname,numberofarguments,pluginID  
    pluginname,numberofarguments,pluginID&pluginname,numberofarguments,pluginID

UI List [l###-###]
------------------  
    UIELEMENT,width,height,args*,*s
    UIELEMENT,width,height,args*,*s&UIELEMENT,width,height,args*,*s

Plugin Data [d###-###]
----------------------
    arg1,arg2,arg3,arg4,arg5,...,argN
