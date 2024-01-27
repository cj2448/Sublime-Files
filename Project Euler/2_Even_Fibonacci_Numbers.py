cap = 4000000

numlist = [1, 2]
even = set()
numsum = 0

while numsum < cap:
	for i in numlist:
		if i%2 == 0:
			even.add(i)

	a = numlist[0]
	b = numlist[1]

	numlist.clear()
	numsum = a+b
	numlist.append(b)
	numlist.append(numsum)

print(numlist)
print(numsum)
print(sum(even))