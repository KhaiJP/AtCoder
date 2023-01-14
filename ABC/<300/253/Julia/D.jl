function main()
  N, A, B = parse.(Int64, readline()|>split)
  ans = N*(N+1)÷2
  k = N÷A
  sumA  = A*k*(k+1)÷2
  k = N÷B
  sumB  = B*k*(k+1)÷2
  AB = lcm(A,B)
  k = N÷(AB)
  sumAB = AB*k*(k+1)÷2
  ans = ans - (sumA+sumB) + sumAB  
  ans |> println
end
main()