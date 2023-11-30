#include "src/render.hpp"

using namespace World;
using namespace Entity;

int main() {

	EntityBase new_dude{};
	EntityBase new_dude2{};
	new_dude.pos = { 2.0, 3.0 };
	Points new_point_a(1.0, 2.0);
	Points new_point_b(4.0, 2.0);
	Points to_pt(2.5, 2.0);
	Wall new_wall(new_point_a, new_point_b);
	Wall new_wall2(new_point_a, new_point_b);
	Space new_wrld({ 255, 0, 230 }, { 244, 190, 0 });
	
	std::vector<Wall> wall_arr = { new_wall, new_wall2 };
	std::vector<EntityBase> ent_arr = { new_dude, new_dude2 };

	new_wrld.assignWorld(wall_arr, ent_arr);

	//new_wall.wallMove(to_pt, Wall::POINT_B, false, 0.32);


	return -1;
}