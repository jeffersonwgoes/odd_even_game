import random
import json
import os

def getRandomNumber():
    random.seed()
    return random.randrange(10)

def oddEven(number):
    if number%2 == 0:
        return "Even"

    return "Odd"

def getMachineName():
    return "John Doe"

def loadScoreBoard():
    print("ScoreBoard")
    if not os.path.exists('scoreboard.txt'):
        return {}
    
    with open('scoreboard.txt', 'r+') as filep:
        return json.load(filep)

def saveScoreBoard(scoreboard):
    with open('scoreboard.txt', 'w+') as score:
        jsonScore = json.dump(scoreboard, score)

    

def main():
    scoreboard = loadScoreBoard()
    print(scoreboard)
    pName = 'Jeff' #input('Your name: ')
    mName = getMachineName()
    print(f"{pName} vs {mName}")
    pScore = 0
    mScore = 0
    while pScore < 3 and mScore < 3:
        playerV = 2#int(input("Enter a number between 0 and 9: "))
        choice = 'Even'#input("Choose between Odd and Even: ")
        machineV = getRandomNumber()
        sum = machineV + playerV
        result = oddEven(sum)
        print(f"You: {playerV} Machine: {machineV} Sum: {sum}")
        print(f"Result: {result}")
        if choice == result:
            print(f"Player {pName} won the round")
            pScore += 1
        else:
            print(f"Machine {mName} won the round")
            mScore += 1

        print(f"Overallscore: {pName}: {pScore} {mName}: {mScore}")



    if pScore == 3:
        winner = pName
    else:
        winner = mName

    print(f"{winner} won the game")

    if winner in scoreboard:
        scoreboard[winner] += 1
    else:
        scoreboard[winner] = 1

    saveScoreBoard(scoreboard)


if __name__ == "__main__":
    main()