from os import wait

n = 0
nums = []
for i in range(n):
    nums.append(int(input()))
results = []

def is_valid(n):
    return len(set(str(n))) == len(str(n))

def solve(n):
    res = []
    for s2 in range(1, 9876543210 // n):
        s1 = n * s2
        if is_valid(s1) and is_valid(s2):
            res.append((s1, s2))  
    return res

k = 1234567890

for solution in solve(k):
    print(f"{solution[0]} / {solution[1]} = {k}")

