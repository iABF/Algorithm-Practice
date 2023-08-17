s = input().split(';')[:-1]
q = int(input())
mp = dict()

for kv in s:
    lst = kv.split('=')
    mp[lst[0]] = lst[1]

for _ in range(q):
    s = input()
    if s in mp:
        print(mp[s])
    else:
        print('EMPTY')

