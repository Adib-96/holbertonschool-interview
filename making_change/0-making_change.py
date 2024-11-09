#!/usr/bin/python3
def makeChange(coins, total):
    """
    Determines the fewest number of coins needed to meet a given total amount.

    Args:
        coins (list): A list of the values of coins in your possession.
        total (int): The total amount to reach using the fewest coins possible.

    Returns:
        int: The minimum number of coins needed to make the total amount, or -1 if it is not possible.
    """
    if total <= 0:
        return 0

    # Sort the coins in descending order to try larger denominations first
    coins.sort(reverse=True)

    coin_count = 0
    for coin in coins:
        if total <= 0:
            break
        # Use as many of this coin as possible
        coin_count += total // coin
        total %= coin

    # If total is not zero, it means it's not possible to make up the amount
    # with the given coins
    return coin_count if total == 0 else -1
