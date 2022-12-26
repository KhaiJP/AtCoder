using Primes
is_false_then(bl::Bool) = !bl
function main()
  N, M = parse.(Int, readline()|>split)
  # Ps[j] = P(A[j]) = {p: p∈Prime ⩓ A[j]|p}
  Ps = parse.(Int, readline()|>split) .|> factor .|> keys
  S = trues(M)

  # P = {p: p∈Prime ⩓ A[j]|p}
  for P ∈ Ps
    for p ∈ P
      if p > M
        break
      end 
      if S[p] |> is_false_then
        continue
      end
      # crossing ouf the multiples of p by Eratosthens-ish method
      for n ∈ 1:(M÷p)
        S[n*p] = false
      end
    end
  end

  S |> sum |> println
  [s |> println for (s, b) ∈ S|>enumerate if b]
  return 0
end
main()