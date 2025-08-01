quarter = 25
dime = 10
nickel = 5
penny = 1

count = 0

while True:
    try:
        change = float(input("Change owed: "))
        if change >= 0:
            break
    except:
        continue

change = round(change * 100)

while change > 0:
    if change >= quarter:
        change -= quarter
        count += 1
    elif change >= dime:
        change -= dime
        count += 1
    elif change >= nickel:
        change -= nickel
        count += 1
    elif change >= penny:
        change -= penny
        count += 1

print(f"{count}")

