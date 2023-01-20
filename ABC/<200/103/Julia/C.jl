function main()
  N = readline()
  A = parse.(Int, readline() |> split)
  (A .|> a->a-1) |> sum |> println
end
main()