main = do
  [n, a, b] <- map read . words <$> getLine
  let propers = [n | n <- [1..n], let d = digitSum n, a <= d, d <= b]
  print . sum $ propers


digitSum :: Int -> Int
digitSum n
  | n < 10 = n
  | otherwise = r + digitSum m
  where
    r = n `mod` 10
    m = n `div` 10

