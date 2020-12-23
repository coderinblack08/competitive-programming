import fileinput
lines = [l.strip() for l in list(fileinput.input(files='input.txt'))]
storage = 7881

for line in lines: 
  collected, used = [float(x) for x in line.split()]
  collected = collected * 1269.90;
  cumulative = max((storage + collected) - used, 0)
  print('Cumulative Storage', cumulative)
  print('Storage', min(15000, cumulative))
  storage = min(15000, cumulative)
