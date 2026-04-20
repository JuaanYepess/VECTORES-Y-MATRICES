#include <stdio.h>

#define ESTUDIANTES 5
#define ASIGNATURAS 3

int main() {
    float calificaciones[ESTUDIANTES][ASIGNATURAS];
    float suma_est, suma_asig, max, min;
    int aprobados, reprobados;

    for (int i = 0; i < ESTUDIANTES; i++) {
        for (int j = 0; j < ASIGNATURAS; j++) {
            do {
                printf("Estudiante %d - Asignatura %d: ", i + 1, j + 1);
                scanf("%f", &calificaciones[i][j]);
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }

    printf("\n--- RESULTADOS POR ESTUDIANTE ---\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        suma_est = 0;
        max = calificaciones[i][0];
        min = calificaciones[i][0];
        for (int j = 0; j < ASIGNATURAS; j++) {
            suma_est += calificaciones[i][j];
            if (calificaciones[i][j] > max) max = calificaciones[i][j];
            if (calificaciones[i][j] < min) min = calificaciones[i][j];
        }
        printf("Est %d | Prom: %.2f | Max: %.2f | Min: %.2f\n", i + 1, suma_est / ASIGNATURAS, max, min);
    }

    printf("\n--- RESULTADOS POR ASIGNATURA ---\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        suma_asig = 0;
        aprobados = 0;
        reprobados = 0;
        max = calificaciones[0][j];
        min = calificaciones[0][j];
        for (int i = 0; i < ESTUDIANTES; i++) {
            suma_asig += calificaciones[i][j];
            if (calificaciones[i][j] > max) max = calificaciones[i][j];
            if (calificaciones[i][j] < min) min = calificaciones[i][j];
            if (calificaciones[i][j] >= 6) aprobados++;
            else reprobados++;
        }
        printf("Asig %d | Prom: %.2f | Max: %.2f | Min: %.2f | Ap: %d | Rep: %d\n", j + 1, suma_asig / ESTUDIANTES, max, min, aprobados, reprobados);
    }

    return 0;
}