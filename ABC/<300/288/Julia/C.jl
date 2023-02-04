parInts(str=readline()) = parse.(Int, str|>split)
using DataStructures
function main()
  N, M = parInts()
  uf = IntDisjointSets(N)

  answer = 0
  for m ∈ 1:M
    A, B = parInts()
    if in_same_set(uf, A, B)
      answer += 1
    else
      union!(uf, A, B)
    end
  end

  answer |> println
end
main()