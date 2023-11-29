#include "src/render.hpp"

int main() {
	Entity::EntityBase new_guy;

	new_guy.pos = { 1.0, 3.0 };

	new_guy.moveEntity({ 30.2, -10.3 }, 1.30);
	return -1;
}