function main()
  N = parse(Int64, readline())
  mod::Int64 = 998_244_353
  x = N%mod
  (x ≥ 0 ? x : x+mod) |> println
end
main()