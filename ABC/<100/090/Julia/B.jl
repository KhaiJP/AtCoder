parInts(str=readline()) = parse.(Int, str|>split)
function isPalindromic(n)
  s = string(n)
  for j ∈ 1:(length(s)÷2)
    if s[j] != s[end-j+1]
      return false
    end
  end
  return true
end

function main()
  A, B = parInts()
  answer = 0
  for j ∈ A:B
    if isPalindromic(j)
      answer += 1
    end
  end
  answer |> println
end
main()