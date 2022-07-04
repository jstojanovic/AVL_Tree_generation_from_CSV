#!/usr/bin/env python
with open('data.dat', "r") as file:
    lines = file.readlines()
    file.close()
print(type(lines))
print(lines.sort())
print(lines)
