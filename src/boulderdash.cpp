#include <amigascreen.h>

#include "boulderdash.h"
#include "boulderdashscreen.h"

void BoulderdashApp::startup() {
	BoulderdashScreen* screen =  new BoulderdashScreen();
	woopsiApplication->addGadget(screen);
}

void BoulderdashApp::shutdown() {

	// Call base shutdown method
	Woopsi::shutdown();
}
