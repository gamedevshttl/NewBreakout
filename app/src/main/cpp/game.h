//
// Created by Vladimir on 01.09.2018.
//

#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H

#include <android/asset_manager_jni.h>

#include <memory>
#include <tuple>
#include <array>

#include "resource_manager.h"
#include "sprite_renderer.h"
#include "game_level.h"
#include "ball_object.h"

void on_surface_created();
void on_surface_changed(int width, int height);
void on_update();
void set_data_dir(const char *dir);
void set_asset_manager(AAssetManager* asset_manager);
void on_touch_press(float x, float y, int idx);
void on_touch_drag(float x, float y, int idx);
void on_touch_release(float x, float y, int idx);


enum game_state {
    game_active,
    game_menu,
    game_win
};

enum type_action{
    none,
    left,
    right,
};

enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

typedef std::tuple<GLboolean, Direction, std::array<float,2>> Collision;

// Initial velocity of the player paddle
const GLfloat PLAYER_VELOCITY(500.0f);
// Initial velocity of the Ball
const std::array<float, 2> INITIAL_BALL_VELOCITY{100.0f, -350.0f};
// Radius of the ball object
const GLfloat BALL_RADIUS = 12.5f;

class game
{
public:
    game();
    void init();
    void set_asset_manager(AAssetManager* asset_manager);
    void set_data_dir(std::string current_dir);
    void on_surface_changed(int width, int height);

    void update(GLfloat dt);
    void render();
    void do_collision();
    void reset_level();
    void reset_player();

    void on_touch_press(float x, float y, int idx);
    void on_touch_drag(float x, float y, int idx);
    void on_touch_release(float x, float y, int idx);

    type_action m_action;

    std::shared_ptr<sprite_renderer> m_sprite_renderer;
    std::string m_current_dir;
    AAssetManager* m_asset_manager;

    int m_width, m_height;
    mat4x4 projection;
    std::vector<game_level> m_levels;
    GLuint m_current_level = 0;

    std::shared_ptr<game_object> m_player;
    vec2 m_player_size;
    GLfloat m_player_velocity;

    std::shared_ptr<ball_object> m_ball;
    GLfloat m_ball_radius;
    vec2 m_ball_velocity;
};


#endif //BREAKOUT_GAME_H
