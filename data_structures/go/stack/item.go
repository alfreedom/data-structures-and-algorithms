package stack

type Item struct {
	Value int
}

// Create a new item
func CreateItem(value int) *Item {
	return &Item{
		Value: 10,
	}
}
