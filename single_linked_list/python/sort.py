from tkinter import Tk, Canvas, ttk
import random
import time

class Window(Tk):
    def __init__(self, width: int, height: int, values: list, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.height = height
        self.width = width
        self.bar_width = 6
        self.values = values
        self.geometry(f"{self.width}x{self.height}")
        self.create_canvas(0, 0)
        button=ttk.Button(self, text="Sort", command=lambda:self.bubble_sort())
        button.pack()
        button2=ttk.Button(self, text="Shuffle", command=lambda:self.shuffle())
        button2.pack()
        button3=ttk.Button(self, text="Sort native", command=lambda:self.sort())
        button3.pack()
        self.draw_bars(self.values, [])

    def create_canvas(self, x: int, y: int):
        self.canvas = Canvas(self, width=self.width, height=self.height)
        self.canvas.pack()
        self.canvas.place(x=x, y=100+y)

    def sort(self):
        self.values.sort()
        self.draw_bars(self.values, [])

    def bubble_sort(self):
        changed = []
        for i in range(len(self.values)):
            for j in range(len(self.values) - i):
                j = j+i
                if self.values[i] > self.values[j]:
                    c = changed + [j]
                    self.values[i], self.values[j] = self.values[j], self.values[i]
                    self.draw_bars(self.values, c)
            changed.append(i)
        self.draw_bars(self.values, changed)

    def shuffle(self):
        random.shuffle(self.values)
        self.draw_bars(self.values, [])

    def draw_bars(self, values: list, changed_indexes: list = list()):
        x = 10
        y = 3
        bg_changed = "blue"
        self.canvas.delete("all")
        for i, v in enumerate(values):
            if i in changed_indexes:
                self.canvas.create_rectangle(x + (i*self.bar_width), y + (290-v), self.bar_width + (i*self.bar_width), 290, fill=bg_changed)
            else:
                self.canvas.create_rectangle(x + (i*self.bar_width), y + (290-v), self.bar_width + (i*self.bar_width), 290, fill="yellow")
        self.update()


    def update(self) -> None:
        return super().update()




if __name__ == "__main__":
    num_bars = 130
    values = [2 + (i*2) for i in range(num_bars)]

    app = Window(800, 400, values)
    app.mainloop()
    print("Hello")