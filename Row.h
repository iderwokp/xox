#include <vector>

class Row;
class Row_iterator {
	int pos;
	Row* row;
	//int Rows_size;
	std::vector<Row*>* rows;
public:
	Row_iterator(std::vector<Row*>* r, int p) : rows{ r }, pos{ p } {}
	Row& operator*() {
		return *rows->at(pos);
	}
	Row* operator->() {
		return &(*rows->at(pos));// Er ikke helt sikker på at denne er rett
	}
	Row_iterator& operator++() {
		++pos;
		return *this;
	}
	Row_iterator& operator--() {
		--pos;
		return *this;
	}
	bool operator==(const Row_iterator& other) const { return pos == other.pos; }
	bool operator!=(const Row_iterator& other) const { return !(*this == other); }

};

class Row {
	std::vector<std::pair<int, int>> row_data{};
public:
	void add_data(std::pair<int, int> p) {
		row_data.push_back(p);
	}
	std::pair<int, int> row_coords(int pos) {
		return row_data.at(pos);
	}
	const std::vector<std::pair<int, int>>& data() {
		return row_data;
	}

};
