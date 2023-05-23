package single_linked_list

import (
	"testing"
)

func create_sample_list(t testing.TB, item_count int) *LinkedList {
	list, _ := CreateLinkedList()

	for i := 1; i <= item_count; i++ {
		list.AddHead(&Item{value: i})
	}
	return list
}
func TestCanCreateLinkedList(t *testing.T) {
	linked_list, _ := CreateLinkedList()

	if linked_list == nil {
		t.Errorf("The new linkeds list must not be 'nil'.")
	}

	if linked_list.head != nil {
		t.Errorf("The head of empty linked list must be 'nil'.")
	}
}

func TestCanAddItemToHead(t *testing.T) {

	t.Run("test add item to head in empty list", func(t *testing.T) {
		linked_list, _ := CreateLinkedList()
		item_to_add, _ := CreateItem(10)

		linked_list.AddHead(item_to_add)

		if linked_list.Length() != 1 {
			t.Errorf("List lenght must be %q, got %q", 1, linked_list.Length())
		}

		if linked_list.head == nil {
			t.Errorf("List head must not be 'nil'.")
		}

		if linked_list.head.item.value != 10 {
			t.Errorf("Head item must be %q, got %q", 10, linked_list.head.item.value)
		}
	})

	t.Run("test add item to head in non empty list", func(t *testing.T) {
		linked_list := create_sample_list(t, 5)
		initial_len := linked_list.Length()
		item_to_add, _ := CreateItem(10)

		linked_list.AddHead(item_to_add)

		if linked_list.Length() != 6 {
			t.Errorf("List lenght must be %d, got %d", initial_len+1, linked_list.Length())
		}

		if linked_list.head.item.value != 10 {
			t.Errorf("Head item must be %d, got %d", 10, linked_list.head.item.value)
		}
	})
}

func TestAddItemToTail(t *testing.T) {
	t.Run("test add item to tail in empty list", func(t *testing.T) {
		linked_list, _ := CreateLinkedList()
		item_to_add, _ := CreateItem(10)

		linked_list.AddTail(item_to_add)

		if linked_list.head == nil {
			t.Errorf("List head must not be 'nil'.")
		}

		if linked_list.head.item.value != 10 {
			t.Errorf("Head item must be %q, got %q", 10, linked_list.head.item.value)
		}
	})

	t.Run("test add item to tail in non empty list", func(t *testing.T) {
		linked_list := create_sample_list(t, 5)
		initial_len := linked_list.Length()
		item_to_add, _ := CreateItem(10)

		linked_list.AddTail(item_to_add)

		if linked_list.Length() != 6 {
			t.Errorf("List lenght must be %d, got %d", initial_len+1, linked_list.Length())
		}

		if linked_list.head.item.value != 5 {
			t.Errorf("Head item must be %d, got %d", 10, linked_list.head.item.value)
		}
	})
}

func TestAddItemToTailRecursively(t *testing.T) {
	t.Run("test add item to tail in empty list recursive", func(t *testing.T) {
		linked_list, _ := CreateLinkedList()
		item_to_add, _ := CreateItem(10)

		linked_list.AddTailRecursive(item_to_add)

		if linked_list.head == nil {
			t.Errorf("List head must not be 'nil'.")
		}

		if linked_list.head.item.value != 10 {
			t.Errorf("Head item must be %q, got %q", 10, linked_list.head.item.value)
		}
	})

	t.Run("test add item to tail in non empty list recursive", func(t *testing.T) {
		linked_list := create_sample_list(t, 5)
		initial_len := linked_list.Length()
		item_to_add, _ := CreateItem(10)

		linked_list.AddTailRecursive(item_to_add)

		if linked_list.Length() != 6 {
			t.Errorf("List lenght must be %d, got %d", initial_len+1, linked_list.Length())
		}

		if linked_list.head.item.value != 5 {
			t.Errorf("Head item must be %d, got %d", 10, linked_list.head.item.value)
		}
	})
}

