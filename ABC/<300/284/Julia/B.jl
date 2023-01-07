function main()
  T = parse(Int, readline())
  for _ ∈ 1:T
    N = parse(Int, readline())
    A = parse.(Int, readline()|> split)
    map(a -> a%2, A) |> sum |> println
  end
end
main()