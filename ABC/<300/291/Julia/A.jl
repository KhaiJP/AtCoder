function main()
  S::String = readline()
  for (i, c) ∈ enumerate(S)
    if c |> isuppercase
      i |> print
      return 0
    end
  end
end
main()