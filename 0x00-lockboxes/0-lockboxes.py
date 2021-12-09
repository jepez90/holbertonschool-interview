#!/usr/bin/python3

""" You have n number of locked boxes in front of you. Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other boxes.

Write a method that determines if all the boxes can be opened.

    Prototype: def canUnlockAll(boxes)
    boxes is a list of lists
    A key with the same number as a box opens that box
    You can assume all keys will be positive integers
        There can be keys that do not have boxes
    The first box boxes[0] is unlocked
    Return True if all boxes can be opened, else return False

"""


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened. """
    # creates an list with the same length of boxes and initialized in False
    boxesAlreadyOpened = [False]*len(boxes)

    # opens the first box and it open all the next recursively
    openBox(0, boxes,  boxesAlreadyOpened)

    # if False is in the boxesAlreadyOpened list, not all boxes was opened
    try:
        boxesAlreadyOpened.index(False)
        return False
    except ValueError:
        # False is not in the boxesAlreadyOpened list, all boxes was opened
        return True


def openBox(boxNumber, boxes, boxesAlreadyOpened):
    """ recusrsive function to open the boxs with each key and store in
    boxesAlreadyOpened true when the box is open
    """
    # if the box already was opened, don't anything,
    # otherwise open the box and call itself with each key in the current box
    if not boxesAlreadyOpened[boxNumber]:
        boxesAlreadyOpened[boxNumber] = True
        for key in boxes[boxNumber]:
            openBox(key, boxes, boxesAlreadyOpened)
