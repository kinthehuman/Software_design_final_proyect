#include "menuManager.h"


int main(){

	menuManager* menu = new menuManager();
	
	menu->run();
	
	delete menu;
	
	return 0;	
	
}
