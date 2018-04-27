#pragma once
#include "ofMain.h"
class ImageLoad
{
public:
	ImageLoad();
	~ImageLoad();

	static ofImage background_image_;
	static ofImage player_image_;
	static ofImage bullet_image_;
	static ofImage door_image_;

	static void loadImages();
};

