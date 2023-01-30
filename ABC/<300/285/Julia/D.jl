using DataStructures
parInt(str=readline())  =  parse(Int, str)

function main()
  N = parInt()
  checker = Dict{String, Int}()

  uf = IntDisjointSets(2N)
  kinds::Int = 1

  for n ∈ 1:N
    S, T = readline() |> split
    (nS, nT) = (0, 0)
  
    if haskey(checker, S)
      nS = checker[S]
    else
      nS = kinds
      checker[S] = kinds
      kinds += 1
    end

    if haskey(checker, T)
      nT = checker[T]
    else
      nT = kinds
      checker[T] = kinds
      kinds += 1
    end

    if in_same_set(uf, nS, nT)
      "No" |> println
      return 0
    end
  
    union!(uf, nS, nT)
  end
  
  "Yes" |> println
  return 0
end
main()