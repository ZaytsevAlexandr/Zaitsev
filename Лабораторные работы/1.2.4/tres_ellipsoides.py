import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

Tp = 2.52
TcubeX = 3.01
TcubeY = 3.01
TcubeZ = 3.01
TcylX = 3.64
TcylY = 3.64
TcylZ = 3.87
TparX = 3.16
TparY = 3.94
TparZ = 3.67

# 1 / (Tx**2 - Tp**2)**0.5

# Создаем данные для эллипсоидов
u = np.linspace(0, 2 * np.pi, 100)
v = np.linspace(0, np.pi, 100)
x1 = 1 / (TcubeX**2 - Tp**2)**0.5 * np.outer(np.cos(u), np.sin(v))
y1 = 1 / (TcubeY**2 - Tp**2)**0.5 * np.outer(np.sin(u), np.sin(v))
z1 = 1 / (TcubeZ**2 - Tp**2)**0.5 * np.outer(np.ones(np.size(u)), np.cos(v))

x2 = 1 / (TcylX**2 - Tp**2)**0.5 * np.outer(np.cos(u), np.sin(v))
y2 = 1 / (TcylY**2 - Tp**2)**0.5 * np.outer(np.sin(u), np.sin(v))
z2 = 1 / (TcylZ**2 - Tp**2)**0.5 * np.outer(np.ones(np.size(u)), np.cos(v))

x3 = 1 / (TparX**2 - Tp**2)**0.5 * np.outer(np.cos(u), np.sin(v))
y3 = 1 / (TparY**2 - Tp**2)**0.5 * np.outer(np.sin(u), np.sin(v))
z3 = 1 / (TparZ**2 - Tp**2)**0.5 * np.outer(np.ones(np.size(u)), np.cos(v))

# Создаем 3D график
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Наносим эллипсоиды на график
ax.plot_surface(x1, y1, z1, color='blue', alpha=0.1, linewidth=0.5, edgecolor='black')
ax.plot_surface(x2, y2, z2, color='red', alpha=0.1, linewidth=0.5, edgecolor='black')
ax.plot_surface(x3, y3, z3, color='green', alpha=0.1, linewidth=0.5, edgecolor='black')

# Устанавливаем масштабы осей
ax.set_xlim([-0.5, 0.5])
ax.set_ylim([-0.5, 0.5])
ax.set_zlim([-0.5, 0.5])

# Выводим график
plt.show()
