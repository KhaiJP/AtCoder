using DataStructures
function main()
  N, M = parse.(Int, readline()|>split)
  uf = IntDisjointSets(N)
  for m ∈ 1:M
    u, v = parse.(Int, readline()|>split)
    union!(uf, u,v)
  end
  num_groups(uf) |> println
end
main()