import random
import json
import os


LINE_DIV="=================================================="

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
        return {}, []
    d = {}
    with open('scoreboard.txt', 'r+') as filep:
        d = json.load(filep)

    wins = dict(sorted(d["wins"].items(), key=lambda item: item[1], reverse=True))
    diff = d["diff"]
    return wins, diff

def saveScoreBoard(wins, diff):
    score = {"wins": wins, "diff": diff}
    with open('scoreboard.txt', 'w+') as filepe:
        jsonScore = json.dump(score, filepe)

    

def main():
    print(LINE_DIV)
    wScore, dScore = loadScoreBoard()
    print(wScore, dScore)
    print(LINE_DIV)
    pName = input('Your name: ')
    mName = getMachineName()
    print(f"{pName} vs {mName}")
    pScore = 0
    mScore = 0
    while pScore < 3 and mScore < 3:
        playerV = 2# int(input("Enter a number between 0 and 9: "))
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


    diff = pScore - mScore
    if pScore == 3:
        dScore.append({pName: diff})
        winner = pName
        if pName in wScore:
            wScore[winner] += 1
        else:
            wScore[winner] = 1
    else:
        winner = mName
        diff *= -1

    print(LINE_DIV)
    print(f"{winner} won the game. Games diff:  {diff}")
    print(LINE_DIV)

    saveScoreBoard(wScore, dScore)


if __name__ == "__main__":
    main()
