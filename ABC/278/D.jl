function main()
    N = parse(Int64, readline())
    A = Dict{Int,Int}(i => c for (i,c) in enumerate(parse.(Int, readline()|>split)))
    Q = parse(Int64, readline())
    bias = 0
    for _ in 1:Q
        q = parse.(Int64, readline()|>split)
        if q[1] == 1
            bias = q[2]
            A = Dict{Int, Int}()
        elseif q[1] == 2
            haskey(A, q[2]) ? A[q[2]] += q[3] : A[q[2]] = q[3]
        else
            haskey(A, q[2]) ? (A[q[2]] + bias) |> println : bias |> println
        end
    end
end
main()