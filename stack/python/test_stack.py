import pytest

from .stack import Stack
from .item import Item


@pytest.fixture
def sample_stack():
    stack = Stack()
    for i in range(5):
        stack.push(Item(i+1))
    return stack


def test_can_creat_stack():
    non_sized_stack = Stack()
    sized_stack = Stack(10)

    assert non_sized_stack is not None
    assert non_sized_stack.size == 0
    assert non_sized_stack.length == 0

    assert sized_stack is not None
    assert sized_stack.size == 10
    assert sized_stack.length == 0


def test_can_push_on_empty_stack():
    stack = Stack()
    item = Item(10)

    pushed = stack.push(item)

    assert pushed is True
    assert stack.length == 1
    assert stack.top.item.value == 10


def test_can_push_on_non_empty_stack(sample_stack):
    item = Item(10)

    pushed = sample_stack.push(item)

    assert pushed is True
    assert sample_stack.length == 6
    assert sample_stack.top.item.value == 10


def test_cannot_push_on_full_stack(sample_stack):
    sample_stack.size = 5
    item = Item(10)

    pushed = sample_stack.push(item)

    assert pushed is False
    assert sample_stack.length == 5
    assert sample_stack.top.item.value == 5


def test_can_pop_on_empty_stack():
    stack = Stack()

    popped = stack.pop()

    assert(popped is None)
    assert(stack.length == 0)


def test_can_pop_on_non_empty_stack(sample_stack):
    popped = sample_stack.pop()

    assert popped is not None
    assert popped.value == 5
    assert sample_stack.length == 4
    assert sample_stack.top.item.value == 4


def test_can_peek_on_empty_stack():
    stack = Stack()

    peeked = stack.peek()

    assert peeked is None
    assert(stack.length == 0)


def test_can_peek_on_non_empty_stack(sample_stack):
    peeked = sample_stack.peek()

    assert peeked is not None
    assert sample_stack.length == 5
    assert sample_stack.top.item.value == 5

