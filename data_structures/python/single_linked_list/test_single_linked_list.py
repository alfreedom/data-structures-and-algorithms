import pytest

from single_linked_list import Node, LinkedList
from item import Item


@pytest.fixture
def sample_list():
    linked_list = LinkedList()
    for v in range(1, 6):
        linked_list.AddTail(Item(v))
    return linked_list

def test_can_create_node():
    item = Item(10)
    node = Node(item)

    assert node is not None
    assert node.item.value == item.value


def test_can_create_list():
    linked_list = LinkedList()

    assert linked_list is not None
    assert linked_list.head is None
    assert linked_list.tail is None


def test_can_get_list_length():
    values = [1, 2, 3, 4, 5]
    linked_list = LinkedList()
    for v in values:
        linked_list.AddTail(Item(v))

    assert len(linked_list) == len(values)


def test_can_add_to_head_in_empty_list():
    linked_list = LinkedList()
    item = Item(10)

    linked_list.AddHead(item)

    assert linked_list.head is not None
    assert linked_list.head.item.value == item.value


def test_can_add_to_head_in_non_empty_list(sample_list):
    new_item = Item(100)
    old_list_len = len(sample_list)
    sample_list.AddHead(new_item)

    assert sample_list.head.item.value == new_item.value
    assert len(sample_list) == old_list_len + 1


def test_can_add_to_tail_in_empty_list():
    linked_list = LinkedList()
    item = Item(100)
    linked_list.AddTail(item)

    assert linked_list.head is not None
    assert linked_list.head.item.value == item.value


def test_can_add_to_tail_in_non_empty_list(sample_list):
    new_item = Item(100)

    sample_list.AddTail(new_item)

    assert sample_list.tail.item.value == new_item.value


def test_can_add_to_tail_in_empty_list_recursively():
    linked_list = LinkedList()
    item = Item(100)

    linked_list.AddTailRecursive(item)

    assert linked_list.head is not None
    assert linked_list.head.item.value == item.value


def test_can_add_to_tail_in_non_empty_list_recursively(sample_list):
    new_item = Item(100)

    sample_list.AddTailRecursive(new_item)

    assert sample_list.tail.item.value == new_item.value


def test_can_remove_head_from_empty_list():
    linked_list = LinkedList()

    removed = linked_list.RemoveHead()

    assert removed is None
    assert len(linked_list) == 0


def test_can_remove_head_from_non_empty_list(sample_list):
    head_item = sample_list.head.item
    old_list_len = len(sample_list)

    removed = sample_list.RemoveHead()

    assert removed is not None
    assert removed.value == head_item.value
    assert len(sample_list) == old_list_len - 1


def test_can_remove_tail_from_empty_list():
    linked_list = LinkedList()

    removed = linked_list.RemoveTail()

    assert removed is None
    assert len(linked_list) == 0


def test_can_remove_tail_from_non_empty_list(sample_list):
    tail_item = sample_list.tail.item
    old_list_len = len(sample_list)

    removed = sample_list.RemoveTail()

    assert removed is not None
    assert removed.value == tail_item.value
    assert len(sample_list) == old_list_len - 1


def test_can_remove_tail_from_list_with_one_element():
    linked_list = LinkedList()
    linked_list.AddHead(Item(50))
    tail_item = linked_list.tail.item
    old_list_len = len(linked_list)

    removed = linked_list.RemoveTail()

    assert removed is not None
    assert linked_list.head is None
    assert removed.value == tail_item.value
    assert len(linked_list) == old_list_len - 1


def test_can_find_item_in_empty_list():
    list = LinkedList()
    item_to_find = Item(4)

    item_found = list.FindItem(item_to_find)

    assert item_found is None


def test_can_find_item_in_non_empty_list(sample_list):
    item_to_find = Item(2)

    item_found = sample_list.FindItem(item_to_find)

    assert item_found is not None
    assert item_found.value == item_to_find.value


def test_can_find_non_existent_item_in_non_empty_list(sample_list):
    item_to_find = Item(50)

    item_found = sample_list.FindItem(item_to_find)

    assert item_found is None


def test_can_find_item_recursively_in_empty_list():
    linked_list = LinkedList()
    item_to_find = Item(2)

    item_found = linked_list.FindItemRecursive(item_to_find)

    assert item_found is None


def test_can_find_item_recursively_in_non_empty_list(sample_list):
    item_to_find = Item(2)

    item_found = sample_list.FindItemRecursive(item_to_find)

    assert item_found is not None
    assert item_found.value == item_to_find.value


def test_can_find_non_existent_item_recursively_in_empty_list():
    linked_list = LinkedList()
    item_to_find = Item(50)

    item_found = linked_list.FindItemRecursive(item_to_find)

    assert item_found is None