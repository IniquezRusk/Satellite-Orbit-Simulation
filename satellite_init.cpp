/************************ TRICK HEADER ************************/
/* PURPOSE: (Set the initial data values) */

#include "../include/satellite.h"
#include <math.h>
#include <iostream>
#include <trick/integrator_c_intf.h>

int SATELLITE::satellite_default_data( SATELLITE* ) {
    pos[0] = 0.0;
    pos[1] = 6578000.0;
    pos_tgt[0] = 0.0;
    pos_tgt[1] = 6878000.0;

    vel0[0] = 7784.40;
    vel0[1] = 0.0;
    vel1[0] = 7784.40;
    vel1[1] = 0.0;

    time = 0.0;
    theta0 = 0.0;
    theta1 = 0.0;

    return 0;
}

/* Initialization job */
int SATELLITE::satellite_init( SATELLITE* ) {
    radius0 = sqrt((pos[0]*pos[0]) + (pos[1]*pos[1]));
    radius1 = sqrt((pos_tgt[0]*pos_tgt[0]) + (pos_tgt[1]*pos_tgt[1]));
    theta0 = atan2(pos[0], pos[1]);
    theta1 = atan2(pos_tgt[0], pos_tgt[1]);

    acc0[0] = 2/100000.0; // change this
    acc0[1] = 2/100000.0; // change this
    acc1[0] = 2/100000.0; // change this
    acc1[1] = 2/100000.0; // change this

    forceGravityVector0[0] = (pos[0]*gravity*mass_earth*100000.0)/(radius0*radius0*radius0);
    forceGravityVector0[1] = (pos[1]*gravity*mass_earth*100000.0)/(radius0*radius0*radius0);
    forceGravityVector1[0] = (pos_tgt[0]*gravity*mass_earth*100000.0)/(radius1*radius1*radius1);
    forceGravityVector1[1] = (pos_tgt[1]*gravity*mass_earth*100000.0)/(radius1*radius1*radius1);

    forceGravity0 = gravity*mass_earth*100000.0/(radius0*radius0);
    forceGravity1 = gravity*mass_earth*100000.0/(radius1*radius1);

    centripetal_force0[0] = 100000.0*acc0[0];
    centripetal_force0[1] = 100000.0*acc0[1];
    centripetal_force1[0] = 100000.0*acc1[0];
    centripetal_force1[1] = 100000.0*acc1[1];

    total_force0 = centripetal_force0 - forceGravityVector0;
    total_force1 = centripetal_force1 - forceGravityVector1;

    return 0;
}

int SATELLITE::satellite_deriv( SATELLITE* ) {
    /* thrusters, centripetal force will affect acceleration, adjust code accordingly
       (add up forces, divide by mass, get acceleration) */
    acc0[0] = 2/100000.0; // change this
    acc0[1] = 2/100000.0; // change this
    acc1[0] = 2/100000.0; // change this
    acc1[1] = 2/100000.0; // change this

    forceGravityVector0[0] = 0.0;
    return 0;
}

int SATELLITE::satellite_integ( SATELLITE* ) {
    // multiply rate times time
    int ipass;

    load_state(
        &pos[0],
        &pos[1],
        &vel0[0],
        &vel0[1],
        &pos_tgt[0],
        &pos_tgt[1],
        &vel1[0],
        &vel1[1],
        NULL
    );

    load_deriv(
        &vel0[0],
        &vel0[1],
        &acc0[0],
        &acc0[1],
        &vel1[0],
        &vel1[1],
        &acc1[0],
        &acc1[1],
        NULL
    );

    ipass = integrate();

    unload_state(
        &pos[0],
        &pos[1],
        &vel0[0],
        &vel0[1],
        &pos_tgt[0],
        &pos_tgt[1],
        &vel1[0],
        &vel1[1],
        NULL
    );

    return(ipass);
}
