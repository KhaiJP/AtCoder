function rotateAgainst(r::Vector{Float64}, ro::Vector{Float64}, θ::Float64)
  r = r .- ro
  M = [cos(θ) -sin(θ); sin(θ) cos(θ)]
  r = M*r
  r = r.+ ro
  return r
end
function main()
  N = parse(Float64, readline())
  r0 = parse.(Float64, readline()|>split)
  rN2 = parse.(Float64, readline()|>split)
  
  r_org = (r0 .+ rN2) ./ 2

  r1 = rotateAgainst(r0, r_org, 2*π/N)
  "$(r1[1]) $(r1[2])" |> println
end
main()