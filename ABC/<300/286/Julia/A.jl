using DataStructures
using Primes
parInt(str=readline()) = parse(Int, str)
parInts(str=readline()) = parse.(Int, str|>split)
function main()
  N, P, Q, R, S = parInts()
  A = parInts()
  for i in 1:P-1
    A[i] |> print
    " " |> print
  end
  for i in 0:(Q-P)
    A[i+R] |> print
    " " |> print
  end
  for i in Q+1:R-1
    A[i] |> print
    " " |> print
  end
  for i in 0:S-R
    A[i+P] |> print
    " " |> print
  end
  for i in S+1:N
    A[i] |> print
    " " |> print
  end
end
main()