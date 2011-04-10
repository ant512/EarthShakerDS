#include <nds.h>
#include "framebuffer.h"
#include "graphics.h"
#include "game.h"
#include "constants.h"

void initGfxMode() {
	powerOn(POWER_ALL_2D);

	videoSetMode( MODE_5_2D | DISPLAY_BG3_ACTIVE );
	videoSetModeSub( MODE_5_2D | DISPLAY_BG3_ACTIVE );

	vramSetBankA( VRAM_A_MAIN_BG );
	vramSetBankC( VRAM_C_SUB_BG );

	// Initialise backgrounds
	bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
}

int main(int argc, char* argv[]) {
	initGfxMode();

	WoopsiGfx::FrameBuffer buffer((u16*)BG_BMP_RAM(0), 256, 192);
	WoopsiGfx::Graphics* gfx = buffer.newGraphics();

	Game* game = new Game();
	game->render(gfx);

	s32 animationTimer = 0;
	s32 movementTimer = 0;

	while(1) {

		animationTimer++;

		if (animationTimer == ANIMATION_TIME) {
			animationTimer = 0;

			game->render(gfx);
		}

		movementTimer++;

		if (movementTimer == MOVEMENT_TIME) {
			movementTimer = 0;

			game->iterate();

			scanKeys();

			if ((keysDown() & KEY_UP) || (keysHeld() & KEY_UP)) {
				game->getPlayerBlock()->applyUpwardForce();
			} else if ((keysDown() & KEY_DOWN) || (keysHeld() & KEY_DOWN)) {
				game->getPlayerBlock()->applyDownwardForce();
			} else if ((keysDown() & KEY_LEFT) || (keysHeld() & KEY_LEFT)) {
				game->getPlayerBlock()->applyLeftwardForce();
			} else if ((keysDown() & KEY_RIGHT) || (keysHeld() & KEY_RIGHT)) {
				game->getPlayerBlock()->applyRightwardForce();
			}
		}

		swiWaitForVBlank();
	}

	return 0;
}
