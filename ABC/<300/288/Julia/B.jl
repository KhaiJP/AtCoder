parInts(str=readline()) = parse.(Int, str|>split)
function main()
  N, K = parInts()
  
  S = Vector{String}([])
  for k ∈ 1:K
    s = readline()
    push!(S, s)
  end
  
  sort!(S)
  for s ∈ S
    s |> println
  end
end
main()