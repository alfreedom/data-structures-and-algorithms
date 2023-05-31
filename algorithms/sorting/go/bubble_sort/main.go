package main

import (
	"fmt"

	"github.com/duckylabs/data-structures-and-algorithms/data_structures/go/single_linked_list"
)

type List struct {
	single_linked_list.LinkedList
}

func (list *List) BubbleSort() {

	for aux := list.Head; aux != nil; aux = aux.Next { // From first list element
		for aux2 := aux.Next; aux2 != nil; aux2 = aux2.Next { // From second list element
			if aux.Item.Value > aux2.Item.Value {
				temp := aux.Item
				aux.Item = aux2.Item
				aux2.Item = temp
			}
		}
	}

}

func main() {
	list := &List{
		LinkedList: single_linked_list.LinkedList{Head: nil},
	}

	list.AddHead(single_linked_list.CreateItem(67))
	list.AddHead(single_linked_list.CreateItem(32))
	list.AddHead(single_linked_list.CreateItem(6))
	list.AddHead(single_linked_list.CreateItem(21))
	list.AddHead(single_linked_list.CreateItem(67))
	list.AddHead(single_linked_list.CreateItem(84))

	fmt.Println(list.String())

	list.BubbleSort()
	fmt.Println(list.String())
}
