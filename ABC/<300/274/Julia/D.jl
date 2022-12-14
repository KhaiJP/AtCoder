function isAchievable(Arr::Array{Int}, t::Int, isY::Bool)
    L = sum(Arr)
    N = length(Arr)
    #Dynamic Programming matirx.
    DP = zeros(Int, 2L+1, N)
    DP[Arr[1]+L+1, 1] = 1
    if isY # p1, X direction, must be (A1,0), cannot be (-A1,0)
        DP[-Arr[1]+L+1, 1] = 1
    end
    # DP
    for col = 2:N
        a = Arr[col]
        for row = 1:2L+1
            if get(DP, (row-a, col-1), 0) == 1
                DP[row, col] = 1
            end
            if get(DP, (row+a, col-1), 0) == 1
                DP[row, col] = 1
            end
        end
    end
    
    return (get(DP,(t+L+1, N), 0) == 1)
end
function main()
    N, x, y = parse.(Int, readline()|>split)
    A = parse.(Int, readline()|>split)
    # A_e = {Ai | Ai ∈ A and i ∈ even}
    A_e = Array{Int}([])
    # A_e = {Ai | Ai ∈ A and i ∈ odd}
    A_o = Array{Int}([])
    for (i, a) ∈ enumerate(A)
        i%2==0 ? push!(A_e, a) : push!(A_o, a)
    end
    ( isAchievable(A_o, x, false) && isAchievable(A_e, y, true)) ? "Yes"|>print : "No"|>print
end
main()
