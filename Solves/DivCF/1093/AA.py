t = int(input())
S = [input() for i in range(t)]
for i in range(t):
    word = list(S[i])
    if len(set(word)) == 1: print(-1)
    else:
        word.sort()
        print("".join(map(str, word)))

      #earlgrey_yh