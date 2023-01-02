function main()
  S = "atcoder"
  L, R = parse.(Int, readline()|>split)
  S[L:R] |> println
  return 0
end
main()