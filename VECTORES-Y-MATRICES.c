#include <stdio.h>

#define ESTUDIANTES 5 
#define ASIGNATURAS 3 
#define MIN_APROBACION 6.0 

int main() {
    float calificaciones[ESTUDIANTES][ASIGNATURAS];

    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("--- Estudiante %d ---\n", i + 1);
        for (int j = 0; j < ASIGNATURAS; j++) {
            do {
                printf("Ingrese nota Asignatura %d (0-10): ", j + 1);
                scanf("%f", &calificaciones[i][j]);
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
                    printf("Error: Nota fuera de rango.\n");
                }
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }
    
    printf("\nPROMEDIO POR ESTUDIANTE\n"); 
    for (int i = 0; i < ESTUDIANTES; i++) {
        float suma = 0;
        for (int j = 0; j < ASIGNATURAS; j++) {
            suma += calificaciones[i][j];
        }
        printf("Estudiante %d -> Promedio: %.2f\n", i + 1, suma / ASIGNATURAS);
    }
    return 0;
}