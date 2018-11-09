import random as rd

ALPHABET = ['.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                   'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                   'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                   'u', 'v', 'w', 'x', 'y', 'z']

# n = rd.randint(10, 100)
# url = []
#
def newUrl(c):
    s = ""
    for i in range(c):
        s = s + (rd.choice(ALPHABET))
    return s
#
# for i in range(n):
#     s = newUrl(rd.randint(5, 30))
#     url.append(s)
#     print(s)
#
# print(-1)

n = rd.randint(10,200)
for i in range(n):
    p = rd.uniform(0, 1)
    s = newUrl(rd.randint(2, 5))
    print(s)
