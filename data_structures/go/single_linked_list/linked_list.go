package single_linked_list

import "strconv"

type Node struct {
	Item *Item
	Next *Node
}

type LinkedList struct {
	Head *Node
}

func (list *LinkedList) String() string {
	s := "["
	aux := list.Head

	for aux != nil {
		s += strconv.Itoa(aux.Item.Value)
		if aux.Next != nil {
			s += ", "
		}
		aux = aux.Next
	}
	s += "]"
	return s
}

func CreateLinkedList() (*LinkedList, error) {
	list := &LinkedList{Head: nil}
	return list, nil
}

func createNode(item *Item) (*Node, error) {
	node := &Node{
		Item: item,
		Next: nil,
	}
	return node, nil
}

func (list *LinkedList) Length() int {
	var length int = 0

	aux_node := list.Head
	for aux_node != nil {
		length++
		aux_node = aux_node.Next
	}

	return length
}

func (list *LinkedList) AddHead(item *Item) error {
	new_node, error := createNode(item)
	new_node.Next = list.Head
	list.Head = new_node
	return error
}

func (list *LinkedList) AddTail(item *Item) error {
	aux_node := list.Head

	if aux_node == nil {
		return list.AddHead(item)
	}

	for aux_node.Next != nil {
		aux_node = aux_node.Next
	}

	new_node, error := createNode(item)
	aux_node.Next = new_node
	return error
}

func add_tail_recursive(node **Node, item *Item) error {
	if *node == nil {
		new_node, error := createNode(item)
		*node = new_node
		return error
	}
	return add_tail_recursive(&(*node).Next, item)
}

func (list *LinkedList) AddTailRecursive(item *Item) error {
	return add_tail_recursive(&list.Head, item)
}

func (list *LinkedList) RemoveHead() *Item {
	if list.Head == nil {
		return nil
	}

	removed := list.Head
	list.Head = removed.Next
	item := removed.Item
	removed = nil
	return item
}

func (list *LinkedList) RemoveTail() *Item {
	if list.Head == nil {
		return nil
	}
	var removed *Node = nil

	if list.Head.Next == nil {
		return list.RemoveHead()
	}

	aux := list.Head
	for aux.Next.Next != nil {
		aux = aux.Next
	}

	removed = aux.Next
	item := removed.Item
	aux.Next = nil
	removed = nil

	return item
}

func (list *LinkedList) FindItem(item *Item) *Item {
	aux_node := list.Head
	for aux_node != nil {
		if aux_node.Item.Value == item.Value {
			return aux_node.Item
		}
		aux_node = aux_node.Next
	}
	return nil
}

func find_item_recursive(node **Node, item *Item) *Item {
	if *node == nil {
		return nil
	}
	if (*node).Item.Value == item.Value {
		return (*node).Item
	}
	return find_item_recursive(&(*node).Next, item)
}

func (list *LinkedList) FindItemRecursive(item *Item) *Item {
	return find_item_recursive(&list.Head, item)
}

func (list *LinkedList) Clear() {
	for list.Head != nil {
		item := list.RemoveHead()
		if item != nil {
			item = nil
		}
	}
}
