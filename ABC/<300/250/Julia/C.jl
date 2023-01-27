parInts(str=readline()) = parse.(Int32, str|>split)
parInt(str=readline())  = parse(Int32, str)
function main()
  N, Q = parInts()
  getPosition = Dict{Int32, Int32}()
  answer = zeros(Int32, N)
  for i ∈ 1:N
    getPosition[i] = i
    answer[i] = i
  end
  for q ∈ 1:Q
    x = parInt()
    pos_x = getPosition[x]
    y = 0
    pos_y = 0
    if pos_x < N
      pos_y = pos_x + 1
    else
      pos_y = pos_x - 1
    end
    y = answer[pos_y]

    getPosition[x] = pos_y
    getPosition[y] = pos_x

    answer[pos_x] = y
    answer[pos_y] = x
  end
  for x ∈ answer
    "$x " |> print
  end
  return 0
end
main()