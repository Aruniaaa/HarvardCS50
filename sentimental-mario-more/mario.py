try:
   height = int(input("Enter the height "))
except:
    height = int(input("Enter the height "))


while 0 >= height or height > 8:
    height = int(input("Enter the height "))
symbol = '#'
space = " "

for i in range(1, height + 1):
    print(f"{(space * (height- i)) + symbol * i}  {symbol * i}")



