/*
 * Particle.h
 *
 *  Created on: 19 dic 2019
 *      Author: tropi
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_
#include <stdlib.h>
#include <Math.h>

namespace mySdl {

struct Particle {
	double m_x, m_y;
	double m_speed,m_direction;
public:
	Particle();
	virtual ~Particle();
	void init();
	void update(int interval);
};

} /* namespace mySdl */

#endif /* PARTICLE_H_ */
