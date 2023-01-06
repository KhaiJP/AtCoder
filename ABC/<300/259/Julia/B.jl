function main()
  a, b, d = parse.(Float64, readline()|>split)
  θ = π * d / 180
  M = [cos(θ) -sin(θ); sin(θ) cos(θ)]
  r = M*[a; b]
  "$(r[1]) $(r[2])" |> println
end
main()