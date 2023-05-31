package single_linked_list

type Item struct {
	Value int
}

func CreateItem(value int) *Item {
	var item *Item = &Item{
		Value: value,
	}

	return item
}
