main :: IO ()
main = do
    _ <- getLine
    as <- map read . words <$> getLine
    let result = foldl update [] as
    print $ length result


update :: [Int] -> Int -> [Int]
update [] y = [y]
update ls@(x:xs) y
    | x == y    = update xs (y + 1)
    | otherwise = y : ls 
