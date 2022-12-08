function localCost(p1::Array{Int}, p2::Array{Int})
    return abs(p2[1]-p1[1]) + abs(p2[2]-p1[2]) + max(0, p2[3]-p1[3])
end
function bitDP(M::Matrix{Int})
    R  = size(M)[2] # num of rows = num of site
    mS = 2^size(M)[2] # maximum number of the bit-expression of "sites that have been visited"
    DP = Inf.*ones(Float64, R, mS) # DP[current site, sites that have beem visited]
    DP[1,1] = 0
    for h ∈ 1:mS # h for histroy
        for cs ∈ 1:R # cr for current site
            if DP[cs,h] ≥ Inf
                continue
            end
            for ns ∈ 1:R # ns for next site
                if ns == cs || ((h-1)÷2^(ns-1))%2 == 1 # ns is already visited
                    continue
                end
                d = localCost(M[:, cs], M[:,ns])
                DP[ns, h+2^(ns-1)] = min(DP[ns, h+2^(ns-1)], DP[cs, h]+d)
            end
        end
    end
    return Int(floor(DP[1, mS]))
end

function main()
    N = parse(Int, readline())
    # Sites
    S = Array{Int}(undef, 3, N)
    for c ∈ 1:N
        S[:,c] = parse.(Int, readline()|>split)
    end
    # show
    bitDP(S) |> println
end
main()