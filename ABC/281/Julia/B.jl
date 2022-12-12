function main()
    S = readline()
    # boolean ? "Yes" : "No"
    ans = (length(S)==8 && 
           isuppercase(S[1]) && 
           isuppercase(S[end]) && 
           S[2] ≠ '0' && 
           all(isdigit, S[2:(end-1)])) ? 
           "Yes" : 
           "No"
    ans |> println
end
main()
