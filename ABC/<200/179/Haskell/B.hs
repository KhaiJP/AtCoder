import Data.List ( group )
import Control.Monad ( replicateM )


main :: IO ()
main = do
    n <- readLn
    ds <- replicateM n $ do
            [a, b] <- map read' . words <$> getLine
            return (a == b)
    putStrLn . solve $ ds


solve :: [Bool] -> String
solve = judge . filter hasEnoughLength . filter head . group


hasEnoughLength :: [Bool] -> Bool
hasEnoughLength list = l >= 3
    where l = length list


judge :: [a] -> String
judge [] = "No"
judge _  = "Yes"


read' :: String -> Int
read' = read
