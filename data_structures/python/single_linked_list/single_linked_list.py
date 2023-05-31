from __future__ import annotations
from typing import Optional

from item import Item


class Node:
    item: Item
    next: Node

    def __init__(self, item: Item) -> None:
        self.item = item
        self.next = None


class LinkedList:
    def __init__(self) -> None:
        """Initialize the linked list with an empty head
        """
        self._head = None

    def __len__(self) -> int:
        """Calculate the lenght of the list walking to the end and counting
        items

        Returns:
            int -- List lenght
        """

        aux_node = self._head
        counter = 0
        while aux_node is not None:
            aux_node = aux_node.next
            counter += 1
        return counter

    @property
    def tail(self) -> Optional[Node]:
        """Get the Tail node of the list walking to the last item.

        Returns:
            Optional[Node] -- The tail node if non empty list, otherwise None
        """

        if self._head is None:
            return None

        aux_node = self._head
        while aux_node.next is not None:
            aux_node = aux_node.next

        return aux_node

    @property
    def head(self) -> Optional[Node]:
        """Return the list Head node.

        Returns:
            Optional[Node] -- List head node if non empty list, otherwise Nonde
        """
        return self._head

    def AddHead(self, item: Item) -> None:
        """Add item list Head.

        Arguments:
            item {Item} -- Item to add.
        """

        new_node = Node(item)
        new_node.next = self._head
        self._head = new_node

    def AddTail(self, item: Item) -> None:
        """Add item to list Tail.

        Arguments:
            item {Item} -- Item to add
        """

        if self._head is None:
            self.AddHead(item)
        else:
            new_node = Node(item)
            aux_node = self._head

            while aux_node.next is not None:
                aux_node = aux_node.next

            aux_node.next = new_node

    def AddTailRecursive(self, item: Item) -> None:
        """Add item to list Head using recurive function.

        Arguments:
            item {Item} -- Item to add
        """

        if self._head is None:
            self.AddHead(item)
        else:
            def _add_tail_recursive(node: Node, item: Item) -> None:
                if node.next is None:
                    node.next = Node(item)
                else:
                    _add_tail_recursive(node.next, item)

            _add_tail_recursive(self._head, item)

    def RemoveHead(self) -> Optional[Item]:
        """Remove the Head item.

        Returns:
            Optional[Item] -- Head item if non empty list, otherwise None
        """

        if self._head is None:
            return None

        removed = self._head
        self._head = self._head.next

        item = removed.item
        del(removed)
        return item

    def RemoveTail(self) -> Optional[Item]:
        """Remove the Tail item.

        Returns:
            Optional[Item] -- Tail item if non empty list, otherwise None
        """

        if self._head is None:
            return None

        if self._head.next is None:
            return self.RemoveHead();
        else:
            aux_node = self._head
            while aux_node.next.next is not None:
                aux_node = aux_node.next
            removed = aux_node.next
            aux_node.next = None

        item = removed.item
        del(removed)

        return item

    def FindItem(self, item: Item) -> Optional[Item]:
        """Find a list item.

        Arguments:
            item {Item} -- Item to find

        Returns:
            Optional[Item] -- Finded item if item exists, otherwise None
        """

        aux_node = self._head
        while aux_node is not None:
            if aux_node.item == item:
                return aux_node.item
            aux_node = aux_node.next

        return None


    def FindItemRecursive(self, item: Item) -> Optional[Item]:
        """Find a list item using recursive function

        Arguments:
            item {Item} -- Item to find

        Returns:
            Optional[Item] -- Found item if exists, otherwise None
        """

        def _find_item_recursive( node: Node, item: Item) -> Optional[Item]:
            if node is None:
                return None

            if node.item == item:
                return node.item

            return _find_item_recursive(node.next, item)

        item_found = _find_item_recursive(self._head, item)
        return item_found