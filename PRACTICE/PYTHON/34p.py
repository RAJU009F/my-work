#!usr/bin/python
def iseq(x):
    x4=4*x
    xs=str(x)
    x4s=int(str(x)[::-1])
  
    
    lxs=len(xs)
    lx=lxs-1
    i=0;

    if x4==x4s:
        print xs,x4s
        return True
         
     
    return False       
    
    
    

x=1000;
while True:
    if iseq(x):
        print x
        break
    else:
        x+=1
     
        
        
            
        
