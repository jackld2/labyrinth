#include "ofApp.h"

//--------------------------------------------------------------
void labyrinthGame::setup(){
	player_img.load("player.png");
	background_img.load("background.png");
	bullet_img.load("bullet.png");
	bullet_ = Bullet(10, 15, 30, 30);
	bullet_.setImage(bullet_img);
	Weapon weapon = Weapon(bullet_);
	player = Player();
	player.exchangeWeapon(weapon);
	player.setImage(&player_img);
	current_room_ = Room();
	current_room_.addPlayer(&player);
	current_room_.setImage(&background_img);
	ofSetBackgroundColor(0, 0, 0);
}

//--------------------------------------------------------------
void labyrinthGame::update(){
	current_room_.update();

	//player.update();

}

//--------------------------------------------------------------
void labyrinthGame::draw(){
	current_room_.drawRoom();
	//background_img.draw(0, 0);
	//player.draw();

}

//--------------------------------------------------------------
void labyrinthGame::keyPressed(int key){
	int upper_key = toupper(key);

	if (upper_key == 'W') {
		player.up_ = true;
	}
	if (upper_key == 'A') {
		player.left_ = true;
	}
	if (upper_key == 'S') {
		player.down_ = true;
	}
	if (upper_key == 'D') {
		player.right_ = true;
	}
	if (upper_key == OF_KEY_UP) {
		current_room_.playerShoot(0);
	}
	if (upper_key == OF_KEY_DOWN) {
		current_room_.playerShoot(2);
	}
	if (upper_key == OF_KEY_LEFT) {
		current_room_.playerShoot(3);
	}
	if (upper_key == OF_KEY_RIGHT) {
		current_room_.playerShoot(1);
	}
	if (upper_key == OF_KEY_F11) {
		ofToggleFullscreen();
		return;
	}
	if (upper_key == 'K') {
		ofToggleFullscreen();
		current_room_.resize();
		return;
	}

}

//--------------------------------------------------------------
void labyrinthGame::keyReleased(int key){
	int upper_key = toupper(key);

	if (upper_key == 'W') {
		player.up_ = false;
	}
	if (upper_key == 'A') {
		player.left_ = false;
	}
	if (upper_key == 'S') {
		player.down_ = false;
	}
	if (upper_key == 'D') {
		player.right_ = false;
	}

}

////--------------------------------------------------------------
//void ofApp::mouseMoved(int x, int y ){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseDragged(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mousePressed(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseReleased(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseEntered(int x, int y){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseExited(int x, int y){
//
//}
//
////--------------------------------------------------------------
//void ofApp::windowResized(int w, int h){
//
//}
//
////--------------------------------------------------------------
//void ofApp::gotMessage(ofMessage msg){
//
//}
//
////--------------------------------------------------------------
//void ofApp::dragEvent(ofDragInfo dragInfo){ 
//
//}
