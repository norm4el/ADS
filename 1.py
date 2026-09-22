import numpy as np
import matplotlib.pyplot as plt

# Параметры контура из задачи 14.10
U0 = 80.0
beta = 86.96
omega = 783.3
T = 0.00802

# Время для двух периодов (от 0 до 2T)
# Используем 1000 точек для плавной кривой
t = np.linspace(0, 2 * T, 1000)

# Уравнение напряжения U(t)
u = U0 * np.exp(-beta * t) * np.cos(omega * t)

# Огибающие экспоненты
env_plus = U0 * np.exp(-beta * t)
env_minus = -U0 * np.exp(-beta * t)

# Построение графика
plt.figure(figsize=(10, 6))

# Основная кривая напряжения
plt.plot(t * 1000, u, label=r'$U(t) = 80 e^{-87t} \cos(783t)$', color='blue', linewidth=2)

# Огибающие пунктиром
plt.plot(t * 1000, env_plus, 'r--', alpha=0.7, label='Огибающая экспонента')
plt.plot(t * 1000, env_minus, 'r--', alpha=0.7)

# Оформление осей и сетки
plt.axhline(0, color='black', linewidth=1)
plt.title('График затухающих колебаний U(t) в пределах 2T (Задача 14.10)', fontsize=14)
plt.xlabel('Время t, мс', fontsize=12)
plt.ylabel('Напряжение U, В', fontsize=12)
plt.grid(True, linestyle=':', alpha=0.7)
plt.legend()

# Добавление ключевых точек, рассчитанных в пункте 4
points_t = np.array([0.5 * T, T, 1.5 * T, 2 * T]) * 1000
points_u = np.array([-56.5, 39.8, -28.2, 19.8])
plt.scatter(points_t, points_u, color='red', zorder=5)

# Подписи к точкам
for pt, pu in zip(points_t, points_u):
    offset = 5 if pu > 0 else -8
    plt.text(pt, pu + offset, f'{pu} В', ha='center', fontsize=10, fontweight='bold')

plt.tight_layout()
plt.show()