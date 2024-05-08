def canUnlockAll(boxes):
    # Initial set of unlocked boxes starting with the first box
    unlocked = set([0])
    # Set of keys collected from the boxes
    keys = set(boxes[0])

    # Keep checking until no new keys are added
    while keys:
        # Get a key to check
        current_key = keys.pop()

        # If the key is for a box that hasn't been unlocked
        if current_key < len(boxes) and current_key not in unlocked:
            # Unlock the box
            unlocked.add(current_key)
            # Add keys from this box to our keys set
            keys.update(boxes[current_key])

    # If we've unlocked all the boxes
    return len(unlocked) == len(boxes)

# Test the function with sample data
boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))  # Output: True

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))