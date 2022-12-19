function main()
    A, B = parse.(Int, readline()|>split)
    A|B |> println
end
main()