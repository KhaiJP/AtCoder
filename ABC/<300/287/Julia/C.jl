parInt(str=readline()) = parse(Int, str)
parInts(str=readline()) = parse.(Int, str|>split)
using DataStructures
function main()
  N, M = parInts()
  E = Dict{Int, Vector{Int}}()
  UF = IntDisjointSets{Int}(N)
  for m ∈ 1:M
    u, v = parInts()
    union!(UF, u, v)
    if haskey(E, u)
      push!(E[u],v)
    else
      E[u] = [v]
    end
    if haskey(E, v)
      push!(E[v],u)
    else
      E[v] = [u]
    end
  end

  e1 = 0
  for u ∈ 1:N
    if !in_same_set(UF, u, 1) || !(haskey(E, u) && (length(E[u]) == 1 || length(E[u]) == 2))
      "No" |> println
      return 0
    end
    e1 += (length(E[u]) == 1 ) ? 1 : 0
  end

  (e1 == 2 ? "Yes" : "No") |> println
  return 0
end
main()