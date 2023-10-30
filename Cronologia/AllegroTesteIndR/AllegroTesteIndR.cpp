//#include <iostream>
#include <stdio.h>
#include <allegro5/allegro.h>

const int SCREEN_W = 960;
const int SCREEN_H = 540;

const float FPS = 100;

//// hearts
//typedef struct Heart {
//    ALLEGRO_COLOR color;
//
//} Heart;
//
//void initHeart(Heart *h) {
//
//}
//
//void drawHeart(Heart h) {
//    al_draw_rectangle()
//}
//
//
//void background() {
//    al_clear_to_color(al_map_rgb(0, 255, 0));
//    //al_draw_filled_rectangle(733, 16, 749, 16, al_map_rgb(255, 0, 0));
//}

int main() {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    
    // Allegro * 
    if (!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    // Screen/Display
    display = al_create_display(SCREEN_W, SCREEN_H);
    if (!display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    // Timer
    timer = al_create_timer(1.0 / FPS);
    if (!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }

    // Events
    event_queue = al_create_event_queue();
    if (!event_queue) {
        fprintf(stderr, "failed to create event_queue!\n");
        al_destroy_display(display);
        return -1;
    }
        
    // Mouse - Installing
    if (!al_install_mouse()) {
        fprintf(stderr, "failed to install mouse!\n");
        return -1;
    }
        
    // Events - line
    al_register_event_source(event_queue, al_get_display_event_source(display)); // x
    al_register_event_source(event_queue, al_get_mouse_event_source()); // mouse
    al_register_event_source(event_queue, al_get_timer_event_source(timer)); // timer

    // Loop
    int playing = 1;

    /* Heart heart;
    initHeart(&heart) */

    // Timer - Starting
    al_start_timer(timer);

    while (playing) {

        al_clear_to_color(al_map_rgb(0, 255, 0));

        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        // Event - type (timer)
        if (ev.type == ALLEGRO_EVENT_TIMER) {

            //background();
           
            //al_flip_display();
           
            if (al_get_timer_count(timer) % (int)FPS == 0) {
                printf("\n%d segundos se passaram...", (int)(al_get_timer_count(timer) / FPS));
            }
        }

        // Event - type (x)
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            playing = 0;
        }

        // Event - type (mouse)
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            printf("\nmouse clicado em: %d, %d", ev.mouse.x, ev.mouse.y);
        }

    }

    // Destroys
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}