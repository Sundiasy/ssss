#include "naobehavior.h"
#include "../rvdraw/rvdraw.h"
#include <cmath>

extern int agentBodyType;

/*
 * Real game beaming.
 * Filling params x y angle
 */
void NaoBehavior::beam( double& beamX, double& beamY, double& beamAngle ) {
    beamX = -HALF_FIELD_X + worldModel->getUNum();
    beamY = 0;
    beamAngle = 0;
}


SkillType NaoBehavior::selectSkill() {
    // My position and angle
    //cout << worldModel->getUNum() << ": " << worldModel->getMyPosition() << ",\t" << worldModel->getMyAngDeg() << "\n";

    // Position of the ball
    //cout << worldModel->getBall() << "\n";

    // Example usage of the roboviz drawing system and RVSender in rvdraw.cc.
    // Agents draw the position of where they think the ball is
    // Also see example in naobahevior.cc for drawing agent position and
    // orientation.

//     worldModel->getRVSender()->clear(); // erases drawings from previous cycle
//     worldModel->getRVSender()->drawPoint("ball", ball.getX() + 1, ball.getY(), 10.0f, RVSender::MAGENTA);
// return SKILL_STAND;

    // ### Demo Behaviors ###

    // Walk in different directions
    //return goToTargetRelative(VecPosition(1,0,0), 0); // Forward
    //return goToTargetRelative(VecPosition(-1,0,0), 0); // Backward
    //return goToTargetRelative(VecPosition(0,1,0), 0); // Left
    //return goToTargetRelative(VecPosition(0,-1,0), 0); // Right
    //return goToTargetRelative(VecPosition(1,1,0), 0); // Diagonal
    //return goToTargetRelative(VecPosition(0,1,0), 90); // Turn counter-clockwise
    //return goToTargetRelative(VecPdosition(0,-1,0), -90); // Turn clockwise
    //return goToTargetRelative(VecPosition(1,0,0), 15); // Circle

    // Walk to the ball
    //return goToTarget(ball);

    // Turn in place to face ball
    /*double distance, angle;
    getTargetDistanceAndAngle(ball, distance, angle);
    if (abs(angle) > 10) {
      return goToTargetRelative(VecPosition(), angle);
    } else {
      return SKILL_STAND;
    }*/

    // Walk to ball while always facing forward
    //return goToTargetRelative(worldModel->g2l(ball), -worldModel->getMyAngDeg());

    // Dribble ball toward opponent's goal
    //return kickBall(KICK_DRIBBLE, VecPosition(HALF_FIELD_X, 0, 0));

    // Kick ball toward opponent's goal
    //return kickBall(KICK_FORWARD, VecPosition(HALF_FIELD_X, 0, 0)); // Basic kick
    //return kickBall(KICK_IK, VecPosition(HALF_FIELD_X, 0, 0)); // IK kick

    // Just stand in place
    //return SKILL_STAND;

    // Demo behavior where players form a rotating circle and kick the ball
    // back and forth

    // // int p [4];

    // // int min;
    // // if(worldModel->getUNum() ==WO_TEAMMATE1 )
    // // {
    // //     if(me.getDistanceTo(VecPosition(0,0))>0.5)
    // //     {
    // //         return goToTarget(VecPosition(-0.5,0,0));

    // //     }
    // // }
    // // if(worldModel->getUNum() ==WO_TEAMMATE2 )
    // // {
    // //     if(me.getDistanceTo(VecPosition(0,0))>0.1)
    // //     {
    // //         return goToTarget(VecPosition(0,1,0));
            
    // //     }
    // // }
    // //   if(worldModel->getUNum() ==WO_TEAMMATE3 )
    // // {
    // //     if(me.getDistanceTo(VecPosition(0,0))>0.1)
    // //     {
    // //         return goToTarget(VecPosition(0,-1,0));
            
    // //     }
    // // }
    // //   if(worldModel->getUNum() ==WO_TEAMMATE4 )
    // // {
    // //     if(me.getDistanceTo(VecPosition(0,0))>0.1)
    // //     {
    // //         return goToTarget(VecPosition(2,0,0));
            
    // //     }
    // // }
    // // if(worldModel->getUNum() ==WO_TEAMMATE4||worldModel->getUNum() ==WO_TEAMMATE3||
    // //     worldModel->getUNum() ==WO_TEAMMATE2||worldModel->getUNum() ==WO_TEAMMATE1)
    // //     {
    // //         p[0] = me.getDistanceTo(VecPosition(-0.5,0,0))  ;
    // //         p[1] = me.getDistanceTo(VecPosition(2,0,0))  ;
    // //         p[2] = me.getDistanceTo(VecPosition(0,1,0))  ;
    // //         p[3] = me.getDistanceTo(VecPosition(0,-1,0))  ;
    // //         for(int i = 0; i< 3;i++)
    // //         {
    // //             if(p [i]<p[i+1])
    // //             {
    // //                 min = p[i];
    // //                 p[i + 1] = p[i];

    // //             }
    // //         }
            
    // //     }
    double k[4][4] = {0};
    double m[4] ;
    double h[4];
    int n[4]{0,0,0,0};
    VecPosition g[4] = {VecPosition(ball + VecPosition(-0.5,0,0)),VecPosition(ball+ VecPosition(0,1,0)),
    VecPosition(ball + VecPosition(0,-1,0)),VecPosition(ball + VecPosition(4,0,0))};
   


    //   if (worldModel->getUNum() == WO_TEAMMATE1)
    // {
     
    //     k[0][0] =me.getDistanceTo(ball + VecPosition(-0.5,0,0));
       
    //     k[0][1] = me.getDistanceTo(ball + VecPosition(0,1,0));
    //     k[0][2] = me.getDistanceTo(ball + VecPosition(0,-1,0));
    //     k[0][3] =me.getDistanceTo( ball + VecPosition(4,0,0));
    //        if(worldModel->isFallen())
    //     {
    //         for(int i = 0;i< 4;i++)
    //         {
    //             k[0][i] ++;

    //         }
    //     }

    // }
    
    
    //   if (worldModel->getUNum() == WO_TEAMMATE2)
    // {
         
    //     k[1][0] =me.getDistanceTo(ball + VecPosition(-0.5,0,0));

    //     k[1][1] = me.getDistanceTo(ball + VecPosition(0,1,0));
    //     k[1][2] = me.getDistanceTo(ball + VecPosition(0,-1,0));
    //     k[1][3] =me.getDistanceTo( ball + VecPosition(4,0,0));
    //     if(worldModel->isFallen())
    //     {
    //         for(int i = 0;i< 4;i++)
    //         {
    //             k[1][i] ++;
                
    //         }
    //     }

    // }
    //  if (worldModel->getUNum() == WO_TEAMMATE3)
    // {
    //      if(worldModel->isFallen())
    //     {
    //         for(int i = 0;i< 4;i++)
    //         {
    //             k[3][i] ++;
                
    //         }
    //     }
    //     k[2][0] =me.getDistanceTo(ball + VecPosition(-0.5,0,0));

    //     k[2][1] = me.getDistanceTo(ball + VecPosition(0,1,0));
    //     k[2][2] = me.getDistanceTo(ball + VecPosition(0,-1,0));
    //     k[2][3] =me.getDistanceTo( ball + VecPosition(4,0,0));
    //        if(worldModel->isFallen())
    //     {
    //         for(int i = 0;i< 4;i++)
    //         {
    //             k[3][i] ++;
                
    //         }
    //     }

    // }
    //  if (worldModel->getUNum() == WO_TEAMMATE4)
    // {
      
    //     k[3][0] =me.getDistanceTo(ball + VecPosition(-0.5,0,0));

    //     k[3][1] = me.getDistanceTo(ball + VecPosition(0,1,0));
    //     k[3][2] = me.getDistanceTo(ball + VecPosition(0,-1,0));
    //     k[3][3] =me.getDistanceTo( ball + VecPosition(4,0,0));
    //        if(worldModel->isFallen())
    //     {
    //         for(int i = 0;i< 4;i++)
    //         {
    //             k[4][i] ++;
                
    //         }
    //     }

    // }
    VecPosition temp[WO_TEAMMATE1+NUM_AGENTS];
    for(int i = WO_TEAMMATE1; i < WO_TEAMMATE1+NUM_AGENTS; ++i) {
        
        int playerNum = i - WO_TEAMMATE1 + 1;
        if (worldModel->getUNum() == playerNum) {
            // Thiss is us
            temp[playerNum-1] = worldModel->getMyPosition();
        } else {
            WorldObject* teammate = worldModel->getWorldObject( i );
            if (teammate->validPosition) {
                temp[i-1] = teammate->pos;
            } else {
                continue;
            }
        }
        // temp.setZ(0);

        // double distanceToBall = temp.getDistanceTo(ball);
        // if (distanceToBall < closestDistanceToBall) {
        //     playerClosestToBall = playerNum;
        //     closestDistanceToBall = distanceToBall;
        // }
    }
    
     for(int j =0;j<4;j++ )
     {
        k[j][0] =pow(temp[j].getX()+(ball + VecPosition(-0.5,0,0)).getX(),2)+pow(temp[j].getY()+(ball + VecPosition(-0.5,0,0)).getY(),2);
       
        k[j][1] =pow(temp[j].getX()+(ball + VecPosition(0,1,0)).getX(),2)+pow(temp[j].getY()+(ball + VecPosition(0,1,0)).getY(),2);
        k[j][2] =pow(temp[j].getX()+(ball + VecPosition(0,-1,0)).getX(),2)+pow(temp[j].getY()+(ball + VecPosition(0,-1,0)).getY(),2);
        k[j][3] =pow(temp[j].getX()+(ball + VecPosition(4,0,0)).getX(),2)+pow(temp[j].getY()+(ball + VecPosition(4,0,0)).getY(),2);
    
        }
           if(worldModel->isFallen())
        {
            for(int i = 0;i< 4;i++)
            {
                k[worldModel->getUNum()-1][i] ++;

            }
        }
  
    
    
    
    //   if (worldModel->getUNum() == WO_TEAMMATE2)
    // {
         
    //     k[1][0] =me.getDistanceTo(ball + VecPosition(-0.5,0,0));

    //     k[1][1] = me.getDistanceTo(ball + VecPosition(0,1,0));
    //     k[1][2] = me.getDistanceTo(ball + VecPosition(0,-1,0));
    //     k[1][3] =me.getDistanceTo( ball + VecPosition(4,0,0));
    //     if(worldModel->isFallen())
    //     {
    //         for(int i = 0;i< 4;i++)
    //         {
    //             k[1][i] ++;
                
    //         }
    //     }

    // }
    //  if (worldModel->getUNum() == WO_TEAMMATE3)
    // {
      
    //     k[2][0] =me.getDistanceTo(ball + VecPosition(-0.5,0,0));

    //     k[2][1] = me.getDistanceTo(ball + VecPosition(0,1,0));
    //     k[2][2] = me.getDistanceTo(ball + VecPosition(0,-1,0));
    //     k[2][3] =me.getDistanceTo( ball + VecPosition(4,0,0));
    //        if(worldModel->isFallen())
    //     {
    //         for(int i = 0;i< 4;i++)
    //         {
    //             k[3][i] ++;
                
    //         }
    //     }

    // }
    //  if (worldModel->getUNum() == WO_TEAMMATE4)
    // {
      
    //     k[3][0] =me.getDistanceTo(ball + VecPosition(-0.5,0,0));

    //     k[3][1] = me.getDistanceTo(ball + VecPosition(0,1,0));
    //     k[3][2] = me.getDistanceTo(ball + VecPosition(0,-1,0));
    //     k[3][3] =me.getDistanceTo( ball + VecPosition(4,0,0));
    //        if(worldModel->isFallen())
    //     {
    //         for(int i = 0;i< 4;i++)
    //         {
    //             k[4][i] ++;
                
    //         }
    //     }

    // }
    for(int i = 0; i< 4;i++)
    {
        h[i]= k[0][i];
    }
    for(int i = 0;i < 4;i++)
    {
        for(int j =0;j<3;j++)
        {
           
            if(h[i]>k[j+1][i])
            {
                h[i] = k[j+1][i];
                n[i] = j+1;
            }
            else if(h[i]==k[j+1][i])
            {
                if(h[i+1]>k[j+1][i+1])
                {
                    h[i] = k[j+1][i];
                    n[i] = j+1;
                }
                else if(h[i+1]==k[j+1][i+1])
                {
                    if(h[i+2]>k[j+1][i+2])
                    {
                        h[i] = k[j+1][i];
                        n[i] = j+1;
                    }
                }
            }
  
        }
        for(int l = 0;l<4;l++)
        {
            k[n[i]-1][l] = INT_MAX;
        }

    }
    //cout << worldModel->getUNum() << " " << n[0] << n[1] << n[2] << n[3] << endl;
    
    if(worldModel->getUNum() ==WO_TEAMMATE1 )
    {
        for(int i = 0;i<4;i++)
        {
            if(n[i] +1 == 1)
            {
                return goToTarget(collisionAvoidance(1 /*teammate*/, 0/*opponent*/,1/*ball*/, 1/*proximity thresh*/, .5/*collision thresh*/, g[i], true/*keepDistance*/));
            }
        }
    }
    else if(worldModel->getUNum() ==WO_TEAMMATE2 )
    {
        for(int i = 0;i<4;i++)
        {
            if(n[i] +1 == 2)
            {
                return goToTarget(collisionAvoidance(1 /*teammate*/, 0/*opponent*/,1/*ball*/, 1/*proximity thresh*/, .5/*collision thresh*/, g[i], true/*keepDistance*/));
            }
        }
    }
    else if(worldModel->getUNum() ==WO_TEAMMATE3 )
    {
        for(int i = 0;i<4;i++)
        {
            if(n[i] +1 == 3)
            {
                return goToTarget(collisionAvoidance(1 /*teammate*/, 0/*opponent*/,1/*ball*/, 1/*proximity thresh*/, .5/*collision thresh*/, g[i], true/*keepDistance*/));
            }
        }
    }
    else if(worldModel->getUNum() ==WO_TEAMMATE4 )
    {
        for(int i = 0;i<4;i++)
        {
            if(n[i] +1 == 4)
            {
                return goToTarget(collisionAvoidance(1 /*teammate*/, 0/*opponent*/,1/*ball*/, 1/*proximity thresh*/, .5/*collision thresh*/, g[i], true/*keepDistance*/));
            }
        }
    }
}
/*
 * Demo behavior where players form a rotating circle and kick the ball
 * back and forth
 */
