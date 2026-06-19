import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# 1. Carrega os Dados
df = pd.read_csv('dataset_result.csv')
df.columns = df.columns.str.strip()

# 2. Tipifica os Dados
n     = df['Tamanho da Base'].values.astype(float)
total = df['Total de Iterações'].values.astype(float)
media = df['Média de Iterações'].values.astype(float)

# 3. Ajuste Linear (Total)
coef  = np.polyfit(n, total, 1)
curva = np.poly1d(coef)

# 4. Ajuste log₂(n) (Média)
log_n       = np.log2(n)
coef_media  = np.polyfit(log_n, media, 1)
curva_media = np.poly1d(coef_media)

n_smooth    = np.linspace(n.min(), n.max(), 500)
logn_smooth = np.log2(n_smooth)

# ── Figura 1: Total + Média ────────────────────────────────────────────────────
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))

ax1.scatter(n, total, label='Dados Reais')
ax1.plot(n, curva(n), color='orange', label='Ajuste Linear')
ax1.set_title('Total de Iterações vs N')
ax1.set_xlabel('N')
ax1.set_ylabel('Total de Iterações')
ax1.legend()
ax1.grid(True)

ax2.scatter(n, media, color='green', label='Média Real')
ax2.plot(n_smooth, curva_media(logn_smooth), color='red', label='Ajuste log₂(n)')
ax2.set_title('Média de Iterações por Inserção')
ax2.set_xlabel('N')
ax2.set_ylabel('Média de Iterações')
ax2.legend()
ax2.grid(True)

plt.tight_layout()
plt.savefig('analise01.png', dpi=150)
plt.close()

# Figura 2: Complexidade Teórica vs Empírica
teorico_log    = np.log2(n_smooth)
empirico_const = np.full_like(n_smooth, np.mean(media))

plt.figure(figsize=(10, 5))
plt.plot(n_smooth, teorico_log,    color='red',      linestyle='--', label='Teórico Pior Caso: O(log n)')
plt.plot(n_smooth, empirico_const, color='orange',   linestyle='--', label=f'Empírico Médio: O(1) ≈ {np.mean(media):.2f}')
plt.scatter(n, media,              color='steelblue', zorder=5,      label='Média Real por Inserção')
plt.title('Complexidade por Inserção — Teórico vs Empírico')
plt.xlabel('N')
plt.ylabel('Iterações por Inserção')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('analise02.png', dpi=150)
plt.close()

print(f'\nCoeficientes Total : ( {coef[0]:.2f} * n ) + ( {coef[1]:.2f} )')
print(f'Coeficientes Média : ( {coef_media[0]:.4f} * log₂(n) ) + ( {coef_media[1]:.4f} )')
print(f'Média Geral        : {np.mean(media):.4f} Iterações/Inserção\n')
print('Figuras geradas: analise01.png | analise02.png\n')