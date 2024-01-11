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
    if not os.path.exists('scoreboard.txt'):
        return {}, []
    d = {}
    with open('scoreboard.txt', 'r+') as filep:
        d = json.load(filep)

    return d["wins"], d["diff"]

def saveScoreBoard(wins, diff):
    __MAX_SIZE_SCOREBOARD = 10
    # order the dict before save
    wins = dict(sorted(wins.items(), key=lambda item: item[1], reverse=True))
    wins = dict(list(wins.items())[:__MAX_SIZE_SCOREBOARD])
    diff.sort(key=lambda item: item[list(item)[0]], reverse=True)
    diff = diff[:__MAX_SIZE_SCOREBOARD]
    score = {"wins": wins, "diff": diff}
    with open('scoreboard.txt', 'w+') as filep:
        jsonScore = json.dump(score, filep)

def printScoreboard(wins, diff):
    print(LINE_DIV)
    print("                   Scoreboard")
    print(LINE_DIV)
    print("                     Winners")
    print(LINE_DIV)
    print("Name\t\t\tScore")
    print(LINE_DIV)
    for item in wins:
        print(f"{item}\t\t\t{wins[item]}")

    print(LINE_DIV)
    print("           Bigger diff between opponent")
    print(LINE_DIV)
    print("Name\t\t\tDiff")
    print(LINE_DIV)
    for item in diff:
        key = list(item)[0]
        print(f"{key}\t\t\t{item[key]}")
    print(LINE_DIV)

def main():
    wScore, dScore = loadScoreBoard()
    printScoreboard(wScore, dScore)
    print(LINE_DIV)
    pName = input('Enter your name: ')
    mName = getMachineName()
    print(f"{pName} vs {mName}")
    pScore = 0
    mScore = 0
    round = 0
    __DIFF_TO_WIN = 10
    while pScore < __DIFF_TO_WIN and mScore < __DIFF_TO_WIN:
        print(LINE_DIV)
        choice = input("Choose between Odd and Even: ")
        playerV = int(input("Enter a number between 0 and 9: "))
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
    if pScore == __DIFF_TO_WIN:
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
