function main()
    N, X = parse.(Int, readline()|>split)
    P    = parse.(Int, readline()|>split)
    for (i, c) in enumerate(P)
        if c == X
            i |> println
            return 0
        end
    end
end
main()

