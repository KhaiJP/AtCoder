parInts(str=readline()) = parse.(Int, str|>split)
function main()
  N, M = parInts()
  if N > 1 && M > 1
    (N-2)*(M-2) |> println
    return 0
  elseif N == 1 && M == 1
    1 |> println
    return 0
  else
    max(N,M) - 2 |> println
    return 0
  end
end
main()