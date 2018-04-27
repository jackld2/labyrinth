#pragma once

#include "ofMain.h"
#include "Player.h"
#include "Room.h"

class labyrinthGame : public ofBaseApp{

	enum GameState {
		START = 0,
		IN_PROGRESS,
		DEATH,
	};

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		//void mouseMoved(int x, int y );
		//void mouseDragged(int x, int y, int button);
		//void mousePressed(int x, int y, int button);
		//void mouseReleased(int x, int y, int button);
		//void mouseEntered(int x, int y);
		//void mouseExited(int x, int y);
		//void windowResized(int w, int h);
		//void dragEvent(ofDragInfo dragInfo);
		//void gotMessage(ofMessage msg);

private:
	ofImage player_img;
	ofImage background_img;
	ofImage bullet_img;
	Room current_room_;
	Bullet bullet_;

	Player player;
	

		
};
