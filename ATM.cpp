#include <iostream>
#include <string>

using namespace std;

// Variables globales para almacenar el PIN y el saldo
string pin = "1234";
double balance = 11500.0;

// Variables para almacenar los saldos de los servicios
double agua = 100.0;
double luz = 200.0;
double telefono = 150.0;
double tarjetaCredito = 500.0;

// Función para verificar el PIN
bool verificarPin(string input) {
    return input == pin;
}

// Función para consultar el saldo
double consultarSaldo() {
    return balance;
}

// Función para hacer un depósito
void depositar(double cantidad) {
    balance += cantidad;
}

// Función para hacer un retiro
bool retirar(double cantidad) {
    if (cantidad <= balance) {
        balance -= cantidad;
        return true;
    } else {
        return false;
    }
}

// Función para cambiar el PIN
void cambiarPin(string nuevoPin) {
    pin = nuevoPin;
}

// Función para pagar servicios
void pagarServicio(string servicio) {
    double* servicioSeleccionado;
    if (servicio == "agua") {
        servicioSeleccionado = &agua;
    } else if (servicio == "luz") {
        servicioSeleccionado = &luz;
    } else if (servicio == "telefono") {
        servicioSeleccionado = &telefono;
    } else {
        cout << "Servicio no reconocido." << endl;
        return;
    }

    if (*servicioSeleccionado <= balance) {
        balance -= *servicioSeleccionado;
        *servicioSeleccionado = 0;
        cout << "Pago exitoso." << endl;
    } else {
        cout << "Fondos insuficientes para pagar el servicio." << endl;
    }
}

// Función para depositar en servicios
void depositarServicio(string servicio, double cantidad) {
    double* servicioSeleccionado;
    if (servicio == "agua") {
        servicioSeleccionado = &agua;
    } else if (servicio == "luz") {
        servicioSeleccionado = &luz;
    } else if (servicio == "telefono") {
        servicioSeleccionado = &telefono;
    } else {
        cout << "Servicio no reconocido." << endl;
        return;
    }

    *servicioSeleccionado += cantidad;
    cout << "Depósito exitoso." << endl;
}

// Función para retirar de servicios
void retirarServicio(string servicio, double cantidad) {
    double* servicioSeleccionado;
    if (servicio == "agua") {
        servicioSeleccionado = &agua;
    } else if (servicio == "luz") {
        servicioSeleccionado = &luz;
    } else if (servicio == "telefono") {
        servicioSeleccionado = &telefono;
    } else {
        cout << "Servicio no reconocido." << endl;
        return;
    }

    if (*servicioSeleccionado >= cantidad) {
        *servicioSeleccionado -= cantidad;
        cout << "Retiro exitoso." << endl;
    } else {
        cout << "Fondos insuficientes en el servicio." << endl;
    }
}

// Función para pagar la tarjeta de crédito
void pagarTarjetaCredito(double cantidad) {
    if (cantidad <= balance) {
        balance -= cantidad;
        tarjetaCredito -= cantidad;
        if (tarjetaCredito < 0) {
            tarjetaCredito = 0;
        }
        cout << "Pago exitoso." << endl;
    } else {
        cout << "Fondos insuficientes para pagar la tarjeta de crédito." << endl;
    }
}

int main() {
    string pinUsuario;
    int opcion;
    string servicio;

    std::cout << "Introduce tu PIN: ";
    std::cin >> pinUsuario;

    if (!verificarPin(pinUsuario)) {
        std::cout << "PIN incorrecto. Acceso denegado." << std::endl;
        return 0;
    }
// ...
do {
        cout << "\n1. Consultar saldo\n2. Depositar\n3. Retirar\n4. Cambiar PIN\n5. Pagar servicio\n6. Depositar a servicio\n7. Retirar de servicio\n8. Pagar tarjeta de crédito\n9. Salir\nElige una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Tu saldo es: " << consultarSaldo() << endl;
                break;
            double cantidad; // Declare the variable "cantidad" before using it

            case 2:
                cout << "Introduce la cantidad a depositar: ";
                std::cin >> cantidad;
                depositar(cantidad);
                break;
            case 3:
                cout << "Introduce la cantidad a retirar: ";
                std::cin >> cantidad;
                if (!retirar(cantidad)) {
                    cout << "Fondos insuficientes." << endl;
                }
                break;
            case 4:
                cout << "Introduce tu nuevo PIN: ";
                std::cin >> pinUsuario;
                cambiarPin(pinUsuario);
                break;
            case 5:
                cout << "Introduce el servicio a pagar (agua, luz, telefono): ";
                std::cin >> servicio;
                pagarServicio(servicio);
                break;
            case 6:
                cout << "Introduce el servicio y la cantidad a depositar (agua, luz, telefono): ";
                std::cin >> servicio >> cantidad;
                depositarServicio(servicio, cantidad);
                break;
            case 7:
                cout << "Introduce el servicio y la cantidad a retirar (agua, luz, telefono): ";
                cin >> servicio >> cantidad;
                retirarServicio(servicio, cantidad);
                break;
            case 8:
                cout << "Introduce la cantidad a pagar de la tarjeta de crédito: ";
                cin >> cantidad;
                pagarTarjetaCredito(cantidad);
                break;
            case 9:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción no reconocida." << endl;
                break;
        }
    } while (opcion != 9);

    return 0;
}