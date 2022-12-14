function main()
  N = parse(Int64, readline())
  A = parse.(Int64, readline()|>split)
  B1 = sum([a*(-1)^(j-1) for (j, a) ∈ enumerate(A) ])
  "$B1 " |> print
  for j ∈ 2:N
    B1 = 2A[j-1] - B1
    "$B1 " |> print
  end
end
main()