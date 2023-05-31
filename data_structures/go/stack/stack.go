package stack

import "errors"

// Node structure
type Node struct {
	item *Item
	next *Node
}

// Stack main structure
type Stack struct {
	top    *Node
	size   int
	length int
}

var EmptyStackError = errors.New("Stack is empty")
var FullStackError = errors.New("Stack is full")

// Create a new empty stack
func CreateStack(size int) *Stack {
	return &Stack{
		top:    nil,
		size:   size,
		length: 0,
	}
}

// Create a new Node
func CreateNode(item *Item) *Node {
	return &Node{
		item: item,
		next: nil,
	}
}

// Push an item into stack, Returns error if stack is full
func (stack *Stack) Push(item *Item) error {
	if stack.size == 0 || stack.length < stack.size {
		new_node := CreateNode(item)
		new_node.next = stack.top
		stack.top = new_node
		stack.length++
		return nil
	}
	return FullStackError
}

// Pop an item from stack. Returns error if stack is empty
func (stack *Stack) Pop() (*Item, error) {
	if stack.top == nil {
		return nil, EmptyStackError
	}
	removed_node := stack.top
	stack.top = removed_node.next
	item := removed_node.item
	stack.length--

	return item, nil
}

// Peek an item from stack withour removing. Returns error if stack is empty
func (stack *Stack) Peek() (*Item, error) {
	if stack.top == nil {
		return nil, EmptyStackError
	}
	return stack.top.item, nil
}
