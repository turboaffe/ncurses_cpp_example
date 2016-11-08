
#include <cursesm.h>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

#include <cursesapp.h>


using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.


class DasMenu : public NCursesMenu {

public:
	DasMenu(int lines, int cols, int y = 0, int x = 0) : NCursesMenu(lines, cols, y, x) {
		
		// must hide menu, otherwise all menus overlap each
		// other and i dont understand anything.
		// remember that menu inherits panel inherits window,
		// so a menu IS actually a window.
		// fundametally different from C ncurses.
		hide();

	}

    std::vector<NCursesMenuItem*> items;
	void create() { InitMenu(&items[0], true, false); }

};
 

int main() {

    std::vector<NCursesMenuItem*> items;
    std::vector<NCursesMenuItem*> items2;

    items.push_back(new NCursesMenuItem("gaga", "huhu"));
    items.push_back(new NCursesMenuItem());

    items2.push_back(new NCursesMenuItem("gaga", "huhu"));
    items2.push_back(new NCursesMenuItem());

	// one way to create a menu
	NCursesMenu* menu = new NCursesMenu(&items[0], true, true);
  
	// way to create menu by using "abstract class" 
	// NCursesMenuItem 
	DasMenu* menu2 = new DasMenu(50, 50, 10,10);
	menu2->items = items2;
	menu2->create();
	menu2->post();
	menu2->show();
	menu2->refresh();

    menu->post();
    menu->refresh();

    refresh();


    sleep_for(1000ms);

    items.clear();
    menu->unpost();
    items2.clear();
    menu2->unpost();

    try {
        delete menu;
        delete menu2;
    } catch (std::exception& e) {
        cout << "except! " << e.what() << std::endl;
    }

    endwin();

    return 0;

}

