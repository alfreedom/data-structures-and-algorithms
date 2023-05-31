package queue

import (
	"testing"
)

func assert_empty_tail(t testing.TB, queue *Queue) {
	t.Helper()
	if queue.head != nil {
		t.Errorf("The head of empty queue must be nil")
	}

	if queue.tail != nil {
		t.Errorf("The tail of empty queue must be nil")
	}

	if queue.length != 0 {
		t.Errorf("The length of empty queue must be 0")
	}
}

func TestCreateQueue(t *testing.T) {

	t.Run("Test can create non sized queue", func(t *testing.T) {
		queue := CreateQueue(0)

		if queue == nil {
			t.Errorf("The queue objects must not be nil")
		}

		if queue.size != 0 {
			t.Errorf("The size of non sized queue must be 0")
		}

		if queue != nil {
			assert_empty_tail(t, queue)
		}
	})

	t.Run("Test can create sized queue", func(t *testing.T) {
		expected_queue_size := 10
		queue := CreateQueue(expected_queue_size)

		if queue == nil {
			t.Errorf("The queue objects must not be nil")
		}

		if queue != nil && queue.size != expected_queue_size {
			t.Errorf("The size of non sized queue must be 0")
		}

		if queue != nil {
			assert_empty_tail(t, queue)
		}
	})
}

func TestEnqueue(t *testing.T) {

	t.Run("Test can enqueue in empty queue", func(t *testing.T) {
		queue := CreateQueue(0)

		queue.Enqueue(CreateItem(4))

		if queue.head == nil {
			t.Errorf("Queue head must not be nil")
		}

		if queue.head != queue.tail {
			t.Errorf("Queue head and tail must be the same")
		}
		if queue.length != 1 {
			t.Errorf("Queue length after enqueue must be 1")
		}
		if queue.head.item.value != 4 {
			t.Errorf("Queue inserted value must be 4, got %d", queue.head.item.value)
		}
	})

	t.Run("Test can enqueue in non empty queue", func(t *testing.T) {
		queue := CreateQueue(0)

		queue.Enqueue(CreateItem(4))
		queue.Enqueue(CreateItem(5))
		queue.Enqueue(CreateItem(6))

		if queue.head == nil {
			t.Errorf("Queue head must not be nil")
		}

		if queue.head == queue.tail {
			t.Errorf("Queue head and tail must be different")
		}

		if queue.length != 3 {
			t.Errorf("Queue length after enqueue must be 3")
		}
		if queue.tail.item.value != 6 {
			t.Errorf("Queue inserted value must be 6, got %d", queue.tail.item.value)
		}
	})

	t.Run("Test cannot enqueue in non full queue", func(t *testing.T) {
		queue := CreateQueue(4)

		queue.Enqueue(CreateItem(4))
		queue.Enqueue(CreateItem(5))
		queue.Enqueue(CreateItem(6))
		queue.Enqueue(CreateItem(7)) // queue full
		queue.Enqueue(CreateItem(8)) // not inserted
		queue.Enqueue(CreateItem(9)) // not inserted

		if queue.head == nil {
			t.Errorf("Queue head must not be nil")
		}

		if queue.length != 4 {
			t.Errorf("Queue length after enqueue must be 1")
		}

		if queue.head == queue.tail {
			t.Errorf("Queue head and tail must be different")
		}

		if queue.tail.item.value != 7 {
			t.Errorf("Queue inserted value must be 7, got %d", queue.tail.item.value)
		}
	})
}

