#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

//prototipos de funcion
void mostrar_mapa();//mostrar mapa
void mostrar_mapa2();//mostrar mapa2
void limpiar_mapa();//llena el mapa de caracteres nulos '\0'
void limpiar_mapa2();//llena el mapa2 de caracteres nulos '\0'
void escribir_en_el_mapa();//escribir en el mapa
void escribir_frase_horizontal_en_mapa();//escribir frase en el mapa
void escribir_numero_horizontal_en_el_mapa();//escribe numeros en el mapa


char mapa[30][30];//mapa de caracteres
int mapa2[30][30];//mapa de numeros enteros

int main(){//----------------------------------------------------------------------------main
	std::cout<<"\a";//sonido
	int opc;
	
	//limpiando mapas
	limpiar_mapa();
	limpiar_mapa2();
		
	do{
		system("cls");
		system("color 71");
		std::cout<<"\t..:MENU:..\n\n";
		std::cout<<"1. Escribir en el mapa";
		std::cout<<"\n2. ver mapa";
		std::cout<<"\n3. Salir";
		std::cout<<"\nDigite opcion: ";std::cin>>opc;
	
	

		switch(opc){
			case 1: system("cls");
					system("color 72");
					escribir_en_el_mapa();
					break;
			case 2: 
					int opc2;
					std::cout<<"\nQue mapa desea ver *(1. Mapa de letras | 2. Mapa de numeros | 3. Todos)* ";std::cin>>opc2;
					switch(opc2){
						case 1: system("cls");system("color 75");mostrar_mapa();break;
						case 2: system("cls");system("color 74");mostrar_mapa2();break;
						case 3: system("cls");system("color 75");mostrar_mapa();system("color 74");std::cout<<"\n\n";mostrar_mapa2();break;
					}
					break;
			case 3:break;
			default: system("color 71");std::cout<<"\nLa opcion digitada no es correcta \n";break;
		}
	}while(opc!=3);
	
	//despedida
	system("cls");
	system("color 79");
	std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t* QUE TENGA UN FELIZ RESTO DEL DIA! *\n\n";
	std::cout<<"\a";//sonido
	getch();
}//-----------------------------------------------------------------------------------------------------fin main

//llena el mapa de caracteres nulos '\0'
void limpiar_mapa(){
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			mapa[i][j]='_';
		}
	}
}

//llena el mapa2 de caracteres nulos '\0'
void limpiar_mapa2(){
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			mapa2[i][j]=00;
		}
	}
}

//muestra el mapa
void mostrar_mapa(){
	std::cout<<"\n\t\t\tMostrando el mapa de letras\n\n";
	for(int i=0;i<30;i++){
		std::cout<<"\t\t\t";
		for(int j=0;j<30;j++){
			std::cout<<mapa[i][j];
		}
		std::cout<<"\n";
	}
	system("pause");
}


//muestra el mapa2
void mostrar_mapa2(){
	std::cout<<"\n\t\t\t\t\tMostrando el mapa de numeros\n\n";
	for(int i=0;i<30;i++){
		std::cout<<"\t\t\t";
		for(int j=0;j<30;j++){
			std::cout<<mapa2[i][j]<<"|";
		}
		std::cout<<"\n";
	}
	system("pause");
}

//escribir en el mapa
void escribir_en_el_mapa(){
	//que quiere escribir en el mapa
	int opc;
	std::cout<<"Que desea escribir en el mapa(1. frase, 2. numero): ";std::cin>>opc;
	
	switch(opc){
		case 1: escribir_frase_horizontal_en_mapa();break;
		case 2: escribir_numero_horizontal_en_el_mapa();break;
	}
	
}

