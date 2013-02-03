"""
Same as 3sum, quadratic time algorithm
For each pair of points, memorize the slope and constant
in the linear equation. For simplicity use integer coordinate
"""
from random import *
import numpy as np, pylab as pl
from matplotlib import pyplot, lines

def collinear(points):
    lines = {}
    n = points.shape[1]
    for i in xrange(0, n):
        for j in xrange(i + 1, n):
            x1, y1 = points[0, i], points[1, i]
            x2, y2 = points[0, j], points[1, j]
            if x1 == x2:
                k = 0
                c = x1
            else:
                k = 1.0 * (y2 - y1) / (x2 - x1)
                c = y1 - k * x1
            if lines.has_key((k, c)):
                return lines[(k, c)] + [(x1, y1), (x2, y2)]
            else:
                lines[(k, c)] = [(x1, y1), (x2, y2)]
    return False

if __name__ == '__main__':
    n = 20 
    points = np.random.random_integers(-50, 50, (2, n))
    pts = collinear(points)

    # plot the figure
    fig = pyplot.figure()
    ax = pyplot.subplot(111)
    ax.plot(points[0], points[1], 'ro')
    if  pts != False:
        pts_coord = np.array(pts).transpose()
        line = lines.Line2D(pts_coord[0], pts_coord[1], 
                linewidth=2, color='green')
        ax.add_line(line)
        ax.plot(pts_coord[0], pts_coord[1], 'bo')
    pyplot.show()
