#include "JackState.h"

namespace axe
{
	const double PI = ALLEGRO_PI;
	const double HALF_PI = PI / 2.f;
	const double TWO_PI = PI * 2.f;
}

JackState::JackState(axe::StateManager &states, axe::InputHandler &input, axe::EventHandler &events, axe::DrawEngine &draw)
	: axe::AbstractState(states, input, events, draw),
	jack_position(200, 200), velocity(0),
	jack_direction(1, 0)
{
	ejack_body = al_load_bitmap("ejack_body.png");
	ejack_handle = al_load_bitmap("ejack_handle.png");
	
	t.start();
}

JackState::~JackState()
{
	al_destroy_bitmap(ejack_body);
	al_destroy_bitmap(ejack_handle);
}

void JackState::update()
{
	steering_angle += axe::PI / 200.f;
	if (steering_angle >= axe::HALF_PI) steering_angle = -axe::HALF_PI;
}

void JackState::handleEvents()
{

}

void JackState::draw()
{
	double force = 50.f;
	double jack_length = 1.5f; // Meters
	double mass = 450; //Kilograms

	axe::m_secs cur_time = t.elapsed();
	double delta_time = (cur_time - prev_time).count() / 1000.f;
	prev_time = cur_time;

	//Calculate point of rotation in local space where the jacks vector is just the x axis at jack_length.
	vec2 jack_point(jack_length, 0.f);
	vec2 rotation_point(0.f, tan(axe::HALF_PI - steering_angle) * jack_length);

	double radius = (jack_point - rotation_point).length();
	double inertia = mass * radius * radius;
	double torque = force * radius * sin(steering_angle);
	double accel = torque / inertia;

	velocity = velocity + (accel * delta_time); // radians per second

	al_draw_filled_circle(jack_position.x, jack_position.y, 2, al_map_rgb(255, 0, 0));
	al_draw_filled_circle(jack_position.x + (jack_point.x * 50), jack_position.y + (jack_point.y * 50), 2, al_map_rgb(255, 0, 0));
	al_draw_filled_circle(jack_position.x + (rotation_point.x * 50), jack_position.y + (rotation_point.y * 50), 2, al_map_rgb(0, 0, 255));
	al_draw_filled_circle(jack_position.x + (jack_point.x * 50) + (10.f * cos(steering_angle)), jack_position.y + (jack_point.y * 50) + (10.f * sin(steering_angle)), 2, al_map_rgb(255, 0, 0));

	//vector2f end = jack_position + (jack_direction * (jack_length * 50));

	//al_draw_line(jack_position.x, jack_position.y, end.x, end.y, al_map_rgb(255, 0, 0), 1);
	//al_draw_line(jack_position.x, jack_position.y, jack_position.x + rotation_point.x, jack_position.y + rotation_point.y, al_map_rgb(255, 0, 0), 1);
}

void JackState::pause()
{

}

void JackState::resume()
{

}