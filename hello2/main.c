#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

Display* display;
int screen_num; // screen identifier
char *display_name = NULL; // if null, the value of the DISPLAY environment variable is used
Screen* screen;

int main(int argc, char** argv) {
    // just unsigned long (Window ID)
    int x = 0, y = 0;
    char* window_name = "Hello, World!";
    XSizeHints size_hints;
    XEvent report;
    GC gc;
    XFontStruct* font_info;

    display = XOpenDisplay(display_name);
    if (display == NULL) {
        fprintf(stderr, "Cannot connect to X server %s\n", XDisplayName(display_name));
        return 1;
    }

    screen_num = DefaultScreen(display);
    screen = DefaultScreenOfDisplay(display);

    unsigned int display_width = DisplayWidth(display, screen_num);
    unsigned int display_height = DisplayHeight(display, screen_num);

    unsigned int width = display_width / 3;
    unsigned int height = display_height / 3;
    unsigned int border_width = 2;

    Window window = XCreateSimpleWindow(
        display,
        RootWindow(display, screen_num),
        x,
        y,
        width,
        height,
        border_width,
        BlackPixel(display, screen_num),
        WhitePixel(display, screen_num)
    );

    return 0;
}