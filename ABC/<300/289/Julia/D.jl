parInt( str=readline()) = parse.(Int, str)
parInts(str=readline()) = parse.(Int, str|>split)

function main()
  N = parInt()
  A = parInts()
  M = parInt()
  B = parInts()
  B = Set{Int}(B)
  X = parInt()

  dp = falses(X+1)
  dp[0 + 1] = true
  for n ∈ 1:X-1
    if !dp[n]
      continue
    end

    for a ∈ A
      if ( n + a > X+1 ) || ( (n + a - 1) ∈ B )
        continue
      end

      if n + a == X+1
        "Yes" |> println
        return 0
      end
      
      dp[n+a] = true
    
    end

  end

  "No" |> println
end
main()