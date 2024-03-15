import tkinter as tk

def convert_to_brainfuck():
    input_text = input_entry.get()
    output_text = ''
    length = len(input_text)

    output_text += '+' * 10 + '\n'
    output_text += '[' + '\n'
    for char in input_text:
        ascii_value = ord(char)
        onluk = int(ascii_value / 10)
        output_text += '>' + ('+' * onluk) + '\n'
    output_text += '<'*length + '-' + '\n'

    output_text += ']' + '\n'
    for char in input_text:
        ascii_value = ord(char)
        kalan = ascii_value % 10
        output_text += '>' + ('+' * kalan) + '.' + '\n'

    output_text_widget.delete(1.0, tk.END)
    output_text_widget.insert(tk.END, output_text)

root = tk.Tk()
root.title("Str -> BrainFK+[+]")

input_label = tk.Label(root, text="Enter your string:")
input_label.pack()

input_entry = tk.Entry(root, width=30)
input_entry.pack()

convert_button = tk.Button(root, text="Convert", command=convert_to_brainfuck)
convert_button.pack()

output_text_widget = tk.Text(root, wrap="word", height=10, width=30)
output_text_widget.pack()

root.mainloop()
