function main()
    N, T = parse.(Int64, readline()|>split)
    A = parse.(Int64, readline()|>split)
    # prefix sum
    pfx = [0]
    for j ∈ 1:N
        push!(pfx, pfx[end]+A[j])
    end
    # current time
    ct = T%pfx[end]
    for (index, t) ∈ enumerate(pfx)
        if ct < t
            "$(index-1) $(A[index-1]-t+ct)" |> println
            break
        end
    end                 
end
main()