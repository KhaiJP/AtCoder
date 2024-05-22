main = do
    p <- product . map read . words <$> getLine
    putStrLn . check $ p


check :: Int -> String
check n
  | n `mod` 2 == 0 = "Even"
  | otherwise      = "Odd"

