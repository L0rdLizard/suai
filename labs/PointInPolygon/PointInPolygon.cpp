#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include "CLI/CLI11.hpp"

using namespace std;

#define EXEC "PointInPolygon.exe"
#define TITLE "\nPointInPolygon\n"
#define FOOTER \
    "Created with <3 by Dmityi Zykov at SUAI University"

class Settings
{
public:
    string file_in;
	int x = 0;
	int y = 0;
};

struct pt {
	int x, y;
};

struct ang {
	int a, b;
};


bool operator < (const ang & p, const ang & q) {
	if (p.b == 0 && q.b == 0)
		return p.a < q.a;
	return p.a * q.b < p.b * q.a;
}


int sq (pt & a, pt & b, pt & c) {
	return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
}

void readPoints(vector<pt> &p, int n, ifstream &fin) {
	for (int i=0; i<n; ++i) {
		fin >> p[i].x >> p[i].y;
	}
}

int main(int argc, char *argv[]) {
	Settings settings;
	CLI::App app{TITLE};
	app.footer(FOOTER);
	app.add_option("input", settings.file_in, "Input file")->option_text("FILE")->required();
	app.add_option("-x", settings.x, "X coordinate of point")->option_text("POINT_X")->required();
	app.add_option("-y", settings.y, "Y coordinate of point")->option_text("POINT_Y")->required();
	CLI11_PARSE(app, argc, argv);

	if (settings.file_in.empty())
    {
        cout << "No file specified" << endl;
        cout << "Use -h or --help to see usage" << endl;
        return 0;
    }

	ifstream fin(settings.file_in);
	if (!fin.is_open())
	{
		cout << "File " << settings.file_in << " not found" << endl;
		return 0;
	}

	int n;
	fin >> n;
	vector<pt> p (n);
	readPoints(p, n, fin);

	fin.close();

	// int n;
	// ifstream fin("input.txt");
	// fin >> n;
	// vector<pt> p (n);
	// readPoints(p, n, fin);

	int zero_id = 0;
	for (int i=0; i<n; ++i) {
		if (p[i].x < p[zero_id].x || p[i].x == p[zero_id].x && p[i].y < p[zero_id].y)
			zero_id = i;
	}
	pt zero = p[zero_id];
	rotate (p.begin(), p.begin()+zero_id, p.end());
	p.erase (p.begin());
	--n;

	vector<ang> a (n);
	for (int i=0; i<n; ++i) {
		a[i].a = p[i].y - zero.y;
		a[i].b = p[i].x - zero.x;
		if (a[i].a == 0)
			a[i].b = a[i].b < 0 ? -1 : 1;
	}

	for (;;) {
		pt q;
		q.x = settings.x;
		q.y = settings.y;
        // cout << "Enter point coordinates: ";
        // scanf ("%d%d", &q.x, &q.y);
		bool in = false;
		if (q.x >= zero.x)
			if (q.x == zero.x && q.y == zero.y)
				in = true;
			else {
				ang my = { q.y-zero.y, q.x-zero.x };
				if (my.a == 0)
					my.b = my.b < 0 ? -1 : 1;
				vector<ang>::iterator it = upper_bound (a.begin(), a.end(), my);
				if (it == a.end() && my.a == a[n-1].a && my.b == a[n-1].b)
					it = a.end()-1;
				if (it != a.end() && it != a.begin()) {
					int p1 = int (it - a.begin());
					if (sq (p[p1], p[p1-1], q) <= 0)
						in = true;
				}
			}
		puts (in ? "INSIDE" : "OUTSIDE");
        break;
	}

}

