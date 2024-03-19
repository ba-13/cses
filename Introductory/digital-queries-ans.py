def fast():
    for x in [int(input()) for j in range(int(input()))]:
        digit, length = 1, 1
        while x > digit*length*9:
            x -= digit*length*9
            digit, length = digit*10, length+1
        number, remain = divmod(x-1, length)
        print("pos", remain, end=" :: ")
        print("num", number+digit)
        print(str(number+digit)[remain])


def brute():
    for query in [int(input()) for j in range(int(input()))]:
        i = 0
        s = ""
        while len(s) <= query:
            i += 1
            s += str(i)
        # print(i)
        # print(s[query-3], end=" ")
        # print(s[query-2], end=" ")
        print(s[query-1])
