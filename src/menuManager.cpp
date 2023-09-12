#include "menuManager.h"

menuManager::menuManager(){

	int MENU1 = 0;
	int MENU2 = 0;
	int MENU3 = 0;
	
}

menuManager::menuManager(int a, int b, int c){

	int MENU1 = a;
	int MENU2 = b;
	int MENU3 = c;
	
}

void menuManager::run(){

	//FOR ALL MENUS
	const int RESET = 0;
	
	//MENU1 INDEX
	const int NEWACC = 1;
	const int LOGIN = 2;
	const int EXIT = 3;
	const int LISTA = 4;
	
	//MENU2 INDEX
	const int CAL = 1;
	const int TEMP = 2;
	const int HUM = 3;
	const int ILU = 4;
	const int LOGOFF = 5;
	const int ADMINMENU = 6;

	//MENU3 INDEX
	const int CHNAME = 1;
	const int CHPASSWORD = 2;
	const int BORRAR = 3;
	const int LISTA2 = 4;
	const int RETURN = 5;
	
	while (!exit){
		if(!interfaz.LoggedIn()){
			switch(MENU1){
				case NEWACC:
					interfaz.ifaceCreateAccount();
					MENU1 = RESET;
				break;
				
				case LOGIN:
					interfaz.ifaceLogin();
					MENU1 = RESET;
				break;
				
				case EXIT:
					interfaz.close();
					exit = true;
					//return 0;
				break;
				
				case LISTA:
					interfaz.displayUsers();
					MENU1 = interfaz.Menu1();
				break;
				
				default:
					interfaz.displayCurrent();
					MENU1 = interfaz.Menu1();
				break;
			}
		//sleep(1);
		}
		else if(MENU2==ADMINMENU && interfaz.Admin()){
			switch(MENU3){
				case CHNAME:
					interfaz.ifaceChUsr();
					MENU3 = RESET;
				break;
				
				case CHPASSWORD:
					interfaz.ifaceChPsw();
					MENU3 = RESET;
				break;
				
				case RETURN:
					MENU3 = RESET;
					MENU2 = RESET;
				break;
				
				case BORRAR:
					interfaz.ifaceDelUsr();
					MENU3 = RESET;
				break;
				
				case LISTA2:
					interfaz.displayUsers();
					MENU3 = interfaz.Menu3();
				break;
				
				default:
					interfaz.displayCurrent();
					MENU3 = interfaz.Menu3();
				break;
			
			}
		//sleep(1);
		
		}
		else{
			switch(MENU2){
				case CAL:
					calidadAire.generateData();
					calidadAire.printData();
				break;
				
				case TEMP:

					temperatura.generateData();
					temperatura.printData();

				break;
				
				case HUM:

					humedad.generateData();
					humedad.printData();

				break;
				
				case ILU:

					iluminacion.generateData();
					iluminacion.printData();

				break;
				
				case ADMINMENU:
					system("clear");
					MENU2 = RESET;
				break;
				
				default:
					interfaz.displayCurrent();
				break;
			}
		
			MENU2 = interfaz.Menu2();
			if(MENU2 == LOGOFF){
				interfaz.ifaceLogoff();
				MENU1 = RESET;
				MENU2 = RESET;
			}
		}
	}
}
