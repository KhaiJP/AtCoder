using Primes
function main()
  X = parse(Int, readline())
  X |> nextprime |> println
end
main()