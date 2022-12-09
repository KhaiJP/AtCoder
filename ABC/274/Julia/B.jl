function main()
    H, W = parse.(Int, readline()|>split)
    C = Array{Int}(undef,W,H)
    for h ∈ 1:H
        C[:, h] = [s=='#' ? 1 : 0 for s in readline()]
    end
    C = transpose(C)
    for w ∈ 1:W
        "$(map(x->x==1, C[:,w]) |> sum) " |> print
    end
end
main()