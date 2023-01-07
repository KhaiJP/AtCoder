function main()
  N = parse(Int, readline())
  S = fill(" ", N)
  for j ∈ 1:N
    S[j] = readline()
  end
  reverse!(S)
  for s ∈ S
    s |> println
  end
end
main()