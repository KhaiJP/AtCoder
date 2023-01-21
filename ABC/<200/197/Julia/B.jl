function main()
  H, W, X, Y = parse.(Int, readline()|>split)
  S = Dict{Int, String}()
  for h ∈ 1:H
    S[h] = readline()
  end
  ans = 0
  for h ∈ 1:X-1
    if S[X-h][Y] != '#'
      ans += 1
    else
      break
    end
  end
  for h ∈ 1:H-X
    if S[X+h][Y] != '#'
      ans += 1
    else
      break
    end
  end
  for w ∈ 1:Y-1
    if S[X][Y-w] != '#'
      ans += 1
    else
      break
    end
  end
  for w ∈ 1:W-Y
    if S[X][Y+w] != '#'
      ans += 1
    else
      break
    end
  end
  ((ans + 1) * (S[X][Y]!='#' ? 1 : 0)) |> print
end
main()