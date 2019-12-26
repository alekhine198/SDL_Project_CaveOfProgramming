/*
 * Particle.cpp
 *
 *  Created on: 19 dic 2019
 *      Author: tropi
 */

#include "Particle.h"

namespace mySdl {

Particle::Particle(){
	init();
}

Particle::~Particle() {
}

void Particle::update(int interval){

	m_direction += interval * -0.0004;

	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);
	//double dist = sqrt(pow(m_x,2)+pow(m_y,2));

	m_x+= xspeed * interval;
	m_y+= yspeed * interval;

	/*if(sqrt(pow(m_x,2)+pow(m_y,2))< dist){
			init();
	}*/

	if(m_x<-1||m_x>1||m_y<-1||m_y>1){
		init();
	}
}

void Particle::init(){
	m_x = 0;
	m_y = 0;

	m_speed = (0.04*rand())/RAND_MAX;
	m_direction = (2*M_PI*rand())/RAND_MAX;
	m_speed *= m_speed;
}

} /* namespace mySdl */
