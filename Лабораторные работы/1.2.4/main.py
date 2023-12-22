import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def plot_ellipsoid(a, b, c):
    u = np.linspace(0, 2 * np.pi, 100)
    v = np.linspace(0, np.pi, 100)

    x = a * np.outer(np.cos(u), np.sin(v))
    y = b * np.outer(np.sin(u), np.sin(v))
    z = c * np.outer(np.ones(np.size(u)), np.cos(v))

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.plot_surface(x, y, z, alpha=0.4, linewidth=0.2, edgecolor='k')

    # Рисуем оси координат
    ax.quiver(-a, 0, 0, 2*a, 0, 0, color='r', arrow_length_ratio=0.1)
    ax.quiver(0, -b, 0, 0, 2*b, 0, color='g', arrow_length_ratio=0.1)
    ax.quiver(0, 0, -c, 0, 0, 2*c, color='b', arrow_length_ratio=0.1)

    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    ax.set_title('Ellipsoid')

    plt.show()

a = 5  # Большая полуось по оси X
b = 3  # Большая полуось по оси Y
c = 2  # Большая полуось по оси Z

plot_ellipsoid(a, b, c)