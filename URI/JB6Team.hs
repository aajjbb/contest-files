import System.IO

isWinner :: String -> String -> Bool

isWinner playerOne playerTwo
  | playerOne == "papel" && playerTwo == "pedra" = True
  | playerOne == "pedra" && playerTwo == "tesoura" = True
  | playerOne == "tesoura" && playerTwo == "papel" = True
  | otherwise = False

printWinner :: String -> String -> String -> String
printWinner dodo leo pepper
  | isWinner dodo leo && isWinner dodo pepper = "Os atributos dos monstros vao ser inteligencia, sabedoria..."
  | isWinner leo dodo && isWinner leo pepper = "Iron Maiden's gonna get you, no matter how far!"
  | isWinner pepper dodo && isWinner pepper leo = "Urano perdeu algo muito precioso..."
  | otherwise = "Putz vei, o Leo ta demorando muito pra jogar..."

run :: String -> IO()
run line = do
  let tokens = words line
  let dodo = tokens !! 0
  let leo = tokens !! 1
  let pepper = tokens !! 2

  putStrLn $ printWinner dodo leo pepper

main :: IO()
main = myLoop

myLoop :: IO()
myLoop = do done <- isEOF
            if done
              then putStr ""
              else do inp <- getLine
                      run inp
                      myLoop
