def treagle(n):
    m = int((n + 1) / 2)
    i = 1
    while i <= m:
        print(' ' * (m - i), '*' * i)
        i += 1

    i = m - 1
    while i >= 0:
        print(' ' * (m - i), '*' * i)
        i -= 1
    return 1


try:
    n = input()
    n = int(n)
    if n % 2 == 0 or n == 0:
        print("Значение n должно быть нечетным и больше 0.")
    else:
        b = treagle(n)
        print(b)
except ValueError:
    print("Значение n должно быть целочисленным.")
