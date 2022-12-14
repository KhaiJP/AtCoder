function main()
  H, _ = parse.(Int, readline()|>split)
  answer = 0
  for __ in 1:H
    answer += sum(x->x=='#', readline())
  end
  answer |> println
end
main()

function main()
  H, _ = parse.(Int, readline()|>split)
  [sum(x->x=='#', readline()) for _ ∈ 1:H] |> sum |> println
end
main()