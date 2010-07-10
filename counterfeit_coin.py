#!/usr/bin/python

n=10

def f(n):
	if n==1:
		return 0
	mini=1000000
	#ret = -1
	for x in xrange(1,n/2+1):
		current=max(x,n-2*x)
		if current<mini:
			mini=current
			#ret=current
	return f(mini)+1

def g(n):
	DP=[]


a=list(15)
a[10]=5
print a[10]
print a[5]

print f(8)
print f(9)
print f(27)
print f(28)
print f(81)
print f(82)
