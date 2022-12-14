# exhaust memory limit
function main()
  vowels = ['a', 'e', 'i', 'o', 'u']
  for w ∈ readline()
    if w ∉ vowels
      w |> print
    end
  end
end
main()
