function make_prev!(arr, num)
    (_, index) = findmin(map(x -> x<num ? num-x : x, arr))
    head = arr[index]
    arr[index] = num
    pushfirst!(arr, head)
    return head
end

function main()
    N = parse(Int, readline())
    P = parse.(Int, readline()|>split)
    s = Vector{Int}()
    push!(s, pop!(P))
    while true
        tmp = pop!(P)
        if tmp < s[end]
            push!(s, tmp)
        else
            make_prev!(s, tmp)
            break
        end
    end
    for n ∈ P
        "$n " |> print
    end
    for n ∈ s
        "$n " |> print
    end
end
main()