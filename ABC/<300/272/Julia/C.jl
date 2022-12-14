parInts(str=readline()) = parse.(Int64, str|>split)
parInt(str=readline()) = parse(Int64, str)
function main()
  N = parInt()
  A = parInts()
  A_e = []
  A_o = []
  for a ∈ A
    a%2==0 ? push!(A_e, a) : push!(A_o, a)
  end
  (m_e, m_o) = (-1, -1)
  (sort!(A_e, rev=true), sort!(A_o, rev=true))
  if length(A_e) > 1
    m_e = A_e[1]+A_e[2]
  end
  if length(A_o) >1
    m_o = A_o[1] + A_o[2]
  end
  max(m_e, m_o) |> println
  return 0
end
main()