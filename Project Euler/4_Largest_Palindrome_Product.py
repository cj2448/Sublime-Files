#10,000-998001 996699


a = 999
numdict = {}
paliset = set()

while a > 99:
	for i in range(100, a+1):
		numdict[i] = a*i

	for k, v in numdict.items():
		if str(v) == str(v)[::-1]:
			paliset.add(v)

	a -= 1


print(max(paliset))