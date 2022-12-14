function main()
    H, W = parse.(Int, readline() |> split)

    # save S, T info as matrix
    S = Array{Char}(undef, H, W)
    for i in 1:H
        for (j,s) in enumerate(readline())
            S[i,j] = s
        end
    end
    T = Array{Char}(undef, H, W)
    for i in 1:H
        for (j,t) in enumerate(readline())
            T[i,j] = t
        end
    end

    # make column strings
    S_ = Array{String}(undef, W)
    for w in 1:W
        S_[w] = join(S[:, w])
    end
    T_ = Array{String}(undef, W)
    for w in 1:W
        T_[w] = join(T[:, w])
    end
    
    # if the sorted are same
    (sort(S_) == sort(T_)) ? "Yes"|>println : "No"|>println
end
main()