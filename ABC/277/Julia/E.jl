using DataStructures
function main()
    N, M, K = parse.(Int64, readline()|>split)
    E =  Array{Array{Pair{Int64,Int64}}}([ [] for _ ∈ 1:2N])
    for _ ∈ 1:M
        u, v, a = parse.(Int64, readline()|>split)
        if a == 0
            u += N
            v += N
        end
        push!(E[u], v=>1)
        push!(E[v], u=>1)
    end
    S = parse.(Int64, readline()|>split)
    for u ∈ S
        push!(E[u], u+N=>0)
        push!(E[u+N], u=>0)
    end
    # 01-BFS
    q = Deque{Int64}()
    push!(q, 1)
    INF::Int64 = 10^9
    dist = Array{Int}([INF for _ ∈ 1:2N])
    dist[1] = 0
    while length(q) > 0
        u = popfirst!(q)
        for pair ∈ E[u]
            v::Int64, d::Int64  = pair
            if dist[u] + d < dist[v]
                dist[v] = dist[u] + d
                d==1 ? push!(q,v) : pushfirst!(q,v)
            end
        end
    end
    cost::Int64 = (min(dist[N], dist[2N]))
    cost = cost < INF ? Int64(cost) : -1 
    cost |> println
end
main()

