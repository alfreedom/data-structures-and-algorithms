package stack

import "errors"

// Node structure
type Node struct {
	Item *Item
	Next *Node
}

// Stack main structure
type Stack struct {
	Top    *Node
	Size   int
	Length int
}

var EmptyStackError = errors.New("Stack is empty")
var FullStackError = errors.New("Stack is full")

// Create a new empty stack
func CreateStack(size int) *Stack {
	return &Stack{
		Top:    nil,
		Size:   size,
		Length: 0,
	}
}

// Create a new Node
func CreateNode(item *Item) *Node {
	return &Node{
		Item: item,
		Next: nil,
	}
}

// Push an item into stack, Returns error if stack is full
func (stack *Stack) Push(item *Item) error {
	if stack.Size == 0 || stack.Length < stack.Size {
		new_node := CreateNode(item)
		new_node.Next = stack.Top
		stack.Top = new_node
		stack.Length++
		return nil
	}
	return FullStackError
}

// Pop an item from stack. Returns error if stack is empty
func (stack *Stack) Pop() (*Item, error) {
	if stack.Top == nil {
		return nil, EmptyStackError
	}
	removed_node := stack.Top
	stack.Top = removed_node.Next
	item := removed_node.Item
	stack.Length--

	return item, nil
}

// Peek an item from stack withour removing. Returns error if stack is empty
func (stack *Stack) Peek() (*Item, error) {
	if stack.Top == nil {
		return nil, EmptyStackError
	}
	return stack.Top.Item, nil
}
