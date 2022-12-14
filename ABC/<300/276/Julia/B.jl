function main()
    N, M = parse.(Int, readline()|>split)
    V = Dict{Int, Vector{Int}}()
    for _ = 1:M
        A, B = parse.(Int, readline()|>split)
        haskey(V, A) ? push!(V[A], B) : V[A] = [B]
        haskey(V, B) ? push!(V[B], A) : V[B] = [A]
    end
    for u = 1:N
        if haskey(V, u)
            V[u] |> length |> print
            for w ∈ sort(V[u])
                " $w" |> print
            end
            "" |> println
        else
            0 |> println
        end
    end
end
main()
