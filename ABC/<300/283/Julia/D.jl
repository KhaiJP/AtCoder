"""
still in debugging
"""
function main()
  S = [c for c ∈ readline()]
  # already = Set{Char}()
  dic = Dict{Char, Int}([c=>0 for c in "abcdefghijklmnopqrstuvwxyz()"])
  rmost = Array{Int}([])
  for (index, c) ∈ enumerate(S)
    if c == '('
      push!(rmost, index)
    elseif c == ')'
      index_prev = pop!(rmost)
      for (lind, c) ∈ enumerate(S[index_prev+1:index-1])
        S[index_prev+lind] = ')'
        dic[c] -= 1
      end
    else
      if dic[c] != 0
        "No" |> println
        return 0
      else 
        dic[c] += 1
      end
    end
  end
  "Yes" |> println
  return 0
end
main()