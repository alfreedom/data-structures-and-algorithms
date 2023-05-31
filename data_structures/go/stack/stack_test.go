package stack

import "testing"

func create_sample_stack(t testing.TB, limit int, num_items int) *Stack {
	t.Helper()
	stack := CreateStack(limit)
	for i := 1; i <= num_items; i++ {
		stack.Push(&Item{Value: i})
	}
	return stack
}
func TestCreateStack(t *testing.T) {
	t.Run("Test can create stack with no size limit", func(t *testing.T) {
		stack := CreateStack(0)

		if stack == nil {
			t.Errorf("New created stack must not be 'nil'")
		}

		if stack.Size != 0 {
			t.Errorf("Stack size must be 0")
		}

		if stack.Length != 0 {
			t.Errorf("Lenght of empty stack must be 0")
		}
	})

	t.Run("Test can create stack with size limit", func(t *testing.T) {
		stack := CreateStack(10)

		if stack == nil {
			t.Errorf("New created stack must not be 'nil'")
		}

		if stack.Size != 10 {
			t.Errorf("Stack size must be 0")
		}

		if stack.Length != 0 {
			t.Errorf("The lenght of empty stack must be 0")
		}
	})
}

func TestStackPush(t *testing.T) {
	t.Run("Test can push item on empty stack", func(t *testing.T) {
		stack := CreateStack(0)
		item := CreateItem(10)

		err := stack.Push(item)

		if err != nil {
			t.Errorf("Returned error from Push on empty stack must be 'nil'")
		}

		if stack.Top == nil {
			t.Errorf("Stack top pointer must not be nil when pushed item")
		}

		if stack.Length != 1 {
			t.Errorf("The lenght of empty stack must be %d, got %d", 1, stack.Length)
		}
	})

	t.Run("Test can push item on non empty stack", func(t *testing.T) {
		stack := create_sample_stack(t, 0, 5)
		item := CreateItem(10)
		initial_stack_length := stack.Length

		err := stack.Push(item)

		if err != nil {
			t.Errorf("Returned error from Push on non empty stack must be 'nil'")
		}

		if stack.Length != initial_stack_length+1 {
			t.Errorf("The stack length must be %d, got %d", initial_stack_length+1, stack.Length)
		}

		if stack.Top.Item.Value != item.Value {
			t.Errorf("New pushed value must be %d, got %d", item.Value, stack.Top.Item.Value)
		}
	})

	t.Run("Test cannot push item on full stack", func(t *testing.T) {
		stack := create_sample_stack(t, 5, 5)
		item := CreateItem(10)
		initial_stack_length := stack.Length

		err := stack.Push(item)

		if err == nil {
			t.Errorf("Returned error from Push on full stack must not be 'nil'")
		}

		if err != FullStackError {
			t.Errorf("Returned error from Push on full stack must be 'FullStackError'")
		}

		if stack.Length != initial_stack_length {
			t.Errorf("The stack length must be %d, got %d", initial_stack_length+1, stack.Length)
		}
	})
}

func TestStackPop(t *testing.T) {
	t.Run("Test can pop item on empty stack", func(t *testing.T) {
		stack := CreateStack(0)

		popped_item, err := stack.Pop()

		if err == nil {
			t.Errorf("Returned error from Pop on empty stack must not be 'nil'")
		}

		if err != EmptyStackError {
			t.Errorf("Returned error from Pop on empty stack must be 'EmptyStackError'")
		}

		if popped_item != nil {
			t.Errorf("Popped item from empty stack must be 'nil'")
		}
	})

	t.Run("Test can pop item on non empty stack", func(t *testing.T) {
		stack := create_sample_stack(t, 0, 5)
		initial_stack_length := stack.Length

		popped_item, err := stack.Pop()

		if err != nil {
			t.Errorf("Returned error from Pop an empty stack must be 'nil'")
		}

		if popped_item == nil {
			t.Errorf("Popped item from non empty stack must not be 'nil'")
		}

		if stack.Length != initial_stack_length-1 {
			t.Errorf("Stack length must be %d, got %d", initial_stack_length-1, stack.Length)
		}

		if popped_item.Value != 5 {
			t.Errorf("Popped item value must be %d, got %d", 5, popped_item.Value)
		}
	})
}

func TestStackPeek(t *testing.T) {

	t.Run("Test can peek item on empty stack", func(t *testing.T) {
		stack := CreateStack(0)

		peeked_item, err := stack.Peek()

		if err != EmptyStackError {
			t.Errorf("Returned error from Peek on empty stack must be 'EmptyStackError'")
		}

		if peeked_item != nil {
			t.Errorf("Peeked item from an empty stack must be 'nil'")
		}

	})

	t.Run("Test can peek item on non empty stack", func(t *testing.T) {
		stack := create_sample_stack(t, 0, 5)
		initial_stack_length := stack.Length

		peeked_item, err := stack.Peek()

		if err != nil {
			t.Errorf("Returned error from Peek on non empty stack must be 'nil'")
		}

		if peeked_item == nil {
			t.Errorf("Peeked item from non empty stack must not be 'nil'")
		}

		if stack.Length != initial_stack_length {
			t.Errorf("Stack length must be %d, got %d", initial_stack_length, stack.Length)
		}

		if stack.Top.Item.Value != 5 {
			t.Errorf("Peeked value must be %d, got %d", 5, stack.Top.Item.Value)
		}
	})
}
