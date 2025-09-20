qntd = int(input(""))
n = input("")

listn = list(map(int, n.split()))

count = 0
total = 0
for i in range(qntd, -1, -1):
    if listn[i] == True:
        total = total + 2**count
    count+=1

contador = 0

while True:
    if total != 1:
        if total%2==0:
            total = total //2
            contador+=1
        else:
            ref = total
            total = total*2 + 1
            total = (total*2 + 1)^total
    else:
        break

print(contador)