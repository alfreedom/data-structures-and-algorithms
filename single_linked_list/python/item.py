from __future__ import annotations


class Item:
    value: int

    def __init__(self, value: int) -> None:
        self.value = value

    def __eq__(self, __other_item: Item) -> bool:
        return self.value == __other_item.value