#ifndef  GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity
{
private:
    double score;
public:
    GradedActivity(double);

};

GradedActivity::GradedActivity(double s)
{
    score = s;
}

GradedActivity::GradedActivity()
{   
    score = 0.0
}


#endif