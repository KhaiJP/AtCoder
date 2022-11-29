function main()
    N = parse(Int, readline())
    A = parse.(Int, readline()|>split)
    A2 = zeros(N)
    A3 = zeros(N)
    for i ∈ 1:N
        while A[i]%2 == 0
            A[i] ÷= 2
            A2[i] += 1
        end
        while A[i]%3 == 0
            A[i] ÷= 3
            A3[i] += 1
        end
    end
    if sum(map(x->x==A[1], A)) ≠ N
        -1 |> print
        return 0
    end
    m2 = findmin(A2)[1]
    m3 = findmin(A3)[1]
    n2 = sum(map(a2 -> a2 - m2, A2))
    n3 = sum(map(a3 -> a3 - m3, A3))
    Int(n2 + n3) |> print
end
main()