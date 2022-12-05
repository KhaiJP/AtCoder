function f(n, A, B)
    return n==-1 ? Inf : A/(√(n+1)) +n*B
end
function main()
    A, B = parse.(Int, readline()|>split)
    # find f'(x) = 0
    x = (A/(2B))^(2/3)-1
    x_f = floor(x)
    x_c = x_f + 1
    f(x_f, A, B) < f(x_c, A, B) ? f(x_f, A, B)|>println : f(x_c, A, B)|>println 
end
main()