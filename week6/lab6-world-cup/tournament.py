""" Simulate a sports tournament """

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():


    """ Ensure correct usage """
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    """ Read teams into memory from file """
    teams = []
    # get input filename from cmd line
    filename = sys.argv[1]
    # open file as csv reader object
    with open(filename, "r") as file:
        reader = csv.DictReader(file)
        # append dict for each team into teams array
        for row in reader:
            row['rating'] = int(row['rating'])
            teams.append(row)
    
    """ Simulate N tournaments and keep track of win counts """
    counts = {}
    for i in range(N):
        res = simulate_tournament(teams)
        if res in counts:
            counts[res] += 1
        else:
            counts[res] = 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")

"""Simulate a game. Return True if team1 wins, False otherwise."""
def simulate_game(team1, team2):
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability

"""Simulate a round. Return a list of winning teams."""
def simulate_round(teams):
    winners = []
    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])
    return winners

"""Simulate a tournament. Return name of winning team."""
def simulate_tournament(teams):
    round_res = simulate_round(teams)
    while len(round_res) > 1:
        round_res = simulate_round(round_res)
    return round_res[0]['team']


if __name__ == "__main__":
    main()
