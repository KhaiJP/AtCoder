main = do
    n <- getLine
    as <- map read . words <$> getLine
    let answer = minimum . map count2s $ as
    print answer


count2s :: Int -> Int
count2s 0 = 0
count2s n
    | r == 0    = 1 + count2s m
    | otherwise = 0
    where
        r = n `mod` 2
        m = n `div` 2

