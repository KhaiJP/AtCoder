import Control.Monad ( replicateM )
import qualified Data.Set as S


main :: IO ()
main = do
    [n, k] <- readInts
    ass <- replicateM k $ do
        _ <- readInts
        readInts
    let sets = fmap S.fromList ass
    let s = foldl S.union S.empty sets
    let ans = (-) n $ S.size s
    print ans


readInts ::IO [Int]
readInts = map read . words <$> getLine
readInt :: IO Int
readInt = readLn
