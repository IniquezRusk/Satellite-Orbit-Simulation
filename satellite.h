/************************ TRICK HEADER ************************/
/* PURPOSE: (Represent the state and initial conditions of a satellite) */

#ifndef SATELLITE_H
#define SATELLITE_H

#include "trick/regula_falsi.h"
#include <math.h>

#define gravity 6.674e-11
#define mass_satellite 100000.0
#define mass_earth 5.9736224e24
#define radius_earth 6378000.0
#define thrust_force 100000.0

class SATELLITE {
public:
    double pos[2];               /* (m) Init position of satellite 1 */
    double pos_tgt[2];           /* (m) Init position of satellite 2 */
    double vel0[2];              /* (m/s) Init velocity of satellite 1 */
    double vel1[2];              /* (m/s) Init velocity of satellite 2 */
    double acc0[2];              /* (m/s^2) xy-acceleration of satellite 1 */
    double acc1[2];              /* (m/s^2) xy-acceleration of satellite 2 */
    double radius0;              /* (m) rad and angle of satellite 1 on Earth's orbit */
    double radius1;              /* (m) rad and angle of satellite 2 on Earth's orbit */
    double theta0;               /* (rad) angle of satellite 1 on Earth's orbit */
    double theta1;               /* (rad) angle of satellite 2 on Earth's orbit */
    double forceGravityVector0[2]; /* (N) Force of gravity on satellite 1 (x,y direction) */
    double forceGravityVector1[2]; /* (N) Force of gravity on satellite 2 (x,y direction) */
    double forceGravity0;        /* (N) Force of gravity on satellite 1 */
    double forceGravity1;        /* (N) Force of gravity on satellite 2 */
    double centripetal_force0[2];/* (N) Centripetal force on satellite 1 */
    double centripetal_force1[2];/* (N) Centripetal force on satellite 2 */
    double total_force0;         /* (N) Total force acting on satellite 1 */
    double total_force1;         /* (N) Total force acting on satellite 2 */
    double time;                 /* (s) Model time */
    double thrust_force_vector0[2]; /* (N) Thrust force acting on satellite 1 (x,y coordinates) */
    double thrust_force_vector1[2]; /* (N) Thrust force acting on satellite 2 (x,y coordinates) */

    int satellite_default_data(SATELLITE*);
    int satellite_init(SATELLITE*);
    int satellite_deriv(SATELLITE*);
    int satellite_integ(SATELLITE*);
};

#endif
