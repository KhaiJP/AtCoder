import Data.List ( sort, group )
import Control.Monad


main = do
  n  <- readLn
  ds <- replicateM n readLn
  print . length . group . sort $ (ds :: [Int])

