#pragma once
#define STB_IMAGE_IMPLEMENTATION
#ifndef TEXTURE_HPP
#define TEXTURE_HPP


#include "stb_image.h"
#include <iostream>
#include <stdio.h>


namespace Tex {

	struct Textures {
		int tex_id;
		static int next_tex_id;
		int width, height, channels;
		unsigned char* img;

		Textures() : tex_id(next_tex_id++) {};

		void loadImg(const char* img_path) {

			unsigned char* img_data = stbi_load(img_path, &width, &height, &channels, 0);

			// check if image has loaded and if it has, set img to the img data
			if (img_data) {
				std::cout << "loaded image: " << img_path << "\n";

				img = img_data;
			}
			// image failed to load
			else {
				std::cout << "image failed to load: " << img_path << "\n";
			}
			stbi_image_free(img_data);
		}

		int getTexId() {
			return tex_id;
		}

	};

	int Textures::next_tex_id = 1;
}

#endif // !TEXTURE_HPP