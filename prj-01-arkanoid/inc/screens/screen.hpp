
// screen.hpp
#ifndef SCREEN_HPP
#define SCREEN_HPP

class Screen
{
public:
    virtual ~Screen() = default; // Make sure destructor is virtual if using polymorphism.
    virtual void display(int& corent_screen) = 0;

private:
};

#endif // SCREEN_HPP


