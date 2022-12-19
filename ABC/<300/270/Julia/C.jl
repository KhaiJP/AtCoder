using DataStructures
"""
Find the path from Y to X instead
"""
function main()
  N, X, Y = parse.(Int, readline()|>split)
  Prev = Dict{Int, Int}()
  Edge = Dict{Int, Array{Int}}()
  # set edges 
  for _ ∈ 1:N-1
    U, V = parse.(Int, readline()|>split)
    haskey(Edge, U) ? push!(Edge[U], V) : Edge[U] = [V]
    haskey(Edge, V) ? push!(Edge[V], U) : Edge[V] = [U]
  end
  q = Deque{Int}()
  push!(q, Y)
  Prev[Y] = 0
  while q |> length |> iszero |> !
    u = pop!(q)
    if haskey(Edge, u) |> !
      continue
    end
    for v ∈ Edge[u]
      if haskey(Prev, v)
        continue
      end
      Prev[v] = u
      # show answer
      if v == X
        while v ≠ 0
          v |> print
          " " |> print
          v = Prev[v]
        end
        return 0
      end
      push!(q,v)
    end
  end
end
main()
