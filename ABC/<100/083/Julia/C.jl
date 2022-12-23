function main()
  X, Y = parse.(Int64, readline()|>split)
  ans::Int8 = 0
  while X ≤ Y
    X *= 2
    ans += 1
  end
  ans |> println
end
main()