parInts(str=readline()) = parse.(Int, str|>split)
function main()
  N, M = parInts()
  S = Vector{String}()
  for n in 1:N
    s = readline()
    push!(S, s[end-2:end])
  end

  t = Set{String}()
  for m ∈ 1:M
    T = readline()
    push!(t, T)
  end

  answer = 0
  for s in S
    answer += ( s ∈ t ? 1 : 0)
  end
  answer |> println
end
main()