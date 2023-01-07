using Primes
function main()
  T = parse(Int, readline())
  for t ∈ 1:T
    N = parse(Int, readline())
    d = factor(N)
    ks = d |> keys
    for k ∈ ks
      if(d[k]==2)
        "$k " |>print
      end
    end 
    for k ∈ ks
      if(d[k]==1)
        "$k " |>println
      end
    end
  end
end
main()