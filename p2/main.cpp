#include "macros.hpp"
#include "funcionesAuxiliares.hpp"

int menu();

int main(){

	int opcion;
	do{
	    opcion = menu();
		std::cout << CLEAR_SCREEN;
		PLACE(3,1);
		// Se ejecuta la opción del menú elegida
		switch(opcion){
            case 0:
			    PLACE(3,1);
				std::cout << BIYELLOW;
				std::cout << "[0] Fin del programa" << std::endl << std::endl;
				std::cout << RESET;
				break;
			case 1:
			   	std::cout << BIBLUE;
				std::cout << "[1] Cualquier casilla inicial" << std::endl;
				std::cout << RESET;
                cualquierCasillaInicial();
                std::cin.ignore();
				break;
			case 2:
			   	std::cout << BIBLUE;
				std::cout << "[2] Casilla inicial (1,2)" << std::endl;
				std::cout << RESET;
				cualquierCasillaFinalDesde12();
				break;
			case 3:
			   	std::cout << BIBLUE;
				std::cout << "[3] Casilla inicial (1,7)" << std::endl;
				std::cout << RESET;
				cualquierCasillaFinalDesde17();
				break;
			default:
				std::cout << BIRED;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
				std::cout << "--> ";
			  	std::cout << ONIRED;
				std::cout << opcion << std::endl;
				std::cout << RESET;
        }

        if (opcion !=0){
            std::cout << "Para mostrar el ";
            std::cout << BIGREEN ;
            std::cout << "menú, ";
            std::cout << RESET;
            std::cout << "pulse ";
            std::cout << INVERSE ;
            std::cout << "ENTER";
            std::cout << RESET;
		    // Pausa
		    std::cin.ignore();
		    std::cout << CLEAR_SCREEN;
        }
	}while(opcion!=0);


    return 0;
}

int menu(){
 int opcion, posicion;
	// Se muestran las opciones del menú
	posicion=2;
	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(posicion++,10);
	std::cout << BIBLUE;
	std::cout << "Programa principal | Opciones del menú   ";
	std::cout << RESET;
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[1] Cualquier casilla inicial" << std::endl;
	PLACE(posicion++,10);
	std::cout << "[2] Casilla inicial (1,2)" << std::endl;
    	PLACE(posicion++,10);
	std::cout << "[3] Casilla inicial (1,7)" << std::endl;
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED;
	std::cout << "[0] Fin del programa " << std::endl;
	std::cout << RESET;
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIYELLOW;
	std::cout << "Opción: ";
	std::cout << RESET;
	std::cin >> opcion;
   	// Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();
	return opcion;
}