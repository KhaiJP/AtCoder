function main()
    # H, W, N, h, w = parse.(Int, readline()|>split)
    # A = Matrix(undef, H, W)
    # for h_ in 1:H
    #     A[h_, :] = parse.(Int, readline()|>split)
    # end
    H, W, N, h, w = 3, 4, 5, 2, 2
    A = [2 2 1 1; 3 2 5 3; 3 4 4 3]
    for k in 0:H-h
        for l in 0:W-w
            Uset = Set{Int}(A[1:k, :])
            union!(Uset, Set{Int}(A[k+1:k+h, 1:l]))
            union!(Uset, Set{Int}(A[k+1:k+h, l+w+1:W]))
            union!(Uset, Set{Int}(A[k+h+1:H, :]))
            Uset |> length |> x->string(x)*" " |> print
            Uset = nothing
        end
        "" |> println
    end
end

function main()
    # H, W, N, h, w = parse.(Int, readline()|>split)
    # A = Matrix(undef, H, W)
    # for h_ in 1:H
    #     A[h_, :] = parse.(Int, readline()|>split)
    # end
    H, W, N, h, w = 3, 4, 5, 2, 2
    # A = [2 2 1 1; 3 2 5 3; 3 4 4 3]
    A = zeros(Int, 3,4,2)
    A[1, :, 1] = [2 2 1 1]
    A[2, :, 1] = [3 2 5 3]
    A[3, :, 1] = [3 4 4 3]
    for k in 0:H-h
        for l in 0:W-w
            A[k+1:k+h, l+1:l+w,1], A[k+1:k+h, l+1:l+w,2] = A[k+1:k+h, l+1:l+w,2], A[k+1:k+h, l+1:l+w,1]
            length(Set{Int}(A[:,:,1]))-1 |> print
            " " |> print
            A[k+1:k+h, l+1:l+w,1], A[k+1:k+h, l+1:l+w,2] = A[k+1:k+h, l+1:l+w,2], A[k+1:k+h, l+1:l+w,1]
        end
        "" |> println
    end
end

function main()
    # H, W, N, h, w = parse.(Int, readline()|>split)
    # A = Matrix(undef, H, W)
    # for h_ in 1:H
    #     A[h_, :] = parse.(Int, readline()|>split)
    # end
    H, W, N, h, w = 3, 4, 5, 2, 2
    A = [2 2 1 1; 3 2 5 3; 3 4 4 3]
    count = zeros(Int, H, W, N)
    # [1, :, 1] = [2 2 1 1]
    # A[2, :, 1] = [3 2 5 3]
    # A[3, :, 1] = [3 4 4 3]
    
end
main()
H, W, N, h, w = 3, 4, 5, 2, 2
A = [2 2 1 1; 3 2 5 3; 3 4 4 3]
# 3 4 5 2 2
# 2 2 1 1
# 3 2 5 3
# 3 4 4 3

# 4 4 3 
# 5 3 4 
main()

a = [[1, 2, 3], [3, 4, 5], [1, 2, 7], [5, 6, 8]]
a = transpose(hcat(a...))
s = Set{Int}(a)
a[1:2, 2:3] = [0 0; 0 0]
a
zeros(Int, 2,3)
a[1:0, 1:0]
s1 = Set(1)
s2 = Set(2)
s3 = Set(3)
union(s1, s2, s3)
zeros(Int, 2,3,4)