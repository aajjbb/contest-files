parseInts :: String -> [Int]
parseInts str = map read (words str)

willPresent :: Int -> String
willPresent presentationDay
 | presentationDay < 24 = "TCC Apresentado!"
 | otherwise = "Fail! Entao eh nataaaaal!"

run :: Int -> Int -> String
run deliverDay deadline
  | deliverDay > deadline = "Eu odeio a professora!"
  | deadline - deliverDay >= 3 = "Muito bem! Apresenta antes do Natal!"
  | otherwise = "Parece o trabalho do meu filho!\n" ++ willPresent (deliverDay + 2)

main :: IO()
main = do
  line <- getLine
  let tokens = parseInts line
  let fs = tokens !! 0
  let sn = tokens !! 1
  putStrLn $ run fs sn
