parInt( str=readline()) = parse.(Int, str)
parInts(str=readline()) = parse.(Int, str|>split)
using DataStructures
function main()
  N, M = parInts()
  S = Vector{Set{Int}}()
  
  for m ∈ 1:M
    C = parInt()
    s = parInts()
    tmpS = Set{Int}(s)
    push!(S, tmpS)
  end

  answer = 0

  for n ∈ 1:2^M-1
    ref = Set{Int}()
    ord = 1
    while n > 0
      if n%2 == 1
        union!(ref, S[ord])
      end
      ord += 1
      n ÷= 2
    end
    answer += length(ref) == N
  end

  answer |> println  
end
main()