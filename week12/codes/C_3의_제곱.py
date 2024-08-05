import sys
lambda input:sys.stdin.readline().strip()

while (True):
    n = int(input())
    if not n: break
    n -= 1
    if not n:
        print("{ }")
        continue
    bit = 1
    p = 1
    ans = []
    while (True):
        if bit > n: break
        if bit & n:
            ans.append(p)
        p *= 3
        bit *= 2
    
    print("{ ", end='')
    print(*ans, sep=', ', end=' }\n')
