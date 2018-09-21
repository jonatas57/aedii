#/usr/bin/python3

import random as rd

n = 10000
lista = []
search = []
print(n)
for i in range(n):
    a = rd.randint(0, 100000)
    lista += [a]
    b = rd.randint(0, 1)
    if b == 1:
        search += [a]
    else:
        search += [rd.randint(0, 100000)]

for i in range(n):
    print(lista[i], end=' ')
print()
for i in range(n):
    print(search[i], end=' ')
print()
print(-1)

lista.sort()

for i in range(n):
    print(lista[i], end=' ')
print()
for i in range(n):
    print(search[i], end=' ')
print()
print(-1)
