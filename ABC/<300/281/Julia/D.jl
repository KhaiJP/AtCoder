parInts(str=readline()) = parse.(Int64, str|>split)
parInt(str=readline()) = parse(Int64, str)
function main()
  N, K, D = parInts()
  A = parInts()
  # DP[n, k, d]: the maximum value when k-1 values from A[1] to A[n-1] with mod D equals d-1.
  # Hence the answer is DP[N+1, K+1, 0]
  DP = fill(-1, N+1, K+1, D)
  DP[1, 1, 1] = 0
  for n ∈ 1:N
    for k ∈ 1:K+1
      for d ∈ 1:D
        # DP[n,k,d]=-1 ⇒ (mod D = d-1) cannot achieved by chosing k-1 values from A[1] to A[n-1]
        if DP[n, k, d] == -1
          continue
        end
        # when A[n] is not taken
        DP[n+1, k, d] = max(DP[n+1, k, d], DP[n, k, d]) # DP[n+1,k,d] turns to be ≥ 0
        #  when A[n] is taken
        if k!=K+1
          DP[n+1, k+1, (d-1+A[n])%D+1] = max(DP[n+1, k+1, (d-1+A[n])%D+1], 
                                             DP[n, k, d] + A[n])
        end
      end
    end
  end
  DP[N+1, K+1, 1] |> println
end
main()