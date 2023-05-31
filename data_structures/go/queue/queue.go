package queue

type Node struct {
	Item *Item
	Next *Node
}

type Queue struct {
	Head   *Node
	Tail   *Node
	Size   int
	Length int
}

func CreateNode(item *Item) *Node {
	return &Node{Item: item, Next: nil}
}

func CreateQueue(size int) *Queue {
	return &Queue{Head: nil, Tail: nil, Size: size, Length: 0}
}

func (queue *Queue) Enqueue(item *Item) {
	if queue.Size == 0 || queue.Length < queue.Size {
		new_node := CreateNode(item)

		if queue.Tail == nil {
			queue.Head = new_node
		} else {
			queue.Tail.Next = new_node
		}
		queue.Tail = new_node
		queue.Length++
	}
}

func (queue *Queue) Dequeue() *Item {
	if queue.Tail == nil {
		return nil
	}

	if queue.Tail == queue.Head {
		queue.Tail = nil
	}

	removed_node := queue.Head
	queue.Head = queue.Head.Next
	queue.Length--

	return removed_node.Item
}

func (queue *Queue) PeekHead() *Item {
	if queue.Head != nil {
		return queue.Head.Item
	}
	return nil
}

func (queue *Queue) PeekTail() *Item {
	if queue.Tail != nil {
		return queue.Tail.Item
	}
	return nil
}

func (queue *Queue) Clear() {
	for queue.Head != nil {
		queue.Head = queue.Head.Next
	}
	queue.Length = 0
	queue.Tail = nil
}
