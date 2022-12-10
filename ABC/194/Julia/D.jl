parInts(str=readline()) = parse.(Int64, str|>split)
parInt(str=readline()) = parse(Int64, str)
function main()
    N = parInt()
    ans::Float64 = 0
    for n ∈ 1:(N-1)
        ans += 1/n
    end
    N*ans |> println
end
main()