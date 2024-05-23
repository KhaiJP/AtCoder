import qualified Data.Map.Strict as M
type Map = M.Map Int Int


main = do
    _ <- getLine
    as <- map read . words <$> getLine
    let m  = foldl triDivision M.empty as
    let tp = mapMaxValue m
    print . fst $ tp


triDivision :: Map -> Int -> Map
triDivision m n = triDivision' m n 2


triDivision' :: Map -> Int -> Int -> Map
triDivision' m n k
    | k == (n + 1)   = m
    | n `mod` k == 0 = triDivision' m' n (k+1)
    | otherwise      = triDivision' m  n (k+1)
    where m' = if M.member k m
                then M.update (\x -> Just (x+1)) k m
                else M.insert k 1 m


mapMaxValue :: Map -> (Int, Int)
mapMaxValue = maxValue (0, 0) . M.toList


maxValue :: (Int, Int) -> [(Int, Int)] -> (Int, Int)
maxValue tp [] = tp
maxValue (rk, rv) ((nk, nv):rest)
    | rv <= nv  = maxValue (nk, nv) rest
    | otherwise = maxValue (rk, rv) rest

