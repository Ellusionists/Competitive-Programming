#!/bin/python

import sys


x1,v1,x2,v2 = raw_input().strip().split(' ')
x1,v1,x2,v2 = [int(x1),int(v1),int(x2),int(v2)]


flag=1
for i in range(10000):
    x1+=v1
    x2+=v2
    if(x1==x2):
        flag=0
        break


if flag==1:
    print("NO")
else:
    print("YES")
