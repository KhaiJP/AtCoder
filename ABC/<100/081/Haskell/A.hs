main = do
    answer <- solve <$> getLine
    print answer

solve :: String -> Int
solve [] = 0
solve (c:cs) = t + solve cs
  where t = if c == '1' then 1 else 0