SkillType NaoBehavior::demoKickingCircle() {
    // Parameters for circle
    VecPosition center = VecPosition(-HALF_FIELD_X/2.0, 0, 0);
    double circleRadius = 5.0;
    double rotateRate = 2.5;

    worldModel->getRVSender()->clearStaticDrawings();
    worldModel->getRVSender()->drawPoint(0,0,10,RVSender::BLUE);

    // Find closest player to ball
    int playerClosestToBall = -1;
    double closestDistanceToBall = 10000;
    for(int i = WO_TEAMMATE1; i < WO_TEAMMATE1+NUM_AGENTS; ++i) {
        VecPosition temp;
        int playerNum = i - WO_TEAMMATE1 + 1;
        if (worldModel->getUNum() == playerNum) {
            // This is us
            temp = worldModel->getMyPosition();
        } else {
            WorldObject* teammate = worldModel->getWorldObject( i );
            if (teammate->validPosition) {
                temp = teammate->pos;
            } else {
                continue;
            }
        }
        temp.setZ(0);

        double distanceToBall = temp.getDistanceTo(ball);
        if (distanceToBall < closestDistanceToBall) {
            playerClosestToBall = playerNum;
            closestDistanceToBall = distanceToBall;
        }
    }

    if (playerClosestToBall == worldModel->getUNum()) {
        // Have closest player kick the ball toward the center
        return kickBall(KICK_FORWARD, center);
    } else {
        // Move to circle position around center and face the center
        VecPosition localCenter = worldModel->g2l(center);
        SIM::AngDeg localCenterAngle = atan2Deg(localCenter.getY(), localCenter.getX());

        // Our desired target position on the circle
        // Compute target based on uniform number, rotate rate, and time
        VecPosition target = center + VecPosition(circleRadius,0,0).rotateAboutZ(360.0/(NUM_AGENTS-1)*(worldModel->getUNum()-(worldModel->getUNum() > playerClosestToBall ? 1 : 0)) + worldModel->getTime()*rotateRate);

        // Adjust target to not be too close to teammates or the ball
        target = collisionAvoidance(true /*teammate*/, false/*opponent*/, true/*ball*/, 1/*proximity thresh*/, .5/*collision thresh*/, target, true/*keepDistance*/);

        if (me.getDistanceTo(target) < .25 && abs(localCenterAngle) <= 10) {
            // Close enough to desired position and orientation so just stand
            return SKILL_STAND;
        } else if (me.getDistanceTo(target) < .5) {
            // Close to desired position so start turning to face center
            return goToTargetRelative(worldModel->g2l(target), localCenterAngle);
        } else {
            // Move toward target location
            return goToTarget(target);
        }
    }
}


