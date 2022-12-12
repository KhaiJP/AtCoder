function main()
    H, W = parse.(Int, readline()|>split)
    C = fill(false, W, H)
    for h ∈ 1:H
        C[:, h] = [s=='#' for s in readline()]
    end
    C = transpose(C)
    for w ∈ 1:W
        "$(C[:,w] |> sum) " |> print
    end
end
main()