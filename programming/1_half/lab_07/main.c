#include <stdio.h>

enum Week {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Suterday,
    Sunday,
};

struct Rect {
    float length, width;
    float anchor;
};

float square(struct Rect temp_figure) {
    return temp_figure.length * temp_figure.width;
}

struct MP3 {
    unsigned short Play : 1;
    unsigned short Pause : 1;
    unsigned short Record : 1;
};

int main() {
    printf("%d\n", Monday);
    struct Rect temp_rectangle;
    temp_rectangle.length = 3;
    temp_rectangle.width = 4;
    temp_rectangle.anchor = 0;
    printf("%f\n", square(temp_rectangle));
    struct MP3 temp_mp3;
    temp_mp3.Pause = 1;
    temp_mp3.Play = 0;
    temp_mp3.Record = 0;
    printf("%s\n", temp_mp3.Pause ? "On" : "Off");
    printf("%s\n", temp_mp3.Play ? "On" : "Off");
    printf("%s\n", temp_mp3.Record ? "On" : "Off");
    return 0;
}
