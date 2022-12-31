function main()
  N, M = parse.(Int, readline()|>split)
  X = falses(N,M)
  for m ∈ 1:M
    tmpX = parse.(Int, readline()|>split)
    for n ∈ tmpX[2:end]
      X[n, m] = true
    end
  end
  Y = X*transpose(X)
  for j ∈ 1:N^2
    if Y[j] == 0
      "No" |> println
      return 0
    end
  end
  "Yes" |> println
end
main()