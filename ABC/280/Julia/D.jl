parInts(str=readline()) = parse.(Int64, str|>split)
parInt(str=readline()) = parse(Int64, str)
using Primes
function find_minimum_factorial(p, r)
  num_of_p_in_N = 0
  for r_ ∈ 1:r
    num_of_p_in_N += power_of_p(r_*p, p)
    if num_of_p_in_N ≥ r
      return r_*p
      break
    end
  end
end
function power_of_p(N, p::Int64)
  result = 0
  while N%p == 0
    result+=1
    N ÷= p
  end
  return result
end

function main()
  K = parInt()
  # Dict-like object K = ∏_k p_j^r_j ⇔ D[p_j] = r_j 
  D = factor(K)
  prime_factors = (D |> keys)
  answer = 0
  for p ∈ prime_factors
    r = D[p]
    Np = find_minimum_factorial(p, r)
    answer = max(answer, Np)
  end  
  answer |> println
end
main()