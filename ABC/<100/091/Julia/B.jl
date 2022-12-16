function main()
  N = parse(Int, readline())
  ss = Dict{String, Int}()
  for n ∈ 1:N
    s = readline()
    haskey(ss, s) ? ss[s]+=1 : ss[s] = 1
  end
  M = parse(Int, readline())
  st = Dict{String, Int}()
  for m ∈ 1:M
    t = readline()
    if haskey(ss, t)
      ss[t] = max(ss[t]-1, 0)
    end
  end
  answer = 0
  for key ∈ keys(ss)
    answer = max(ss[key], answer)
  end
  answer |> println
end
main()
Dict{Int,Int}([j=>j for j in 1:2])[3]