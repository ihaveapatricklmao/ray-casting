#include "src/render.hpp"

int main() {

	Entity::EntityBase new_dude;
	new_dude.pos = { 2.0, 3.0 };
	World::Points new_point_a(1.0, 2.0);
	World::Points new_point_b(4.0, 2.0);
	World::Points to_pt(2.5, 2.0);
	World::Wall new_wall(new_point_a, new_point_b);
	World::Space new_wrld({ 255, 0, 230 }, { 244, 190, 0 });
	
	World::Wall wall_arr[1] = {new_wall};
	Entity::EntityBase ent_arr[1] = { new_dude };

	new_wrld.assignWorld(wall_arr, ent_arr);

	new_wall.wallMove(to_pt, World::Wall::POINT_B, false, 0.32);


	return -1;
}