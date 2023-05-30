from __future__ import annotations
from typing import Optional

from item import Item


class Node:
    """Stack node class"""
    item: Item
    next: Node

    def __init__(self, item: Item) -> None:
        self.item = item
        self.next = None


class Stack:
    """Stack class"""
    top: Node
    length: int
    size: int

    def __init__(self, size: int = 0) -> None:
        self.top = None
        self.size = size
        self.length = 0

    def push(self, item: Item) -> bool:
        """Push an item into stack

        Arguments:
            item {Item} -- Item to push

        Returns:
            bool -- True if pushed, otherwise False
        """
        if self.size == 0 or self.length < self.size:
            new_node = Node(item)
            new_node.next = self.top
            self.top = new_node
            self.length += 1
            return True

        return False

    def pop(self) -> Optional[Item]:
        """Pop an item from stack

        Returns:
            Optional[Item] -- Item if non empty stack, otherwise None
        """
        item = None
        if self.top:
            removed = self.top
            self.top = removed.next
            item = removed.item
            self.length -= 1
            del(removed)

        return item

    def peek(self) -> Optional[Item]:
        """Peek an item without removing from stack

        Returns:
            Optional[Item] -- Item if non empty stack, otherwise None
        """
        return self.top.item if self.top else None