func TestCanRemoveAtHead(t *testing.T) {
	t.Run("test can remove at head in empty list", func(t *testing.T) {
		list, _ := CreateLinkedList()

		removed := list.RemoveHead()

		if removed != nil {
			t.Errorf("Removed item must be 'nil' in empty list.")
		}

	})

	t.Run("test can remove at head in non empty list", func(t *testing.T) {
		list := create_sample_list(t, 5)

		removed := list.RemoveHead()

		if removed == nil {
			t.Errorf("Removed item must not be 'nil' in non empty list.")
		}

		if list.Length() != 4 {
			t.Errorf("List length must be %d, got %d", 4, list.Length())
		}

		if removed.value != 5 {
			t.Errorf("Removed item value must be %d, got %d", 5, removed.value)
		}
	})
}

func TestCanRemoveAtTail(t *testing.T) {
	t.Run("test can remove at tail in empty list", func(t *testing.T) {
		list, _ := CreateLinkedList()

		removed := list.RemoveTail()

		if removed != nil {
			t.Errorf("Removed item must be 'nil' in empty list.")
		}

	})

	t.Run("test can remove at tail in non empty list", func(t *testing.T) {
		list := create_sample_list(t, 5)

		removed := list.RemoveTail()

		if removed == nil {
			t.Errorf("Removed item must not be 'nil' in non empty list.")
		}

		if list.Length() != 4 {
			t.Errorf("List length must be %d, got %d", 4, list.Length())
		}

		if removed.value != 1 {
			t.Errorf("Removed item value must be %d, got %d", 1, removed.value)
		}
	})

	t.Run("test can remove at tail in list with one element", func(t *testing.T) {
		list := create_sample_list(t, 1)

		removed := list.RemoveTail()

		if removed == nil {
			t.Errorf("Removed item must not be 'nil' in non empty list.")
		}

		if list.Length() != 0 {
			t.Errorf("List length must be %d, got %d", 0, list.Length())
		}

		if removed.value != 1 {
			t.Errorf("Removed item value must be %d, got %d", 1, removed.value)
		}

		if list.head != nil {
			t.Errorf("List head must be 'nil' after remove all items.")
		}
	})
}

func TestCanFindItem(t *testing.T) {
	t.Run("Test can find item in empty list", func(t *testing.T) {
		list, _ := CreateLinkedList()
		item_to_find, _ := CreateItem(10)

		item_found := list.FindItem(item_to_find)

		if item_found != nil {
			t.Errorf("Found item must be 'nil' in empty list.")
		}

	})
	t.Run("Test can find item in non empty list", func(t *testing.T) {
		list := create_sample_list(t, 5)
		item_to_find, _ := CreateItem(3)

		item_found := list.FindItem(item_to_find)

		if item_found == nil {
			t.Errorf("Found item must not be 'nil' in non empty list.")
		}

		if item_to_find.value != item_found.value {
			t.Errorf("Found item value must be %d, got %d", item_found.value, item_found.value)
		}
	})
	t.Run("Test can find non existent item in non empty list", func(t *testing.T) {
		list := create_sample_list(t, 5)
		item_to_find, _ := CreateItem(100)

		item_found := list.FindItem(item_to_find)

		if item_found != nil {
			t.Errorf("Found item must be 'nil' if not exists.")
		}
	})
}

func TestCanFindItemRecursively(t *testing.T) {
	t.Run("Test can find item in empty list recursively", func(t *testing.T) {
		list, _ := CreateLinkedList()
		item_to_find, _ := CreateItem(10)

		item_found := list.FindItemRecursive(item_to_find)

		if item_found != nil {
			t.Errorf("Found item must be 'nil' in empty list.")
		}

	})
	t.Run("Test can find item in non empty list recursively", func(t *testing.T) {
		list := create_sample_list(t, 5)
		item_to_find, _ := CreateItem(3)

		item_found := list.FindItemRecursive(item_to_find)

		if item_found == nil {
			t.Errorf("Found item must not be 'nil' in non empty list.")
		}

		if item_to_find.value != item_found.value {
			t.Errorf("Found item value must be %d, got %d", item_found.value, item_found.value)
		}
	})
	t.Run("Test can find non existent item in non empty list recursively", func(t *testing.T) {
		list := create_sample_list(t, 5)
		item_to_find, _ := CreateItem(100)

		item_found := list.FindItemRecursive(item_to_find)

		if item_found != nil {
			t.Errorf("Found item must be 'nil' if not exists.")
		}
	})
}
