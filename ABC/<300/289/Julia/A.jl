function main()
  s = readline()
  for c ∈ s
    ( c == '0' ? '1' : '0' ) |> print
  end
end
main()