//escribir una frase horizontal en el mapa
void escribir_frase_horizontal_en_mapa(){
	fflush(stdin);//limpiando buffer
	system("cls");
	//tomando frase y tamano de la frase
	char frase[999];
	std::cout<<"\nDigite la frase: ";
	std::cin.getline(frase,999,'\n');
	int len=strlen(frase);
	
	//tomando coordenadas
	int fila,c1,c2;
	std::cout<<"\nDigite la fila: ";std::cin>>fila;
	std::cout<<"\nLos espacios necesarios a dar son "<<len<<"\n";
	std::cout<<"\nDesde: ";std::cin>>c1;
	std::cout<<"\nHasta: ";std::cin>>c2;
	
	//espacio desde c1 hasta c2
	int esp=0;
	for(int i=c1;i<=c2;i++){
		esp++;
	}
	
	//comprobando que la frase quepa en el epacio dado
	if(len<=esp){//en caso de que quepa
		//escribiendo frase en el mapa
		int x=0;
		for(int i=c1;i<=c2;i++){
			mapa[fila-1][i-1]=frase[x];
			x++;
		}
	}
	else{//en caso de que no quepa
		int opc;
		do{
			std::cout<<"\nEl espacio dado no es suficiente *(1. dar nuevas coordenadas, 2. Escribir de todos modos)*: ";std::cin>>opc;
			if(opc==1){
				std::cout<<"\nDigite la fila: ";std::cin>>fila;
				std::cout<<"\nLos espacios necesarios a dar son "<<len<<"\n";	
				std::cout<<"\nDesde: ";std::cin>>c1;
				std::cout<<"\nHasta: ";std::cin>>c2;
					//espacio desde c1 hasta c2
					int esp=0;
					for(int i=c1;i<=c2;i++){
						esp++;
					}
				}
				
			else if(opc==2){
				//escribiendo frase en el mapa
				int x=0;
				for(int i=c1;i<=c2;i++){
					mapa[fila-1][i-1]=frase[x];
					x++;
				}
			}
		}while(opc!=2 && esp==len);
		//escribiendo frase en el mapa
		int x=0;
		for(int i=c1;i<=c2;i++){
			mapa[fila-1][i-1]=frase[x];
			x++;
		}
	}	
}

//escribe numeros horizontalen el mapa2
void escribir_numero_horizontal_en_el_mapa(){
	
	//pide cuantos numeros desea el usuario escribir en el mapa y crea un vector
	int cant;
	std::cout<<"\nCuantos numeros desea escribir en el mapa: ";std::cin>>cant;
	int numeros[cant];
	
	//pidiendo los numeros a escribir en el vector
	std::cout<<"\nDigite los numeros: \n";
	for(int i=0;i<cant;i++){
		std::cin>>numeros[i];
	}
	
	//pidiendo coordenadas
	int fila,c1,c2;
	fflush(stdin);//limpiando buffer
	std::cout<<"\nDigite la fila: ";std::cin>>fila;
	std::cout<<"\nLos espacios necesarios a dar son "<<cant<<"\n";
	std::cout<<"\nDesde: ";std::cin>>c1;
	std::cout<<"\nHasta: ";std::cin>>c2;
	
	
	//espacio desde c1 hasta c2
	int esp=0;
	for(int i=c1;i<=c2;i++){
		esp++;
	}
	
	//comprobando que la frase quepa en el epacio dado
	if(esp==cant){
		//escribiendo en la matriz
		int x=0;
		if(x<cant){
			for(int i=c1;i<=c2;i++){
				mapa2[fila-1][i]=numeros[x];
				x++;
			}
		}
	}
	else{//en caso de que no quepa
		int opc;
		do{
			std::cout<<"\nEl espacio dado no es correcto debe dar los espacios exactos para cada numero *(1. dar nuevas coordenadas, 2. Escribir de todos modos)*: ";std::cin>>opc;
			if(opc==1){
				fflush(stdin);//limpiando buffer
				std::cout<<"\nDigite la fila: ";std::cin>>fila;
				std::cout<<"\nLos espacios necesarios a dar son "<<cant<<"\n";
				std::cout<<"\nDesde: ";std::cin>>c1;
				std::cout<<"\nHasta: ";std::cin>>c2;
			}
			
			else if(opc==2){//escribir de todos mados
				//escribiendo numeros en la matriz
				int x=0;
				for(int i=c1;i<=c2;i++){
					mapa2[fila-1][i]=numeros[x];
					x++;
				}
			}
			//espacio desde c1 hasta c2
			esp=0;
			for(int i=c1;i<=c2;i++){
				esp++;
			}
		}while(esp!=cant && opc!=2);
		//escribiendo numeros en la matriz
		int x=0;
		if(x<cant){
			for(int i=c1;i<=c2;i++){
				mapa2[fila-1][i]=numeros[x];
				x++;
			}
		}
	}	
}//fin funcion