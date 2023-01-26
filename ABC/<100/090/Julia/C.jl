parInts(str=readline()) = parse.(Int, str|>split)
function main()
  N, M = parInts()
  if N > 1 && M > 1
    (N-2)*(M-2) |> println
  elseif N == 1 && M == 1
    1 |> println
  else
    max(N,M) - 2 |> println
  end
end
main()