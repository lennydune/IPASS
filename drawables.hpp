#include <hwlib.hpp>

class drawable {
protected:
	hwlib::window &w;
	hwlib::xy start;
	hwlib::xy size;

public:
	drawable(hwlib::window &w, const hwlib::xy &start, const hwlib::xy &size):
		w(w),
		start(start),
		size(size)
		{}

	virtual void draw();
	virtual void update();
};

class line : public drawable {
private:
	hwlib::xy end;
public:
	line(hwlib::window &w, const hwlib::xy &start, const hwlib::xy &end):
		drawable(w, start, end-start),
		end(end)
		{}

	void draw() override
}