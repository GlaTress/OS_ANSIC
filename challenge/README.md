# Retos en ANSI C — Sistemas Operativos

Pequeño set de 5 ejercicios en C para practicar conceptos de SO. Compilas con `make`, ejecutas `./retoN`, limpias con `make clean`. Rápido y sin drama.

---

## 🧩 Ejercicios

| # | Fuente         | Ejecutable |
| - | -------------- | ---------- |
| 1 | `challenge1.c` | `reto1`    |
| 2 | `challenge2.c` | `reto2`    |
| 3 | `challenge3.c` | `reto3`    |
| 4 | `challenge4.c` | `reto4`    |
| 5 | `challenge5.c` | `reto5`    |

---

## ✅ Requisitos

* `gcc`
* `make`
* Linux o macOS

---

## ⚙️ Compilación

```bash
# Compilar todo
make

# Compilar solo un reto
make reto3
```

---

## 🚀 Ejecución

```bash
./reto1
./reto2
./reto3
./reto4
./reto5
```

---

## 🧽 Limpieza

```bash
make clean
```

---

## 📁 Estructura sugerida

```
.
├─ challenge1.c
├─ challenge2.c
├─ challenge3.c
├─ challenge4.c
├─ challenge5.c
├─ Makefile
└─ README.md
```

---

## 🛠️ Objetivos de `make` (referencia)

```Makefile
# make        -> compila todos los retos
# make retoN  -> compila solo el N
# make clean  -> elimina binarios
```

---

## 🧪 Tip rápido de prueba

```bash
# Ver salida y código de retorno
./reto1 ; echo "exit:$?"
```

---

## 📎 Notas

* Flags y dependencias se controlan en el `Makefile`.
* Si falla la compilación, verifica que `gcc` y `make` estén en PATH.
