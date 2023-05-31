import pytest

from queue_dsa import Node, Queue, FullQueueError
from item import Item


def assert_empty_queue(queue: Queue):
    assert queue.length == 0
    assert queue.head is None
    assert queue.tail is None


def test_can_create_queue_node():
    node = Node(Item(10))

    assert node.item.value == 10
    assert node.next == None


def test_can_create_non_sized_queue():
    queue = Queue()

    assert queue.size == 0
    assert_empty_queue(queue)


def test_can_create_sized_queue():
    queue = Queue(5)

    assert queue.size == 5
    assert_empty_queue(queue)


def test_can_enqueue_on_empty_queue():
    queue = Queue()

    error = queue.enqueue(Item(25))

    assert error is None
    assert queue.length == 1
    assert queue.tail == queue.tail
    assert queue.tail.item.value == 25
    assert queue.head.item.value == 25

def test_can_enqueue_in_non_empty_queue():
    queue = Queue()

    queue.enqueue(Item(25))
    queue.enqueue(Item(35))
    queue.enqueue(Item(45))
    error = queue.enqueue(Item(55))

    assert error is None
    assert queue.length == 4
    assert queue.head.item.value == 25
    assert queue.head.next.item.value == 35
    assert queue.head.next.next.item.value == 45
    assert queue.head.next.next.next.item.value == 55
    assert queue.tail.item.value == 55


def test_cannot_enqueue_on_full_queue():
    queue = Queue(4)

    queue.enqueue(Item(11))
    queue.enqueue(Item(22))
    queue.enqueue(Item(33))
    queue.enqueue(Item(44))

    error = queue.enqueue(Item(55))

    assert error is not None
    assert type(error) == FullQueueError
    assert queue.length == 4
    assert queue.tail.item.value == 44


def test_can_dequeue_on_empty_queue():
    queue = Queue()

    dequeued = queue.dequeue()

    assert dequeued is None
    assert_empty_queue(queue)


def test_can_dequeue_on_non_empty_list():
    queue = Queue()
    queue.enqueue(Item(11))
    queue.enqueue(Item(22))
    queue.enqueue(Item(33))

    dequeued = queue.dequeue()

    assert dequeued is not None
    assert queue.length == 2
    assert dequeued.value == 11
    assert queue.head.item.value == 22
    assert queue.tail.item.value == 33


def test_can_peek_at_head_on_empty_queue():
    queue = Queue()

    peeked = queue.peek_head()

    assert peeked is None
    assert_empty_queue(queue)


def test_can_peek_at_tail_on_empty_queue():
    queue = Queue()

    peeked = queue.peek_tail()

    assert peeked is None
    assert_empty_queue(queue)


def test_can_peek_at_head_on_non_empty_queue():
    queue = Queue()
    queue.enqueue(Item(11))
    queue.enqueue(Item(22))
    queue.enqueue(Item(33))
    queue.enqueue(Item(44))

    peeked = queue.peek_head()

    assert peeked is not None
    assert peeked.value == 11
    assert queue.length == 4
    assert queue.head.item.value == 11
    assert queue.tail.item.value == 44


def test_can_peek_at_tail_on_non_empty_queue():
    queue = Queue()
    queue.enqueue(Item(11))
    queue.enqueue(Item(22))
    queue.enqueue(Item(33))
    queue.enqueue(Item(44))

    peeked = queue.peek_tail()

    assert peeked is not None
    assert peeked.value == 44
    assert queue.length == 4
    assert queue.head.item.value == 11
    assert queue.tail.item.value == 44


def test_can_clear_empty_queue():
    queue = Queue()

    queue.clear()

    assert_empty_queue(queue)


def test_can_clear_non_empty_queue():
    queue = Queue()
    queue.enqueue(Item(11))
    queue.enqueue(Item(22))
    queue.enqueue(Item(33))
    queue.enqueue(Item(44))

    queue.clear()

    assert_empty_queue(queue)