parInts(str=readline()) = parse.(Int64, str|>split)
parInt(str=readline()) = parse(Int64, str)
function main()
    N = parInt()
    A = parInts()
    Σ_1 = sum(A)
    Σ_2 = sum(map(n->n^2, A))
    N*Σ_2 - Σ_1^2 |> println
end
main()