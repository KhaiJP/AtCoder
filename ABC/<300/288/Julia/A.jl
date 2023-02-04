parInt(str=readline()) = parse(Int, str)
parInts(str=readline()) = parse.(Int, str|>split)

function main()
  N = parInt()
  for n ∈ 1:N
    A, B = parInts()
    A+B |> println
  end
end
main()