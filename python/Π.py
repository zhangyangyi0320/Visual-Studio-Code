from decimal import Decimal, getcontext
import time
a=input("Give me a number: ")
getcontext().prec = a+1
pi = Decimal(3.141592653589793) ** a / a
print(str(pi)[:a])
time.sleep(10000)