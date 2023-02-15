if __name__ == "__main__":
    INF = 10**10

    N = int(input().strip())
    h = list(map(int, input().split()))
    h.append(-INF)
    
    dp = [INF for _ in range(N+10)]
    dp[0] = 0

    for i in range(0, N-1):
        dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]))
        dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]))

    print(dp[N-1])
    