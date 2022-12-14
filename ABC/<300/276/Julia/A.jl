function main()
    s = split(readline(), "")
    l = length(s)
    for j = 1:l
        tmp = pop!(s)
        if tmp=="a"
            return println(l-j+1)
        end
    end
    return println(-1)
end
main()