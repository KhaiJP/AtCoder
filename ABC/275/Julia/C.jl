function get_num(r,c)
    return 9*(r-1)+c
end

function get_rc(n)
    r = (n-1)÷9+1
    c = (n-1)%9+1
    return (r,c)
end

function main()
    # v: vector that contains the addresses of #
    v = Array{Int}([])
    for i in 1:9
        S = split(readline(), "")
        for (j, s) ∈ enumerate(S)
            if s == "#"
                push!(v, get_num(i,j))
            end
        end
    end
    # st: set of squares=set{{p1, p2, p3, p4}}
    st = Set{Set{Int}}()
    for (i, p1)  ∈ enumerate(v)
        for j ∈ i+1:length(v)
            p2 = v[j]
            (r1, c1) = get_rc(p1)
            (r2, c2) = get_rc(p2)
            if c2 > c1
                Δr, Δc = (r2-r1, c2-c1)
                (r3, c3) = (r1+Δc, c1-Δr)
                (r4, c4) = (r2+Δc, c2-Δr)
                if 1≤r3≤9 && 1≤c3≤9 && 1≤r4≤9 && 1≤c4≤9 
                    p3 = get_num(r3, c3)
                    p4 = get_num(r4, c4)
                    if p3 ∈ v && p4 ∈ v
                        push!(st, Set([p1,p2,p3,p4]))
                    end
                end
            end
        end
    end
    st |> length |> println
end
main()