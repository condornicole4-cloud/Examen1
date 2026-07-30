/*
Nombre del estudiante: Nicole Cóndor
Fecha: 29/07/2026
Tema: Sistema de registro y análisis de notas
Entrada: cantidad, nombres, notas, opción del menú y nombre a buscar
Proceso: validar, almacenar, recorrer, calcular y buscar
Salida: reporte general y resultado de búsqueda
*/
#include <iostream>
#include <string>
using namespace std;

void mostrarMenu();
int registrarEstudiantes(string nombres[], float notas[]);
void mostrarReporte(string nombres[], float notas[], int cantidad);
void buscarEstudiante(string nombres[], float notas[], int cantidad);

int main(){
   string nombres[20];
   float notas[20];
   int cantidad = 0;
   int opcion=0;

   do{
    mostrarMenu();
    cin>>opcion;
    while(opcion<1 || opcion>4){
        cout<<"Opción inválida. Ingrese nuevamente: ";
        cin>>opcion;
    }

    switch(opcion){
        case 1:
            cantidad = registrarEstudiantes(nombres, notas);
            break;
        case 2:
            if(cantidad==0){
                cout<<"No hay estudiantes registrados."<<endl;
            }else{
                mostrarReporte(nombres, notas, cantidad);
            }
            break;
        case 3:
            if(cantidad==0){
                cout<<"No hay estudiantes registrados."<<endl;
            }else{
                buscarEstudiante(nombres, notas, cantidad);
            }
            break;
        case 4:
            cout<<"Saliendo del programa..."<<endl;
            break;
    }
   }while(opcion!=4);

   return 0;
}


void mostrarMenu() {
    cout << "\nMenu de opciones" << endl;
    cout << "1. Registrar estudiantes" << endl;
    cout << "2. Mostrar reporte general" << endl;
    cout << "3. Buscar estudiante" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int registrarEstudiantes(string nombres[], float notas[]) {
    int cant;
    cout << "\nIngrese la cantidad de estudiantes (1 a 20): ";
    cin >> cant;

    // Validación de la cantidad
    while (cant < 1 || cant > 20) {
        cout << "Cantidad invalida. Ingrese un valor entre 1 y 20: ";
        cin >> cant;
    }

    // Registro y validación de datos
    for (int i = 0; i < cant; i++) {
        cout << "\nEstudiante " << i + 1 << ":" << endl;
        cout << "Primer nombre (sin espacios): ";
        cin >> nombres[i];
        
        cout << "Nota final (0 a 20): ";
        cin >> notas[i];

        // Validación de la nota
        while (notas[i] < 0 || notas[i] > 20) {
            cout << "Nota invalida. Ingrese una nota entre 0 y 20: ";
            cin >> notas[i];
        }
    }
    
    cout << "\n¡Datos registrados correctamente!\n";
    return cant; 
}

void mostrarReporte(string nombres[], float notas[], int cantidad) {
    float sumaNotas = 0;
    float notaMayor = notas[0];
    float notaMenor = notas[0];
    string estMayor = nombres[0];
    string estMenor = nombres[0];
    int aprobados = 0;
    int reprobados = 0;

    cout << "\n--- REPORTE GENERAL ---" << endl;
    cout << "Listado de estudiantes:" << endl;
    
    for (int i = 0; i < cantidad; i++) {
        string estado;
        if (notas[i] >= 14) {
            estado = "APROBADO";
        } else {
            estado = "REPROBADO";
        }
        
        cout << i + 1 << ". " << nombres[i] << " - Nota: " << notas[i] << " - " << estado << endl;
        sumaNotas += notas[i];
        
        if (notas[i] >= 14) {
            aprobados++;
        } else {
            reprobados++;
        }

        if (notas[i] > notaMayor) {
            notaMayor = notas[i];
            estMayor = nombres[i];
        }
        if (notas[i] < notaMenor) {
            notaMenor = notas[i];
            estMenor = nombres[i];
        }
    }

    float promedio = sumaNotas / cantidad;

    cout << "Resumen Estadistico:"<< endl;
    cout << "- Promedio general: " << promedio << endl;
    cout << "- Estudiante con nota mayor: " << estMayor << " (" << notaMayor << ")\n";
    cout << "- Estudiante con nota menor: " << estMenor << " (" << notaMenor << ")\n";
    cout << "- Cantidad de aprobados: " << aprobados << endl;
    cout << "- Cantidad de reprobados: " << reprobados << endl;
}

void buscarEstudiante(string nombres[], float notas[], int cantidad) {
    string nombreBusqueda;
    bool encontrado = false;

    cout << "\nIngrese el nombre del estudiante a buscar: ";
    cin >> nombreBusqueda;

    // Búsqueda secuencial
    for (int i = 0; i < cantidad; i++) {
        if (nombres[i] == nombreBusqueda) {
            string estado;
            if (notas[i] >= 14) {
                estado = "APROBADO";
            } else {
                estado = "REPROBADO";
            }
            
            cout << "\nEstudiante encontrado:" << endl;
            cout << "Nombre: " << nombres[i] << " | Nota: " << notas[i] << " | Estado: " << estado << endl;
            encontrado = true;
            break; 
        }
    }

    if (!encontrado) {
        cout << "El estudiante '" << nombreBusqueda << "' no se encuentra registrado." << endl;
    }
}