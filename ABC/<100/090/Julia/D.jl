parInts(str=readline()) = parse.(Int, str|>split)
function main()
  N, K = parInts()
  answer = 0
  for b ∈ K+1:N
    answer += (N÷b)*(b-K) + max((N%b - K + 1), 0)
    answer -= (K==0 ? 1 : 0)
  end
  answer |> println
end
main()