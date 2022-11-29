function isConfusing(H, M)
    A = (H > 9) ? H÷10 : 0
    B = H%10
    C = (M > 9) ? M÷10 : 0
    D = M%10
    return (0≤ 10A+C ≤23) && (0≤ 10B+D ≤59)
end
function nextTime(H, M)
    M += 1
    if M == 60
        M = 0
        H = (H==23) ? 0 : H+1
    end
    return H, M
end
function main()
    H, M = parse.(Int, readline() |> split)
    while true
        if !isConfusing(H, M)
            H, M = nextTime(H, M)
        else
            H |> x->string(x)*" " |> print
            M |> print
            return 0
        end
    end
end
main()
