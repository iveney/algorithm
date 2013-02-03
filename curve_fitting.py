"""
Fit a curve using polynomial order of n,
where n is the number of data points
"""

from scipy import *
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

#xs = array([1.0, 2.0, 3.0, 4.0, 5.0, 6.0])
#ys = array([0.0, 5.0, -4.0, 3.0, -5.0, -6.0])

xmin, xmax = -10, 10
numx = 10
xs = linspace(xmin, xmax, numx)
ys = sin(xs) * cos(xs)

def f(x, *args):
    """
    x is a list of points
    args is arbitrary length arguments
    """
    lenarg = len(args)
    lenx = len(x)
    s = zeros(lenx)
    xx = ones(lenx)
    for i in range(lenarg):
        s = s + args[i] * xx
        xx = xx * x
    return s

order = numx

# initial guess p0 is required to tell the function num args
popt, _ = curve_fit(f, xs, ys, p0 = ones(order))

plt.plot(xs, ys, 'ro')

# put 100 points between each x to plot the curve
n = numx * 100
x = linspace(min(xs), max(xs), n)
plt.plot(x, f(x, *popt), 'b')
plt.show()
