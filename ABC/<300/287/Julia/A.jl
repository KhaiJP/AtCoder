parInt(str=readline()) = parse(Int, str)
function main()
  N = parInt()
  fr = 0
  for n ∈ 1:N
    S = readline()
    if S == "For"
      fr += 1
    end
  end
  (2fr > N ? "Yes" : "No") |> println
  return 0
end
main()