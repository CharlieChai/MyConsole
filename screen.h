
#ifndef C_PRIMER_SCREEN_H
#define C_PRIMER_SCREEN_H

class Screen {

public:
    typedef  std::string::size_type pos;
    Screen();
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}
    //overload function
    char get() const {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
private:
    mutable std::string access_str;
    pos cursor = 0, height = 0, width = 0;
    std::string contents;
};

inline Screen::Screen() {
    access_str = "default";
    cursor = 1, height = 1, width = 1;
    contents = "charlie";
}
#endif //C_PRIMER_SCREEN_H