#include <iostream>
#include "board.hpp"

int main() {
	board bd;
	bd.show();
	while (bd.is_finished() == false) {
		int x, y;
		std::cin >> x >> y;
		while (bd.put(x, y) == false) {
			std::cin >> x >> y;
		}
		bd.show();
	}
}
