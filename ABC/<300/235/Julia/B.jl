function main()
  N = readline()
  H = parse.(Int, readline()|>split)
  answer = 0
  for h ∈ H
    if h > answer
      answer = h
    else
      answer |> println
      return 0
    end
  end
  answer |> println
  return 0
end
main()