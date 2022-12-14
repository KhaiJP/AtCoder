# memorization
function f(k, D)
    if haskey(D, k)
        return D[k]
    else
        result = f(k÷2, D) + f(k÷3, D)
        D[k]  = result
        return result
    end
end
function main()
    N = parse(Int, readline())
    D = Dict{Int, Int}()
    D[0] = 1
    f(N, D) |> println
end  
main()