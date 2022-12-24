parInts(str=readline()) = parse.(Int, readline()|>split)

function main()
  A, B = parInts()
  A^B |> println
end
main()