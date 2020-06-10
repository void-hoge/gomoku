#ifndef BOARD_HPP
#define BOARD_HPP

#include <bitset>
#include <array>

namespace gomoku {
const int SIZE = 19;
const int N_MOKU = 5;

using color = int;
const color white = 0;
const color black = 1;
const color empty = -1;

inline std::bitset<SIZE*SIZE> get_horizontal_mask() {
	std::bitset<SIZE*SIZE> res = 0;
	for (int i = 0; i < N_MOKU; i++) {
		res <<= 1;
		res |= 1;
	}
	return res;
}

inline std::bitset<SIZE*SIZE> get_vertical_mask() {
	std::bitset<SIZE*SIZE> res = 0;
	for (int i = 0; i < N_MOKU; i++) {
		res <<= SIZE;
		res |= 1;
	}
	return res;
}

inline std::bitset<SIZE*SIZE> get_diagonal_mask1() {
	std::bitset<SIZE*SIZE> res = 0;
	for (int i = 0; i < N_MOKU; i++) {
		res <<= SIZE+1;
		res |= 1;
	}
	return res;
}

inline std::bitset<SIZE*SIZE> get_diagonal_mask2() {
	std::bitset<SIZE*SIZE> res = 0;
	for (int i = 0; i < N_MOKU; i++) {
		res <<= SIZE;
		res |= (1<<i);
	}
	return res;
}

const auto horizontal_mask = get_horizontal_mask();
const auto vertical_mask = get_vertical_mask();
const auto diagonal_mask1 = get_diagonal_mask1();
const auto diagonal_mask2 = get_diagonal_mask2();

}//namespace gomoku

class board {
private:
	std::array<std::bitset<gomoku::SIZE*gomoku::SIZE>, 2> cells;
	int turn;
	gomoku::color current_color;	//直前に打った手の色
public:
	board ();
	gomoku::color get_current_color() const;
	bool is_filled() const;
	bool is_finished() const;
	void show() const;
	bool set(const int idx, const gomoku::color c);
	bool put(const int x, const int y);
	gomoku::color check(const int idx) const;
};

#endif
