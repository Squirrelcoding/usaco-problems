n = int(input())
numbers = [int(k) for k in input().split()]

def solve(index, sum_a, sum_b):
    if index == n:
        return abs(sum_a - sum_b)
    
    # Try adding numbers[index] to either subset
    option1 = solve(index + 1, sum_a + numbers[index], sum_b)
    option2 = solve(index + 1, sum_a, sum_b + numbers[index])
    
    return min(option1, option2)

print(solve(0, 0, 0))


