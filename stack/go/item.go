package stack

type Item struct {
	value int
}

// Create a new item
func CreateItem(value int) *Item {
	return &Item{
		value: 10,
	}
}
