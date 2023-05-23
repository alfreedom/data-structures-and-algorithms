package single_linked_list

import "strconv"

type Node struct {
	item *Item
	next *Node
}

type LinkedList struct {
	head *Node
}

func (list *LinkedList) String() string {
	s := "["
	aux := list.head

	for aux != nil {
		s += strconv.Itoa(aux.item.value)
		if aux.next != nil {
			s += ", "
		}
		aux = aux.next
	}
	s += "]"
	return s
}

func CreateLinkedList() (*LinkedList, error) {
	list := &LinkedList{head: nil}
	return list, nil
}

func creatNode(item *Item) (*Node, error) {
	node := &Node{
		item: item,
		next: nil,
	}
	return node, nil
}

func (list *LinkedList) Length() int {
	var length int = 0

	aux_node := list.head
	for aux_node != nil {
		length++
		aux_node = aux_node.next
	}

	return length
}

func (list *LinkedList) AddHead(item *Item) error {
	new_node, error := creatNode(item)
	new_node.next = list.head
	list.head = new_node
	return error
}

func (list *LinkedList) AddTail(item *Item) error {
	aux_node := list.head

	if aux_node == nil {
		return list.AddHead(item)
	}

	for aux_node.next != nil {
		aux_node = aux_node.next
	}

	new_node, error := creatNode(item)
	aux_node.next = new_node
	return error
}

func add_tail_recursive(node **Node, item *Item) error {
	if *node == nil {
		new_node, error := creatNode(item)
		*node = new_node
		return error
	}
	return add_tail_recursive(&(*node).next, item)
}

func (list *LinkedList) AddTailRecursive(item *Item) error {
	return add_tail_recursive(&list.head, item)
}

func (list *LinkedList) RemoveHead() *Item {
	if list.head == nil {
		return nil
	}

	removed := list.head
	list.head = removed.next
	item := removed.item
	removed = nil
	return item
}

func (list *LinkedList) RemoveTail() *Item {
	if list.head == nil {
		return nil
	}
	var removed *Node = nil

	if list.head.next == nil {
		return list.RemoveHead()
	}

	aux := list.head
	for aux.next.next != nil {
		aux = aux.next
	}

	removed = aux.next
	item := removed.item
	aux.next = nil
	removed = nil

	return item
}

func (list *LinkedList) FindItem(item *Item) *Item {
	aux_node := list.head
	for aux_node != nil {
		if aux_node.item.value == item.value {
			return aux_node.item
		}
		aux_node = aux_node.next
	}
	return nil
}

func find_item_recursive(node **Node, item *Item) *Item {
	if *node == nil {
		return nil
	}
	if (*node).item.value == item.value {
		return (*node).item
	}
	return find_item_recursive(&(*node).next, item)
}

func (list *LinkedList) FindItemRecursive(item *Item) *Item {
	return find_item_recursive(&list.head, item)
}
