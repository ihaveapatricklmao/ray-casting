#include "src/render.hpp"

int main() {

	World::Points new_point_a(1.0, 2.0);
	World::Points new_point_b(4.0, 2.0);
	World::Points to_pt(2.5, 2.0);
	World::Wall new_wall(new_point_a, new_point_b);

	new_wall.wallMove(to_pt, World::Wall::POINT_B, false, 0.50);


	return -1;
}