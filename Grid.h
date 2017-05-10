// Grid.cpp : Defines the entry point for the console application.
//
#include "Row.h"
//#include "stdafx.h"

/*
int vec_indx = game_size + (i*game_size) - (i + 1);
k.x = vec_indx % game_size;
k.y = static_cast<int> (vec_indx / game_size);
*/


template<typename T>
class Grid {
	int size_hor, size_vert;
	std::vector<T> vec{};
	std::vector<Row*> row_vec{};

public:
	Grid() :Grid(0) {};
	Grid(int sz) :Grid(sz, sz) {}
	Grid(int h, int v) : size_hor{ h }, size_vert{ v } {
		vec.resize(size_hor*size_vert);
		init_row_vec();
	}
	Grid(const Grid& src);// = default;
	Grid& operator=(const Grid& src);// = default;
	Grid(Grid&& src);// = delete;
	Grid& operator=(Grid&& src) ;//= delete;
	
	int num_rows() const {return size_vert;}
	int num_columns() const {return size_hor;}

	int x_coord(int index) const;
	int y_coord(int index) const;

	int coordToIndx(int x, int y) const;
	T& operator[](int indx) { return vec[indx];}
	const T& operator[](int indx) const { return vec[indx];}
	T& getElement(int x, int y);
	T& getElement(std::pair<int, int>);
	T setElement(int x, int y, T verdi);
	T setElement(std::pair<int, int>, T verdi);
	Row_iterator begin();
	Row_iterator end();
	void fill();
	virtual	~Grid();

private:
	void init_row_vec();
	void copyFrom(const Grid& src);

};

template<typename T>
void Grid<T>::copyFrom(const Grid& src) {
	vec = src.vec;
	size_hor = src.size_hor;
	size_vert = src.size_vert;
}
template<typename T>
Grid<T>::Grid(const Grid& src) {
	std::cout << "GRID::copytor\n";
	//vec.resize(src.vec.size());
	copyFrom(src);
	init_row_vec();
	
}
template<typename T>
Grid<T>& Grid<T>::operator=(const Grid& src) {
	std::cout << "GRID::copyassign\n";
	if(this == &src) return *this;
	vec.clear();
	row_vec.clear();
	copyFrom(src);
	return *this;
}

template<typename T>
Grid<T>::Grid(Grid&& src) {
	std::cout << "GRID::movetor\n";
	copyFrom(src);
	src.vec.clear();
	row_vec = src.row_vec();
	src.row_vec.clear();	
}
template<typename T>
Grid<T>& Grid<T>::operator=(Grid&& src) {
	std::cout << "GRID::moveassign\n";
	if(this == &src) return *this;
	copyFrom(src);
	src.vec.clear();
	row_vec = src.row_vec();
	src.row_vec.clear();	
	return *this;
}
template<typename T>
void Grid<T>::fill() {
	for(T& e: vec) {
		T t;
		e = t;
	}	
		
}

template<typename T>
int Grid<T>::x_coord(int index) const {
	return index % size_hor;
}
template<typename T>
int Grid<T>::y_coord(int index) const {
	return static_cast<int> (index / size_vert);
}
template<typename T>
int Grid<T>::coordToIndx(int x, int y) const {
	return (y*size_hor + x);

}
template<typename T>
T& Grid<T>::getElement(int x, int y) {
	return vec.at(coordToIndx(x, y));
}
template<typename T>
T& Grid<T>::getElement(std::pair<int, int> xy) {
	return getElement(xy.first, xy.second);
}
template<typename T>
T Grid<T>::setElement(int x, int y, T verdi) {
	T temp = vec.at(coordToIndx(x, y));
	vec.at(coordToIndx(x, y)) = verdi;
	return temp;
}
template<typename T>
T Grid<T>::setElement(std::pair<int, int> xy, T verdi) {
	
	return setElement(xy.first, xy.second, verdi);
}
template<typename T>
Row_iterator Grid<T>::begin() {
	if (row_vec.size() == 0) return end();
	return Row_iterator(&row_vec, 0);
}
template<typename T>
Row_iterator Grid<T>::end() {
	return Row_iterator(&row_vec, row_vec.size());
}
template<typename T>
Grid<T>::~Grid() {
	for (auto r : row_vec) delete r;
	//std::cout << "Grid::~Grid()\n";
}
template<typename T>
void Grid<T>::init_row_vec() {
	//Horisontale rekker
	for (int y = 0; y < size_vert; ++y) {
		Row* r = new Row();
		for (int x = 0; x < size_hor; ++x) {
			r->add_data(std::make_pair(x, y));
		}

		row_vec.push_back(r);
	}//for(int y ...
	 //Vertikale rekker
	for (int x = 0; x < size_vert; ++x) {
		Row* r = new Row();
		for (int y = 0; y < size_hor; ++y) {
			r->add_data(std::make_pair(x, y));
		}
		row_vec.push_back(r);
	}//for(int x ...

	if (size_hor == size_vert) { //Dersom kvadratisk Grid
		Row* r1 = new Row();
		Row* r2 = new Row();
		for (int xy = 0; xy < size_hor; ++xy) {
			r1->add_data(std::make_pair(xy, xy));
		}
		row_vec.push_back(r1);
		for (int xy = 0; xy < size_hor; ++xy) {
			r2->add_data(std::make_pair((size_hor - 1) - xy, xy));
		}
		row_vec.push_back(r2);
	}//if
}//init_row_vec()

template <typename T>
std::ostream& operator<<(std::ostream& os, Grid<T> &grid) {
	//for(auto r = std::begin(grid);r<std::begin(grid)+num_rows();r++) {
	for(int y = 0;y<grid.num_rows();++y) {
		os << "|";
		for(int x = 0;x<grid.num_columns();++x) {
			os << grid.getElement(x, y) << "|";
		}//for x
		os << "\n";
	}//for y
	return os;	
		
	
	
}




