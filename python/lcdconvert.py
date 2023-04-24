import sys

# ASCII LCD alphabet
alphabet = [
    " _     _  _     _  _  _  _  _ ",
    "| |  | _| _||_||_ |_   ||_||_|",
    "|_|  ||_  _|  | _||_|  ||_| _|"
]

#
# Appends the next n number to the ASCII LCD buffer
#
def append_lcd_num(n, buffer):
  for i in range(3):
    for j in range(3):
      buffer[i].append(alphabet[i][j + 3 * n])

#
# Display the given n number in ASCII LCD format
#
def display_lcd(n):
  stringified_n = str(n)
  final_output = [[], [], []]

  # Create the final output string by appending numbers
  for i in range(len(stringified_n)):
    append_lcd_num(int(stringified_n[i]), final_output)

  # Display the final output string
  for i in range(3):
    print("".join(final_output[i]))

#
# Display usage to user
#
def show_usage():
   print(f"Usage : python3 {sys.argv[0]} [integer]")

#
# Main function, calling display_lcd with the first argument number
#
def main():
  if len(sys.argv) != 2:
    show_usage()
    return

  try:
    n = int(sys.argv[1])
  except:
    print("Please enter a number as the only argument.")
    return
  display_lcd(n)

#
# Only execute this if we are in a CLI context
#
if __name__ == "__main__":
    main()
