N = parse(Int, readline())
S = Set()
answer = 0
for j ∈ 1:N
  A = readline()
  if A ∈ S 
    global answer += 1
  else
    push!(S, A)
  end
end
answer |> println
