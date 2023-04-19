#include <iostream>
#include <math.h>//Required on DevC++/Necesario en DevC++
using std::cout;
using std::cin;
using std::endl;

int main() {
	const long long K = 9 * pow(10, 9);
	double op, f[3], x1, x2, z1, z2, p[3], i1, i2, j1, j2, k1, k2, q1, q2, r;
	do {
		int counter = 1;//Restart counter/Reinicia el counter
		f[0] = 0, f[1] = 0, f[2] = 0, p[0] = 0, p[1] = 0, p[2] = 0;//initialized to zero/inicializado en zero
		cout << "----------------------------------------------------------------\n"
			"Fuerza electrica e intensidad de campo electrico\n"
			"----------------------------------------------------------------\n"
			"Carga sobre la que se desea hallar la fuerza electrica: a*e(b) C\n" << endl;
			do {
				cout << "	a: "; cin >> x1;
				cout << "	b: "; cin >> z1;
				cout << "Coordenada de la carga:\n"
					"	x: "; cin >> i1;
				cout << "	y: "; cin >> j1;
				cout << "	z: "; cin >> k1;
				cout << endl;
				q1 = x1 * pow(10, z1);
				cout << "Carga principal: " << x1 << "*e(" << z1 << ") en/in: (" << i1 << "; " << j1 << "; " << k1 << ")\n"//Displays the information entered to rule out errors/Muestra la información ingresada para descartar errores
				"Cambiar la carga principal?(1.Si/2.No): "; cin >> op;//Allows you to modify information/Permite modificar información
			} while (op == 1);//Repeat until op = 1/Repite hasta que op = 1
			cout << endl;
			do  {
				cout << "Q" << counter << ": a*e(b) C\n"
					"	a: "; cin >> x2;
				cout << "	b: "; cin >> z2;
				cout << "Q" << counter << " Coordenada de Q" << counter << ":\n"
					"	x: "; cin >> i2;
				cout << "	y: "; cin >> j2;
				cout << "	z: "; cin >> k2;
				q2 = x2 * pow(10, z2);
				cout << endl;
				cout << "*Q" << counter << ": " << x2 << "*e(" << z2 << ")C en : (" << i2 << "; " << j2 << "; " << k2 << ")\n"
					<< counter << "Cambiar Q" << counter << "?(1.Si/2.No): "; cin >>op;
				cout << endl;
				if (op == 2) {
					p[0] = i1 - i2;//p[0] contains the difference of x coordinates between the two charges/p[0] contiene la diferencia de coordenas x entre las dos cargas 
					p[1] = j1 - j2;//p[0] contains the difference of y coordinates between the two charges/p[0] contiene la diferencia de coordenas y entre las dos cargas
					p[2] = k1 - k2;//p[0] contains the difference of z coordinates between the two charges/p[0] contiene la diferencia de coordenas z entre las dos cargas
					r = sqrt(pow(p[0], 2) + pow(p[1], 2) + pow(p[2], 2));//Distance between the two charges/Distancia entre las dos cargas
					for (int a = 0; a < 3; a++) { f[a] = (K * ((q1 * q2) / pow(r, 3))) * p[a] + f[a]; }//Three times for each coordinate (x, y, z)/Tres veces por cada coordenada (x,y,z)
					counter++;
					do {
						cout << "Agregar una carga mas?(1.Y/2.N): "; cin >> op;
					} while (op != 1 && op != 2);//If op = 1 or op = 2 the loop do-while is over / Si op = 1 o op = 2 el bucle do-while se termina
					cout << endl;
				}
			} while (op == 1);
		cout << "La fuerza electrica en la carga " << x1 << "*e(" << z1 << ")C es (" << f[0] << "; " << f[1] << "; " << f[2] << ")N and la intensidad del campo electrico es (" << f[0] / q1 << "; " << f[1] / q1 << "; " << f[2] / q1 << ")V/m\n" << endl;
		cout << endl;
		do {
			cout << "1.Reiniciar\n"
				"2.Salir\n"
				"Seleccione una opcion: "; cin >> op;
			cout << endl;
			if (op == 1) { system("CLS"); }//Clean the console/Limpia la consola			
		}while (op != 1 && op != 2);//If op = 1 or op = 2 the loop is over/Si op = 1 o op = 2 el bucle se termina
	} while (op == 1);//Repeat program until op = 1/Repite el programa hasta que op = 1
}