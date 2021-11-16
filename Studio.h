//
// Created by Shay on 10/11/2021.
//

#ifndef SPL_HW1_STUDIO_H
#define SPL_HW1_STUDIO_H
#include <vector>
#include <string>
#include "Workout.h"
#include "Trainer.h"
#include "Action.h"
#include <fstream>


class Studio{
public:
    Studio();
    Studio(const std::string &configFilePath);
    void start();
    int getNumOfTrainers() const;
    Trainer* getTrainer(int tid);
    const std::vector<BaseAction*>& getActionsLog() const; // Return a reference to the history of actions
    std::vector<Workout>& getWorkoutOptions();
    void closeStudio();
    ~Studio();
    Studio(const Studio& other);
    void operator=(const Studio& other);
    BaseAction* buildAction(char* command);
    Customer* buildCustomer(char* command);
private:
    int id;
    bool open;
    std::vector<Trainer*> trainers;
    std::vector<Workout> workout_options;
    std::vector<BaseAction*> actionsLog;
};

#endif //SPL_HW1_STUDIO_H
