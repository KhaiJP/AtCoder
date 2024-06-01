main :: IO ()
main = do
    n <- readLn
    print . solve $ n


solve :: Int -> Int
solve = solve' 1 1 0


solve' :: Int -> Int -> Int -> Int -> Int
solve' a b ans n
    | a == n    = ans
    | c <= 0    = solve' (a+1) 1 ans n
    | otherwise = solve' a (b+1) (ans+1) n
    where c = n - a*b
