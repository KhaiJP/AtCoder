using Primes
parInt(str=readline()) = parse(Int64, str)

function main()
  N = parInt()
  answer = 0
  q = 3
  while 2 * q^3 <= N
    if isprime(q) |> !
      q += 2
      continue
    end
    
    ref = N÷(q^3)
    answer += length(primes(2,min(ref, q-1)))
    q += 2
  end
  answer |> println
  return 0
end
main()