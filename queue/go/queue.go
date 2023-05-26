package queue

type Node struct {
	item *Item
	next *Node
}

type Queue struct {
	head   *Node
	tail   *Node
	size   int
	length int
}

func CreateNode(item *Item) *Node {
	return &Node{item: item, next: nil}
}

func CreateQueue(size int) *Queue {
	return &Queue{head: nil, tail: nil, size: size, length: 0}
}

func (queue *Queue) Enqueue(item *Item) {
	if queue.size == 0 || queue.length < queue.size {
		new_node := CreateNode(item)

		if queue.tail == nil {
			queue.head = new_node
		} else {
			queue.tail.next = new_node
		}
		queue.tail = new_node
		queue.length++
	}
}

func (queue *Queue) Dequeue() *Item {
	if queue.tail == nil {
		return nil
	}

	if queue.tail == queue.head {
		queue.tail = nil
	}

	removed_node := queue.head
	queue.head = queue.head.next
	queue.length--

	return removed_node.item
}

func (queue *Queue) PeekHead() *Item {
	if queue.head != nil {
		return queue.head.item
	}
	return nil
}

func (queue *Queue) PeekTail() *Item {
	if queue.tail != nil {
		return queue.tail.item
	}
	return nil
}

func (queue *Queue) Clear() {
	for queue.head != nil {
		queue.head = queue.head.next
	}
	queue.length = 0
	queue.tail = nil
}
