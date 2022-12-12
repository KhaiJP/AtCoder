function main()
    N = parse(Int, readline())
    N==1 ? A = parse(Int, readline()) : A = parse.(Int, readline()|>split)
    cnt = Dict{Int,Int}()
    for i ∈ 1:N
       cnt[A[i]] = get(cnt, A[i],0)+1
    end
    ks = sort([k for k ∈ keys(cnt)], rev=true)
    for K ∈ 1:N
        get(cnt, get(ks, K, -1), 0) |> println
    end
end
main()