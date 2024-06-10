import Control.Monad
import Data.Maybe ( isJust )


main :: IO ()
main = do
    [n, m, t] <- getInts
    abS' <- replicateM m $ (\[a, b] -> (a, b)) <$> getInts
    let abS = abS' ++ [(t, t)]
    let goodBattery = goodBattery' n
    let result = foldl (\mState inOut -> mState >>= goodBattery inOut) (return (n, 0)) abS
    putStrLn $ if isJust result then "Yes" else "No"


goodBattery' :: Int -> (Int, Int) -> (Int, Int) -> Maybe (Int, Int)
goodBattery' maxVolume (shopIn, shopOut) (battery, now)
    | battery' <= 0 = Nothing
    | otherwise     = Just (battery'', shopOut)
    where
        battery'  = battery - (shopIn - now)
        battery'' = min maxVolume $ battery' + (shopOut - shopIn)


getInts :: IO [Int]
getInts = map read . words <$> getLine
