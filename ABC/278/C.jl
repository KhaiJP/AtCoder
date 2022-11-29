function main()
    N, Q = parse.(Int, readline()|>split)
    D = Dict{Int64, Set{Int64}}()
    for _ = 1:Q
        T, A, B = parse.(Int, readline()|>split)
        if T==1
            if haskey(D, A)
                push!(D[A], B)
            else
                D[A] = Set([B])
            end
        elseif T==2
            if haskey(D, A) &&  in(B, D[A])
                pop!(D[A], B)
            end
        elseif T==3
            if haskey(D, A) && haskey(D, B) && in(B, D[A]) && in(A, D[B])
                "Yes" |> println
            else
                "No" |> println
            end
        end
    end
end
main()