with open("13.txt", "r") as file:
  data = file.readlines()

buses = [int(i) if i != "x" else 0 for i in data[1].split(",")]

modulus = 1
for b in buses:
  modulus *= b if b != 0 else 1

timestamp = 0
for b in buses:
  if b != 0:
    timestamp += -buses.index(b) * (modulus // b) * pow(modulus // b, -1, b)

print(timestamp % modulus)