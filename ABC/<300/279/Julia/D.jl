## solve by differential
function main()
    A, B = parse.(Int, readline()|>split)
    f(x) = x==-1 ? Inf : A/(√(x+1)) + x*B
    # find f'(x) = 0
    x = (A/(2B))^(2/3)-1
    x_f = floor(x)
    x_c = x_f + 1
    f(x_f) < f(x_c) ? f(x_f)|>println : f(x_c)|>println 
end
main()