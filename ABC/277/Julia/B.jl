function main()
    N = parse(Int, readline())
    s1 = Set{Char}(['H', 'D', 'C', 'S'])
    s2 = Set{Char}(['A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'])
    ss = Set{String}()
    flag = true
    for _ in 1:N
        S = readline()
        if !in(S[1], s1) || !in(S[2], s2) || in(S, ss)
            flag = false
            break
        end
        push!(ss, S)
    end
    flag ? "Yes" |> print : "No" |> print
end
main()
