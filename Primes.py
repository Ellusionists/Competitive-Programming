def sieve(upto):
	limit=upto+1
	a=[True]*limit
	a[0]=False
	a[1]=False
	b=[]
	for i in range(2,limit):
		for j in range(i*i,limit,i):
			a[j]=False

		if a[i]==True:
			#b.append(i)
			print i
	#return b

n=int(raw_input())
sieve(n)


