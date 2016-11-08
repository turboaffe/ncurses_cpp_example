# ncurses_cpp_example
Example on how to create a menu using ncurses++w

Requirements:
Install ncurses6 with libtool, see here:
http://www.linuxfromscratch.org/lfs/view/development/chapter06/ncurses.html

export CPPFLAGS="-P"

./configure 
--prefix=/usr 
--mandir=/usr/share/man
--with-shared
--without-debug
--without-normal
--enable-pc-files
--enable-widec 
--with-libtool


Compile with:
g++ -o main main.cpp -I. -lncursesw -lncurses++w -lmenuw -lpanelw -std=gnu++14


