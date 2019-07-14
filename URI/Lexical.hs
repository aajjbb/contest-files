main :: IO()
main = do
  s1 <- getLine
  s2 <- getLine

  putStrLn $ min s1 s2
  putStrLn $ max s1 s2
