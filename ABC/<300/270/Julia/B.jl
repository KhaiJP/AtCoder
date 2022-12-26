function main()
  X, Y, Z = parse.(Int, readline()|>split)
  m = findmin([X,Y,Z])[1]
  if Y<0
      X *= -1
      Y *= -1
      Z *= -1
  end
  if X < Y
      abs(X) |> println
  elseif Z > Y
      -1 |> println
  else
      if Z < 0
          -2Z + X |> println
      else
          X |> println
      end
  end
  return 0
end
main()