func TestDequeue(t *testing.T) {

	t.Run("Test can dequeue on empty queue", func(t *testing.T) {
		queue := CreateQueue(0)

		dequeued := queue.Dequeue()

		if dequeued != nil {
			t.Errorf("Dequeued element from an empty string must be nil")
		}

		if queue != nil {
			assert_empty_tail(t, queue)
		}
	})

	t.Run("Test can dequeue on non empty queue", func(t *testing.T) {
		queue := CreateQueue(0)
		queue.Enqueue(CreateItem(10))
		queue.Enqueue(CreateItem(15))
		queue.Enqueue(CreateItem(20))

		dequeued := queue.Dequeue()

		if dequeued == nil {
			t.Errorf("Dequeued element from an empty string must not be nil")
		}

		if queue.length != 2 {
			t.Errorf("Queue lenght must be 2, got %d", queue.length)
		}
		if dequeued != nil && dequeued.value != 10 {
			t.Errorf("Dequeued value must be %d, got %d", 10, dequeued.value)
		}
	})

	t.Run("Test can dequeue all items", func(t *testing.T) {
		queue := CreateQueue(0)
		values := []int{1, 2, 3, 4, 5, 6, 7}

		// Enqueue values
		for _, v := range values {
			queue.Enqueue(CreateItem(v))
		}

		// Dequeue values and validate
		for ix, v := range values {
			dequeued := queue.Dequeue()

			expected_len := len(values) - (ix + 1)

			if dequeued.value != v {
				t.Errorf("Dequeued value must be %d, got %d", v, dequeued.value)
			}

			if queue.length != expected_len {
				t.Errorf("Lenght after dequeue must be %d, got %d", expected_len, queue.length)
			}
		}

		if queue != nil {
			assert_empty_tail(t, queue)
		}

	})
}

func TestPeek(t *testing.T) {

	t.Run("Test can peek at head on empty queue", func(t *testing.T) {
		queue := CreateQueue(0)

		peeked := queue.PeekHead()

		if peeked != nil {
			t.Errorf("Peeked element on empty list must be nil")
		}
	})

	t.Run("Test can peek at tail on empty queue", func(t *testing.T) {
		queue := CreateQueue(0)

		peeked := queue.PeekTail()

		if peeked != nil {
			t.Errorf("Peeked element on empty list must be nil")
		}
	})

	t.Run("Test can peek at head on non empty queue", func(t *testing.T) {
		queue := CreateQueue(0)
		queue.Enqueue(CreateItem(55))
		queue.Enqueue(CreateItem(10))
		queue.Enqueue(CreateItem(30))
		queue.Enqueue(CreateItem(40))

		expected_length := queue.length

		peeked := queue.PeekHead()

		if peeked == nil {
			t.Errorf("Peeked element must not be nil")
		}

		if queue.length != expected_length {
			t.Errorf("Queue length must not be changed on peek item, must be %d, got %d", expected_length, queue.length)
		}

		if peeked.value != 55 {
			t.Errorf("Peekede value must be %d, got %d", 55, peeked.value)
		}
	})

	t.Run("Test can peek at tail on non empty queue", func(t *testing.T) {
		queue := CreateQueue(0)
		queue.Enqueue(CreateItem(55))
		queue.Enqueue(CreateItem(10))
		queue.Enqueue(CreateItem(30))
		queue.Enqueue(CreateItem(40))

		expected_length := queue.length

		peeked := queue.PeekTail()

		if peeked == nil {
			t.Errorf("Peeked element must not be nil")
		}

		if queue.length != expected_length {
			t.Errorf("Queue length must not be changed on peek item, must be %d, got %d", expected_length, queue.length)
		}

		if peeked.value != 40 {
			t.Errorf("Peekede value must be %d, got %d", 55, peeked.value)
		}
	})
}

func TestClearQueue(t *testing.T) {

	t.Run("Test can clear empty queue", func(t *testing.T) {
		queue := CreateQueue(0)

		queue.Clear()

		if queue != nil {
			assert_empty_tail(t, queue)
		}
	})

	t.Run("Test can clear non empty queue", func(t *testing.T) {
		queue := CreateQueue(0)
		queue.Enqueue(CreateItem(10))
		queue.Enqueue(CreateItem(45))
		queue.Enqueue(CreateItem(54))
		queue.Enqueue(CreateItem(71))

		queue.Clear()

		if queue != nil {
			assert_empty_tail(t, queue)
		}
	})
}
