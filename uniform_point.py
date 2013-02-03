"""
Generate points in a circle uniformly
1) Rejection sampling
2) polar coordinate
"""
import numpy as np, matplotlib.pyplot as plt

def rejection_sampling(n):
    points = np.random.uniform(-1.0, 1.0, size = (2, n))
    sqr = points[0] ** 2 +  points[1] ** 2
    idx = (sqr <= 1.0)
    circle_pts = points[:, idx]
    return circle_pts

def polar_coordinate(n):
    theta = np.random.uniform(0, 2*np.pi, n)
    rr = np.random.uniform(0.0, 1.0, n)
    r = np.sqrt(rr)
    x = r * np.cos(theta)
    y = r * np.sin(theta)
    return np.vstack((x, y))


if __name__ == '__main__':
    n = 1000
    points1 = rejection_sampling(n)
    points2 = polar_coordinate(n)
    plt.figure(1)
    plt.subplot(121)
    plt.axis('equal')
    plt.plot(points1[0], points1[1], 'ro')
    plt.subplot(122)
    plt.axis('equal')
    plt.plot(points2[0], points2[1], 'bo')
    plt.show()
