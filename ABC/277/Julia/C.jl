using DataStructures
function main()
    N = parse(Int, readline())
    V = Dict{Int, Vector{Int}}()
    for _ ∈ 1:N
        u,v = parse.(Int, readline()|>split)
        haskey(V, u) ? push!(V[u], v) : V[u] = [v]
        haskey(V, v) ? push!(V[v], u) : V[v] = [u]
    end
    q = Deque{Int}()
    h = 1
    checked = Set{Int}(1)
    push!(q, 1)
    # BFS
    while !isempty(q)
        u = popfirst!(q)
        for v in get!(V, u, [])
            if !in(v, checked)
                push!(checked, v)
                push!(q, v)
                h = max(h, v)
            end
        end
    end
    h |> print
end
main()