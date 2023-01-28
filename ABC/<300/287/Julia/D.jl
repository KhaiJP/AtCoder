parInt(str=readline()) = parse(Int, str)
parInts(str=readline()) = parse.(Int, str|>split)
using DataStructures
using Primes
function main()
  S = readline()
  T = readline()
  s = S |> length
  t = T |> length

  f = trues(t+1)
  b = trues(t+1)
  for i ∈ 2:t+1
    f[i] = f[i-1] && ( S[i-1] == '?' || T[i-1] == '?' || S[i-1] == T[i-1])
    b[i] = b[i-1] && ( S[s-i+2] == '?' || T[t-i+2] == '?' || S[s-i+2] == T[t-i+2])
  end

  for i ∈ 1:t+1
    (f[i] && b[t-i+2] ? "Yes" : "No") |> println
  end
end
main()