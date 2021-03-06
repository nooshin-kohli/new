#ifndef _QUADRUPED_BALANCER_H_
#define _QUADRUPED_BALANCER_H_

#include<quadruped_balancer.h>
#include<quadruped_base.h>

class QuadrupedBalancer
{
    QuadrupedBase *base;

    Transformation *leg_stances_[4];
    
    Transformation lf_stance_;
    Transformation rf_stance_;
    Transformation lh_stance_;
    Transformation rh_stance_;

    public:
        QuadrupedBalancer(QuadrupedBase &quadruped_base);

        void balance(float target_roll, float target_pitch, float target_yaw, 
                     float target_x, float target_y, float target_z);

        void legGroundIntersection(QuadrupedLeg *leg, Transformation *leg_stance, float target_roll, float target_pitch, 
                                   float target_yaw, float target_x, float target_y, float target_z);

        void ee_base_to_hip(QuadrupedLeg *leg, Transformation *ee);

        Transformation lf_stance();
        Transformation rf_stance();
        Transformation lh_stance();
        Transformation rh_stance();
};

#endif