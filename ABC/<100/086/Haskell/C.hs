import Control.Monad ( replicateM )
type Time  = Int
type Event = (Time, Int, Int)


main :: IO ()
main = do
    n <- readLn
    events <- map ((\[a,b,c] -> (a,b,c)) . map read . words) <$> replicateM n getLine
    let hasAchieved = myFoldl canTravel (0, 0, 0) events
    putStrLn $ if hasAchieved then "Yes" else "No"


canTravel :: Event -> Event -> Bool
canTravel (t0, x0, y0) (t1, x1, y1)
    | span < dist = False
    | otherwise   = even (span - dist)
    where
        dist = abs (x1 - x0) + abs (y1-y0)
        span = t1 - t0


myFoldl :: (a -> a -> Bool) -> a -> [a] -> Bool
myFoldl _ _ [] = True
myFoldl f x (y:ys)
    | successed = myFoldl f y ys
    | otherwise = False
    where successed = f x y
