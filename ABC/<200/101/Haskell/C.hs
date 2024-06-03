main :: IO ()
main = do
    [n, k] <- map read . words <$> getLine
    let ans = (n - 1 + (k - 1) - 1) `div` (k - 1)
    print (ans :: Int)
