import numpy as np
import matplotlib.pyplot as plt

# Создаем три семейства точек
x1 = [1, 2, 3, 4, 5]
y1 = [3.1591, 6.3112, 9.4834, 12.7319, 15.8389]

x2 = [1, 2, 3, 4, 5]
y2 = [4.2618, 8.5133, 12.7749, 17.0579, 21.3082]

x3 = [1, 2, 3, 4, 5]
y3 = [4.1245, 8.25282, 12.3835, 16.516, 20.6026]

# Применяем метод наименьших квадратов для каждого семейства точек
coeffs1 = np.polyfit(x1, y1, 1)
fit1 = np.poly1d(coeffs1)

coeffs2 = np.polyfit(x2, y2, 1)
fit2 = np.poly1d(coeffs2)

coeffs3 = np.polyfit(x3, y3, 1)
fit3 = np.poly1d(coeffs3)

# Создаем график
fig, ax = plt.subplots()

# Устанавливаем масштаб осей и задаем максимальные/минимальные значения
ax.axis([0, 5.1, 0, 21.4])
x1.insert(0, 0)
x2.insert(0, 0)
x3.insert(0, 0)
y1.insert(0, -0.0292)
y2.insert(0, -0.0080)
y3.insert(0, 0.0101)

# Создаем точки и прямые для каждого семейства точек
ax.scatter(x1, y1, color='blue')
ax.plot(x1, fit1(x1), color='blue', label='Медь: u = {:.4f} м/с'.format(coeffs1[0]*1000*1.2))

ax.scatter(x2, y2, color='red')
ax.plot(x2, fit2(x2), color='red', label='Дюраль: u = {:.4f} м/с'.format(coeffs2[0]*1000*1.2))

ax.scatter(x3, y3, color='green')
ax.plot(x3, fit3(x3), color='green', label='Сталь: u = {:.4f} м/с'.format(coeffs3[0]*1000*1.2))

# Добавляем подписи осей
ax.set_xlabel('Номер гармоники n')
ax.set_ylabel('Частота v, кГц')
plt.text(1.5, 1, "Сверху вниз: дюраль, сталь, медь.", fontsize=10)

# Добавляем легенду
ax.legend()

# Отображаем график
plt.show()
