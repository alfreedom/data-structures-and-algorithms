package single_linked_list

type Item struct {
	value int
}

func CreateItem(value int) *Item {
	var item *Item = &Item{
		value: value,
	}

	return item
}
