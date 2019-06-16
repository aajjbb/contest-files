L = int(input())
N = str(input())

ans = 10**100000

l = L // 2
r = L // 2 + 1

while l > 0 and N[l] == '0':
    l -= 1
while r < L and N[r] == '0':
    r += 1

if l != 0:
    ans = min(ans, int(N[:l]) + int(N[l:]))

if r != L:
    ans = min(ans, int(N[:r]) + int(N[r:]))

print(ans)
