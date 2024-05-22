main = do
  [n, y] <- map read . words <$> getLine
  let candidate = [[a, b, c] | a <- [0..n], b <- [0..(n-a)], let c = n - (a+b), c >= 0, cal a b c == y]
  if null candidate
    then putStrLn "-1 -1 -1"
    else putStrLn . unwords . map show . head $ candidate


cal :: Int -> Int -> Int -> Int
cal a b c = 10000*a + 5000*b + 1000*c

