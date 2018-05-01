#pragma once
#include "ofMain.h"
class Door
{
public:
	Door();
	Door(int cardinal);
	~Door();
	void setImage(ofImage image); //sets image of the door
	void setPosition(ofVec2f pos); //sets position of the door
	ofVec2f getPosition(); //returns position of the door

	void draw();
	static const int DOOR_WIDTH = 155;
	static const int DOOR_HEIGHT = 125;

private:
	ofVec2f position_;
	ofImage image_;
	int cardinal_;

};

