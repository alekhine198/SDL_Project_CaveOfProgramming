/*
 * Swarm.cpp
 *
 *  Created on: 19 dic 2019
 *      Author: tropi
 */

#include "Swarm.h"

namespace mySdl {

Swarm::Swarm(): m_pParticle{new Particle[NPARTICLES]}, lastTime{0}{


}

Swarm::~Swarm() {
	delete[] m_pParticle;
}

const mySdl::Particle *  Swarm::getParticles(){
	return m_pParticle;
}

void Swarm::update(int elapsed){

	int interval = elapsed - lastTime;

	for(int i =0; i < NPARTICLES;i++){
		m_pParticle[i].update(interval);
	}

	lastTime = elapsed;
}

} /* namespace mySdl */
