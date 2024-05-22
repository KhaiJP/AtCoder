main = do
  a :: Int <- readLn
  b :: Int <- readLn
  c :: Int <- readLn
  x :: Int <- readLn
  print . length $ [0 | na <- [0..a], nb <- [0..b], nc <- [0..c], 500*na + 100*nb + 50*nc == x]

