function main()
  S = readline()
  S = S |> reverse
  ans = 0
  # whatever other than '0'
  prev = '1'
  for c in S
    if c=='0' && prev == '0'
      # whatever other than '0'
      prev = '1'
      continue
    end
    prev = c
    ans += 1
  end
  ans |> println
end
main()