import math

a = 1
b = 1
c = a + b

i = 2
while math.log10(b) < 999:
    i += 1
    b_copy = b
    b = a + b
    a = b_copy
    print(i, b)

# print(b)
