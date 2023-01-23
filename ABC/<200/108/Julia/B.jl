function main()
  x1, y1, x2, y2 = parse.(Int, readline()|>split)
  r12 = Vector{Int}([x2-x1, y2-y1])
  r3  = Vector{Int}([x2-r12[2] , y2+r12[1]])
  r4  = Vector{Int}([r3[1]-r12[1], r3[2]-r12[2]])
  "$(r3[1]) $(r3[2]) $(r4[1]) $(r4[2])" |> println
end
main()