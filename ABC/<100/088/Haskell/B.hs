import Data.List ( sort )


main = do
  _ <- getLine
  ax <- map read . words <$> getLine
  let rSorted = reverse . sort $ ax
  let distributed = zipWith (*) rSorted $ cycle [1, -1]
  print . sum $ distributed

