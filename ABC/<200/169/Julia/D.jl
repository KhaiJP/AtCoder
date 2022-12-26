using Primes
function main()
  N = parse(Int64, readline())
  pfs = factor(N)
  answer = 0
  for ord ∈ pfs |> values
    l_i = 1
    while ord-l_i ≥ 0
      ord -= l_i
      l_i += 1
      answer += 1
    end
  end
  answer |> println
end
main()