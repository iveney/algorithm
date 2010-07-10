#!/usr/bin/python

def factorial(n):
	product=1
	for i in xrange(1,n+1):
		product*=i
	return product

def choose(n,m):
	return factorial(m)/(factorial(n)*factorial(m-n))

ms=[7,5,3,2,1]
ns=[2,2,1,1,1]

x=map(choose,ns,ms)
#print 8*reduce(lambda x,y:x*y,x)
X=26**6-25**6

sum=0
for i in range(1,7):
	sum+=choose(i,6)*(24**(6-i))

print sum
print "b=",X-sum

print 5*24*23*22*21
print choose(2,6)*24*23*22*21

print factorial(8)/4
print choose(4,24)*factorial(5)**2
print factorial(7)*8/4
