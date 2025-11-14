Actividad 1 — Productor/Consumidor (Semáforos POSIX)
Pontificia Universidad Javeriana
Profesor: John Jairo Corredor, PhD
Autor: Thomas Leal Puerta
Fecha: 13 Noviembre de 2025

Introducción
Esta actividad valida el esquema productor–consumidor con semáforos POSIX y memoria compartida. Se realizan dos pruebas: (1) el productor llena inicialmente solo 5 posiciones del búfer y queda bloqueado; (2) al iniciar el consumidor, los elementos se consumen mientras el productor continúa produciendo hasta completar su secuencia.

Requisitos
Sistema operativo Linux.
Compilador gcc.
Ejecutables: producer, consumer.

Prueba 1 – Llenado inicial limitado (productor produce 5)
Objetivo:
Verificar que el productor respete la cota inicial del búfer y se bloquee tras producir exactamente 5 elementos cuando no hay consumidor activo.

Conceptos aplicados:
sem_open, sem_wait, sem_post
shm_open, ftruncate, mmap
Búfer circular (índices entrada/salida)

Compilación y ejecución:
gcc producer.c -o producer
./producer
La consola debe mostrar: “Productor: Produce 1” … “Productor: Produce 5” y detenerse sin producir más.

Prueba 2 – Consumo en curso con producción continua
Objetivo:
Comprobar que al iniciar el consumidor, los elementos existentes se consumen y el productor reanuda la producción (produce 6..10) a medida que se liberan espacios.

Conceptos aplicados:
Semáforo de elementos disponibles (lleno)
Semáforo de espacios disponibles (vacío)
Coordinación sin espera activa

Compilación y ejecución:
gcc consumer.c -o consumer
./consumer   (con el productor de la Prueba 1 ya ejecutado)
La consola del consumidor mostrará: “Consumidor: Consume 1” … “Consumidor: Consume 10”.
La consola del productor mostrará la reanudación: “Productor: Produce 6” … “Productor: Produce 10”.

Conclusión
El sistema implementa correctamente el control de capacidad y la sincronización: el productor se bloquea al alcanzar cinco elementos sin consumidor y, una vez iniciado el consumidor, ambos procesos avanzan de forma coordinada sin pérdidas ni desbordes.

