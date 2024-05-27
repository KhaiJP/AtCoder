main :: IO ()
main = do
    x <- getLine
    putStrLn $ if isChoku x then "YES" else "NO"


isChoku :: String -> Bool
isChoku [] = True
isChoku ('c':'h':rest) = isChoku rest
isChoku ('o':rest)     = isChoku rest
isChoku ('k':rest)     = isChoku rest
isChoku ('u':rest)     = isChoku rest
isChoku _              = False
