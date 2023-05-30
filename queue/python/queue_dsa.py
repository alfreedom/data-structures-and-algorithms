from __future__ import annotations

from typing import Optional

from item import Item

class FullQueueError(Exception):
    pass


class Node:
    def __init__(self, item: Item, next: Optional[Node] = None) -> None:
        self.item: Item = item
        self.next: Node = next


class Queue:
    def __init__(self, size: int = 0) -> None:
        self.length = 0
        self._size = size
        self._head = None
        self._tail = None

    @property
    def size(self) -> int:
        return self._size

    @property
    def head(self):
        return self._head

    @property
    def tail(self):
        return self._tail

    def enqueue(self, item: Item) -> Optional[FullQueueError]:
        """Add item at end of Queue

        Args:
            item (Item): Item to add

        Returns:
            Optional[FullQueueError]: Exception if queue is full, otherwise None
        """
        if self._size != 0 and self.length >= self.size:
            return FullQueueError("Enqueue error: Queue is full.")

        new_node = Node(item)

        if self._tail is None:
            self._head = new_node
        else:
            self._tail.next = new_node

        self._tail = new_node
        self.length += 1

        return None

    def dequeue(self) -> Optional[Item]:
        """Remove item from queue head

        Returns:
            Optional[Item]: Item if queue is not empty, otherwise None
        """
        if self._head is None:
            return None

        if self._tail == self._head:
            self._tail = None

        removed = self._head
        item = removed.item
        self._head = self._head.next
        self.length -= 1
        del(removed)

        return item

    def peek_head(self) -> Optional[Item]:
        """Peek an item from head without remove it from queue

        Returns:
            Optional[Item]: Head item if queue is not empty, otherwise None
        """
        return self._head.item if self._head else None

    def peek_tail(self) -> Optional[Item]:
        """Peek an item from tail without remove it from queue

        Returns:
            Optional[Item]: Tail item if queue is not empty, otherwise None
        """
        return self._tail.item if self._tail else None

    def clear(self) -> None:
        """Clear a queue removing all their items
        """
        while(self._head):
            item = self.dequeue()
            if item:
                del(item)