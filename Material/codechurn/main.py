import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation


plt.rcParams.update({
    'axes.titlesize': 24,
    'axes.labelsize': 14,
    'xtick.labelsize': 12,
    'ytick.labelsize': 12
})


# Parameters
A_base = 10
lambda_ = 0.1
B = 0.2

segment_width_months = 1
N_groups = 10

cmap = plt.get_cmap('tab10')
colors = cmap(range(N_groups))

t_start_months = 0
t_end_months = 25

creation_dates_months = np.linspace(-25, t_end_months, 8000)

group_indices = ((creation_dates_months // segment_width_months) % N_groups).astype(int)

# Create different initial amplitudes for each group: ±30%
np.random.seed(42)  # For reproducibility
# A_groups = A_base * np.random.uniform(0.7, 1.3, size=N_groups)
A_groups = np.full(N_groups, A_base)


def f_per_group(x, t):
    age = t - x
    amps = A_groups[group_indices]
    return np.where(age >= 0, amps * np.exp(-lambda_ * age) + B, 0)


fig, ax = plt.subplots(figsize=(12, 6))

# Adjust y-axis for ±30% amplitude variation
ax.set_xlim(-25, 0)
ax.set_ylim(0, A_base)

ax.set_xlabel("Creation time relative to now (months)")
ax.set_ylabel("Churn (change rate)")
ax.grid(True)

scatters = [ax.scatter([], [], color=colors[i], s=20, edgecolors='none') for i in range(N_groups)]
title = ax.set_title("")


def init():
    for sc in scatters:
        sc.set_offsets(np.empty((0, 2)))
    title.set_text("")
    return scatters + [title]


def update(t_months):
    x_relative = creation_dates_months - t_months
    y = f_per_group(creation_dates_months, t_months)
    valid = creation_dates_months <= t_months

    for i in range(N_groups):
        mask = (group_indices == i) & (x_relative >= -25) & (x_relative <= 0) & valid
        coords = np.column_stack((x_relative[mask], y[mask]))
        scatters[i].set_offsets(coords)

    title.set_text(f"Churn after {int(round(t_months))} months")
    title.set_fontsize(24)
    return scatters + [title]


frames_months = np.linspace(t_start_months, t_end_months, 300)

ax.set_xticks(np.arange(-25, 1, 5))

ani = FuncAnimation(fig, update, frames=frames_months,
                    init_func=init, blit=False, interval=150)

ani.save('code_churn_animation.mp4', writer='ffmpeg', fps=15, dpi=200)

plt.show()
