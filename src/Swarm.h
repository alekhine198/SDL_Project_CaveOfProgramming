/*
 * Swarm.h
 *
 *  Created on: 19 dic 2019
 *      Author: tropi
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace mySdl {

class Swarm {
public:
	const static int NPARTICLES =4000;
private:
	Particle *m_pParticle;
	int lastTime;
public:
	Swarm();
	virtual ~Swarm();
	const mySdl::Particle *getParticles();
	void update(int elapsed);
};

} /* namespace mySdl */

#endif /* SWARM_H_ */
