function main()
  N, L   = parse.(Int32, readline()|>split)
  A      = parse.(Int32, readline()|>split)
  for (j, a) ∈ enumerate(A|>reverse)
    if a |> iseven
      ( L-sum(A[1:end-j]) - N+j ≥ 2 ? "Yes" : "No" ) |> println
      return 0
    end
  end
  "Yes" |> println
end
main()