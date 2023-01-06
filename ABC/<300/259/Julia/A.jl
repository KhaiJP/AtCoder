function main()
  N, M, X, T, D = parse.(Int, readline()|>split)
  h_born = T-X*D
  if( M <= X )
    h_born + M*D |> println
  else
    T |> println
  end
end
main()