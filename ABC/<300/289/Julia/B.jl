parInts(str=readline()) = parse.(Int, str|>split)
using DataStructures
function main()
  N, M = parInts()
  A = parInts()
  S = Stack{Int}()

  for n ∈ 1:N
    push!(S, n)

    if n ∉ A
      while S |> isempty |> !
        S |> pop! |> print
        ' ' |> print
      end
    end
    
  end

end
main()