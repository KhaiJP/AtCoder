main = do
  s <- reverse <$> getLine
  putStrLn . check $ s


check :: String -> String
check [] = "YES"
check ('m':'a':'e':'r':'d':rest)         = check rest
check ('e':'s':'a':'r':'e':rest)         = check rest
check ('r':'e':'m':'a':'e':'r':'d':rest) = check rest
check ('r':'e':'s':'a':'r':'e':rest)     = check rest
check _ = "NO"

