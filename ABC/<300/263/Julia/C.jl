using DataStructures
function main()
  N, M = parse.(Int, readline()|>split)
  dq = Deque{Vector{Int}}()
  for n ∈ 1:M
    push!(dq,[n])
  end
  while dq |> isempty |> !
    L = popfirst!(dq)
    if L |> length == N
      for n ∈ L
        "$n " |> print
      end
      "" |> println
    else
      for n in L[end]+1:M
        push!(dq, vcat((L, [n])...))
      end
    end
  end
end
main()