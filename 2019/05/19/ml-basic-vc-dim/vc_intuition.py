import matplotlib.pyplot as plt

plt.subplot(2,2,1)
plt.scatter([0, 0, 1], [0, 1, 0], color='black', marker='x')
plt.scatter([1], [1], color='black', marker='o')
plt.plot([0.5, 1.0], [1.0, 0.5], color='blue')

plt.subplot(2, 2, 2)
plt.scatter([0, 1, 1], [1, 0, 1], color='black', marker='o')
plt.scatter([0], [0], color='black', marker='x')
plt.plot([0, 0.5], [0.5, 0], color='blue')

plt.subplot(2, 2, 3)
plt.scatter([0], [1], color='black', marker='o')
plt.scatter([1], [0], color='black', marker='x')
plt.plot([0, 1], [0, 1], color='blue')

plt.subplot(2,2,4)
plt.scatter([1, 0], [1, 0], color='black', marker='x')
plt.scatter([0, 1], [1, 0], color='black', marker='o')
plt.text(0.47, 0.45, '?', fontsize=16, color='blue')

plt.show()
