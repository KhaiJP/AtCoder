function main()
  S = readline()
  r = r"^(?:dream(?:er)?|eraser?)+$"
  (occursin(r, S) ? "YES" : "NO") |> println
end
main()
