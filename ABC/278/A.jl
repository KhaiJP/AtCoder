function main()
    N,K = parse.(Int, readline()|>split)
    A   = parse.(Int, readline()|>split)
    for j in 1:N
        get(A, j+K, 0) |> print
        " "            |> print
    end
end
main()