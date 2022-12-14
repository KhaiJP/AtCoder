function main()
    N = parse(Int64, readline())
    A = reverse([j for j ∈ 0:N])
    for a ∈ A
        a |> println
    end
end
main()