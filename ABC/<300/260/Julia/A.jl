function main()
  S::String = readline()
  d = Dict{Char, Int}()
  for c ∈ S
    haskey(d, c) ? d[c]+=1 : d[c] = 1
  end
  for k ∈ d |> keys
    if d[k] == 1
      k |> println
      return 0
    end
  end
  -1 |> println
  return 0
end
main()