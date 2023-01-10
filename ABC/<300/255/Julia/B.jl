function main()
  N, K = parse.(Int, readline()|>split)
  S = Set{Int}()
  [push!(S, n) for n ∈ parse.(Int, readline()|>split)]
  L = []
  P = []
  for n ∈ 1:N
    X, Y = parse.(Int, readline()|>split)
    if n ∈ S
      push!(L, [X,Y])
    else
      push!(P, [X,Y])
    end
  end
  answer = 0
  for p ∈ P
    r = Inf64
    for l ∈ L
      r = min(r, (p[1]-l[1])^2+(p[2]-l[2])^2)
    end
    answer = max(answer, r)
  end
  answer |> sqrt |> println
end
main()