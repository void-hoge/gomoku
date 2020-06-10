#include "board.hpp"
#include <iostream>
using namespace gomoku;

board::board() {
	cells[white] = 0;
	cells[black] = 0;
	turn = 0;
	current_color = white;
}

bool board::is_filled() const{
	return (cells[white] | cells[black]) == ~(std::bitset<SIZE*SIZE>)0;
}

bool board::is_finished() const {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE-N_MOKU; j++) {
			//horizontal check
			if ((cells[current_color] & (horizontal_mask<<(i*SIZE+j))) == (horizontal_mask<<(i*SIZE+j))) {
				return current_color;
			}
			//vertical check
			if ((cells[current_color] & (vertical_mask<<(j*SIZE+i))) == (horizontal_mask<<(j*SIZE+i))) {
				return true;
			}
		}
	}
	//diagonal check
	for (int i = 0; i < SIZE-N_MOKU; i++) {
		for (int j = 0; j < SIZE-N_MOKU; j++) {
			if ((cells[current_color] & (diagonal_mask1<<(j*SIZE+i))) == (diagonal_mask1<<(j*SIZE+i))) {
				return true;
			}
			if ((cells[current_color] & (diagonal_mask2<<(j*SIZE+i))) == (diagonal_mask2<<(j*SIZE+i))) {
				return true;
			}
		}
	}
	return false;
}

bool board::set(const int idx, const color c) {
	if ((cells[c] & (std::bitset<SIZE*SIZE>)1<<idx) != 0) {
		return false;
	}
	if ((cells[1-c] & (std::bitset<SIZE*SIZE>)1<<idx) != 0) {
		return false;
	}
	cells[c] |= (std::bitset<SIZE*SIZE>)1<<idx;
	return true;
}

bool board::put(const int x, const int y) {
	const int idx = x*SIZE+y;
	if (idx < 0) {
		return false;
	}
	if (idx > SIZE*SIZE) {
		return false;
	}
	if (set(idx, 1-current_color) == false) {
		return false;
	}
	turn++;
	current_color = 1-current_color;
	return true;
}

color board::get_current_color() const{
	return current_color;
}

color board::check(const int idx) const{
	if ((cells[white] & (std::bitset<SIZE*SIZE>)1<<idx) != 0) {
		return white;
	}
	if ((cells[black] & (std::bitset<SIZE*SIZE>)1<<idx) != 0) {
		return black;
	}
	return empty;
}

void board::show() const{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			switch (check(i*SIZE+j)) {
				case white:
					std::cout << " O ";
					break;
				case black:
					std::cout << " X ";
					break;
				default:
					std::cout << " . ";
					break;
			}
		}
		std::cout << '\n' << '\n';
	}
}
