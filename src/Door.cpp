#include "Door.h"



Door::Door() {}

Door::Door(int cardinal) {
	cardinal_ = cardinal;
}

Door::~Door() {
}

void Door::setImage(ofImage image) {
	image_ = image;
	image_.rotate90(cardinal_);
}

void Door::setPosition(ofVec2f pos) {
	position_ = pos;
}

ofVec2f Door::getPosition() {
	return position_;
}

void Door::draw() {
	image_.draw(position_.x - DOOR_WIDTH / 2, position_.y - DOOR_HEIGHT / 2, DOOR_WIDTH, DOOR_HEIGHT);
}
