import Data.List ( sort )


main :: IO ()
main = print . count . sort =<< readInts


count :: [Int] -> Int
count = count' 0


count' :: Int -> [Int] -> Int
count' n xs
    | a == c    = n
    | a == b    = count' (n+1) [a+1, b+1, c]
    | otherwise = count' (n+1) xs'
    where
        [a, b, c] = xs
        xs' = sort [a+2, b, c]


readInts :: IO [Int]
readInts = map read . words <$> getLine
