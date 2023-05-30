from stack import Stack

OPERATORS = {
    "(": 0,
    ")": 0,
    "+": 1,
    "-": 1,
    "*": 2,
    "/": 2,
    "^": 3,
}

def in2pos(infija: str) -> str:
    inf = infija.replace(" ", "")
    stack = Stack()
    posfija = ""

    for ch in inf:
        if ch == "(":
            stack.push(ch)
        elif ch == ")":
            while stack.length and stack.peek() != "(":
                posfija += stack.pop()
            stack.pop() # Remove the '('
        elif ch not in "+-*/^":
            posfija += ch
        else:
            while stack.length and OPERATORS[ch] <= OPERATORS[stack.peek()]:
                posfija += stack.pop()
            stack.push(ch)

    while stack.length:
        posfija += stack.pop()

    return posfija


def evaluate_posfija(posfija: str):
    stack = Stack()
    for ch in posfija:
        if ch in "+-*/^":
            op2 = float(stack.pop())
            op1 = float(stack.pop())

            if ch == "+":
                stack.push(op1 + op2)
            elif ch == "-":
                stack.push(op1 - op2)
            elif ch == "/":
                stack.push(op1 / op2)
            elif ch == "*":
                stack.push(op1 * op2)
            elif ch == "^":
                stack.push(op1 ** op2)

        else:
            stack.push(ch)


    return stack.pop()


def main():
    infija = "9+4*2"
    posfija = in2pos(infija)

    print("Infija:", infija)
    print("Posfija:", posfija)
    #print("Evaluation:", evaluate_posfija(posfija))

    infija = "(3+4) * 7 / 9 ^ 1 - 2"
    posfija = in2pos(infija)

    print("Infija:", infija)
    print("Posfija:", posfija)
    print("Evaluation:", evaluate_posfija(posfija))

if __name__ == "__main__":
    main()